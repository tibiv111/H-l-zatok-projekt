#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <winsock2.h>
#include <algorithm>
#include <QMessageBox>
#include <string.h>
#include <QScrollBar>
#include <QVector>
#include <QColorDialog>


/*
 *
 * protokoll:  INT: meret, tipus(connect, disconnect, messageAll, messagePrivate), kinek, kitol
 *
*/




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //MyTextEdit* newTextEdit = new MyTextEdit(ui->sendToEveryoneButton);

    bool isConnected = connectToServer();
    //bool getListOfConnected = getConnectedUsers();

    if(isConnected == false)
    {
        exit(-1);
    }else
    {
        ui->sendToEveryoneButton->setEnabled(true);

        //ui->serverConnectBtn->setEnabled(false);
    }
    if(getConnectedUsers())
    {
        QMessageBox messageBox;
        messageBox.information(0,"Hurray","Got connected users");
        messageBox.setFixedSize(500,200);
    }
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","User list unavaiable");
        messageBox.setFixedSize(500,200);
        exit(-1);
    }
    ui->username->setStyleSheet("background-color : rgba(255, 0, 0, 0%); color : black;");
    //QColor color = QColorDialog::getColor(Qt::black,this);
    //ui->username->setTextColor(color);
    //QString nr = this->TCP_Server_Kliens_Socket;
    //ui->username->setText("User" + nr);
    qDebug() << "Ez a QT SOCKET : " << TCP_Kliens_Socket << "\n";
    qDebug() << "Ez a Szerver altal visszakuldott SOCKET : " << TCP_Server_Kliens_Socket << "\n";
}


void MainWindow::buildProtocol(int type, int from, int to, char* message)
{
    //memset(Puffer, '\0', PufferHossz);
    //Puffer = (char*)std::realloc(Puffer, PufferHossz * sizeof(char));

    Puffer = (char*)realloc(Puffer, PufferHossz*sizeof(char));
    protocol currentProtocol;
    //char* message2 = message.c_str();


    std::string s2 = std::to_string(type)+'~';

    currentProtocol.type =  s2.c_str();

    std::string s3 = std::to_string(from)+ '~';
    currentProtocol.from =  s3.c_str();

    std::string s4 = std::to_string(to)+ '~';
    currentProtocol.to =  s4.c_str();


    std::string s5 = std::string(message) + '~';
    char const* message2 =  s4.c_str();
    strcat(message, "~");

    int length = strlen(currentProtocol.type)+strlen(currentProtocol.from) + strlen(currentProtocol.to) + strlen(message);
    std::string s_length = std::to_string(length);
    int lengthfull = s_length.length() + length + 1;
    std::string s = std::to_string(lengthfull)+'~';
    currentProtocol.length = s.c_str();



    //qDebug() <<length << type << from << to << message;
    /*
    std::copy(currentProtocol.length, currentProtocol.length+sizeof(int), Puffer);
    std::copy(currentProtocol.type, currentProtocol.type+sizeof(int), Puffer + sizeof(int));
    std::copy(currentProtocol.from, currentProtocol.from+sizeof(int), Puffer + 2*sizeof(int));
    std::copy(currentProtocol.to, currentProtocol.to+sizeof(int), Puffer + 3*sizeof(int));
    std::copy(message2, message2+strlen(message2), Puffer + 4*sizeof(int));
    */


    std::memcpy(Puffer, currentProtocol.length, sizeof(int)); //Beallitom a puffer meretet a headerrel egyutt

    std::memcpy(Puffer+strlen(currentProtocol.length), currentProtocol.type, sizeof(int));

    std::memcpy(Puffer+strlen(currentProtocol.length)+strlen(currentProtocol.type), currentProtocol.from, sizeof(int));

    std::memcpy(Puffer+strlen(currentProtocol.length)+strlen(currentProtocol.type)+strlen(currentProtocol.from), currentProtocol.to, sizeof(int));

    std::memcpy(Puffer+strlen(currentProtocol.length)+strlen(currentProtocol.type)+strlen(currentProtocol.from) + strlen(currentProtocol.to), message, strlen(message));

    Puffer[lengthfull] = '\0';



}

bool MainWindow::getConnectedUsers()
{

    char msg[] = "getUsers()";

    buildProtocol(0, TCP_Kliens_Socket, TCP_Kliens_Socket, msg);
    int send_valasz = send(TCP_Kliens_Socket, Puffer, strlen(Puffer), 0);

    if (send_valasz == SOCKET_ERROR)
    {//hiba lepett fel a send soran!
        //cout << "Hiba lepett fel a send soran!\n";
        QMessageBox messageBox;
        messageBox.critical(0,"Error","An error has occured at sending !");
        messageBox.setFixedSize(500,200);
        closesocket(TCP_Kliens_Socket);

        WSACleanup(); //felszabaditom a WSAStartupot

        return false; //kilepek a programbol
    }

    while (send_valasz != strlen(Puffer)) {
        //nem tudtuk elkuldeni a teljes csomagot => megprobalom ujra elkuldeni a csomag azon reszet,amit nem sikerult elkuldeni

        send_valasz = send(TCP_Kliens_Socket, Puffer + send_valasz, strlen(Puffer) - send_valasz, 0);

    }


    //ui->messagesBox->clear();


    //6.lepes: Recv megirasa / visszakapni a valaszt a szervertol


    //cout << "A visszateritett adat: " << Puffer << "\n\n";
    messageThread->wait();






    return true;
}

void MainWindow::ThreadObserver()
{
    messageThread = new MessagesReceiver(this->TCP_Kliens_Socket, this->TCP_Server_Kliens_Socket, ui->messagesBox, ui->currentlyOnlineListWidget, ui->username);
    connect(messageThread, SIGNAL(refreshWindow(QString, QVector<QString>, QString)),SLOT(on_refreshWindow(QString, QVector<QString>, QString)));

    messageThread->start();
}








bool MainWindow::connectToServer()
{
    //1.lepes: WSAStartup elinditasa -> .dll konyvtarak beolvasasa
        WSADATA wsaData;
        int  WSAStartup_ertek = WSAStartup(MAKEWORD(2, 2), &wsaData);

        if (WSAStartup_ertek != NO_ERROR) {
            //hiba lepett fel a WSAStartup soran
            //cout << "Hiba lepett fel a WSAStartup soran!\n";
            QMessageBox messageBox;
            messageBox.critical(0,"Error","An error has occured during WSAStartup !");
            messageBox.setFixedSize(500,200);

            return false;
        }

        //2.Lepes: Létrehozok egy SOCKET-et amelyik a szerverhez kapcsolódik
        TCP_Kliens_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        if (TCP_Kliens_Socket == INVALID_SOCKET) {
            //hogyha hibas a socket,akkor hibauzenetet irok ki
            //felszabaditom a WSAStartup-ot (cleanelem),majd kilepek a programbol

            //cout << "Hiba lepett fel a TCP Kliens SOCKET-jenek a letrehozasa soran!\n";
            QMessageBox messageBox;
            messageBox.critical(0,"Error","An error has occured while creating socket !");
            messageBox.setFixedSize(500,200);

            WSACleanup();

            return false;
        }

        //3.lepes: A Szerver SOCKADDR letrehozasa es az adatok feltoltese,ezekkel az adatokkal tudok majd a szerverhez csatlakozni!
        int Port = 13000;
        char IP_cim[] = "127.0.0.1";

        sockaddr_in SockAddr_in;
        SockAddr_in.sin_family = AF_INET; //megadtam a Ping csaladot(cimet) protokolt a szervernek
        SockAddr_in.sin_addr.s_addr = inet_addr(IP_cim); //megadtam a szerver IP cimjet
        SockAddr_in.sin_port = htons(Port); //megadtam a szervehez kapcsolodo portot
        int SockAddr_hossz = sizeof(SockAddr_in); //lementem a SockAddr hosszat

        //4.Lepes: A connect megvalositasa, vagyis a kapcsolat felepitese

        int connect_valasz = ::connect(TCP_Kliens_Socket, (SOCKADDR*)&SockAddr_in, SockAddr_hossz);

        if (connect_valasz == SOCKET_ERROR) {
            //hiba lepett fel a kapcsolat felepitese soran

            //cout << "Hiba lepett fel a kapcsolat felepitese soran(connect)!\n"; //hibauzenetet irok ki
            QMessageBox messageBox;
            messageBox.critical(0,"Error","An error has occured while connecting !");
            messageBox.setFixedSize(500,200);
            closesocket(TCP_Kliens_Socket); //lezarom a socketet

            WSACleanup(); //felszabaditom a WSAStartupot

            return false; //kilepek a programbol
        }


        //5.Lepes: Send utasitas megirasa / adatkuldes
        //char Puffer[1024];
        //int PufferHossz = 1024;

        std::string tmp = std::to_string(connect_valasz);
        char const *num_char = tmp.c_str();

        QMessageBox messageBox;
        messageBox.information(0,"Status", "Connection Success!");
        messageBox.setFixedSize(500,200);
        ThreadObserver();
        return true;
}






MainWindow::~MainWindow()
{
    delete ui;
}







void MainWindow::on_sendToEveryoneButton_clicked()
{
    //ui->messageTextEdit = newTextEdit;
    if(ui->messageTextEdit->toPlainText().isEmpty())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Empty message!");
        messageBox.setFixedSize(500,200);
        return;
    }else
    {
        //char Puffer[1024];
        //int PufferHossz = 1024;
        memset(Puffer, '\0', PufferHossz);
        QByteArray ba = ui->messageTextEdit->toPlainText().toLocal8Bit();
        char *message = ba.data();

        if(ui->messageTextEdit->toPlainText().length() > PufferHossz)
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Length of message is longer than the size of Buffer !");
            messageBox.setFixedSize(500,200);
            return;
        }
        buildProtocol(1, this->TCP_Server_Kliens_Socket.toUInt(), 0, message);
        //memcpy(Puffer, message, strlen(message));
        /*
        if (strcmp(Puffer, "exit") == 0 || strcmp(Puffer, "exit\n") == 0) {
            return;
        }'
        */
        int send_valasz = send(TCP_Kliens_Socket, Puffer, strlen(Puffer), 0);
        if (send_valasz == SOCKET_ERROR)
        {//hiba lepett fel a send soran!
            //cout << "Hiba lepett fel a send soran!\n";
            QMessageBox messageBox;
            messageBox.critical(0,"Error","An error has occured at sending !");
            messageBox.setFixedSize(500,200);
            closesocket(TCP_Kliens_Socket);

            WSACleanup(); //felszabaditom a WSAStartupot

            return; //kilepek a programbol
        }
        ui->messageTextEdit->clear();

        while (send_valasz != strlen(Puffer)) {
            //nem tudtuk elkuldeni a teljes csomagot => megprobalom ujra elkuldeni a csomag azon reszet,amit nem sikerult elkuldeni

            send_valasz = send(TCP_Kliens_Socket, Puffer + send_valasz, strlen(Puffer) - send_valasz, 0);

        }


        //ui->messagesBox->clear();


        //6.lepes: Recv megirasa / visszakapni a valaszt a szervertol


        //cout << "A visszateritett adat: " << Puffer << "\n\n";
        messageThread->wait();
    }


}

void MainWindow::exitApp()
{
    MainWindow::close();
}



void MainWindow::on_MainWindow_destroyed()
{
    shutdown(TCP_Kliens_Socket, 2); //felbontom a kapcsolatot

    closesocket(TCP_Kliens_Socket);
    if(messageThread->isRunning())
    {
        messageThread->terminate();
    }
    WSACleanup(); //felszabaditom a WSAStartupot
}

void MainWindow::on_sendMessageOnEnter(QPushButton* button)
{
    button->animateClick();
}

void MainWindow::on_refreshWindow(QString message, QVector<QString> onlinePeople, QString username)
{
    if(onlinePeople.size() != 0)
    {
        ui->currentlyOnlineListWidget->addItems(onlinePeople);
    }
    if(ui->username->toPlainText().isEmpty())
    {
        ui->username->setText("User"+username);
        TCP_Server_Kliens_Socket = username;
    }

    ui->messagesBox->setText(message);
    ui->messagesBox->verticalScrollBar()->setValue(ui->messagesBox->verticalScrollBar()->maximum());
    //a megfigyelot ujra kell inditani
    ThreadObserver();
}


/*
void MainWindow::on_serverConnectBtn_clicked()
{
    bool isConnected = connectToServer();
    if(isConnected == false)
    {
        return;
    }else
    {
        ui->sendToEveryoneButton->setEnabled(true);
        ui->serverConnectBtn->setEnabled(false);

    }
}
*/

void MainWindow::on_exitButton_clicked()
{
    QObject::connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exitApp()));
}



void MainWindow::on_sendPMButton_clicked()
{
    //ui->messageTextEdit = newTextEdit;
    if(ui->messageTextEdit->toPlainText().isEmpty())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Empty message!");
        messageBox.setFixedSize(500,200);
        return;
    }else
    {

        //char Puffer[1024];
        //int PufferHossz = 1024;
        memset(Puffer, '\0', PufferHossz);
        QByteArray ba = ui->messageTextEdit->toPlainText().toLocal8Bit();
        char *message = ba.data();

        if(ui->messageTextEdit->toPlainText().length() > PufferHossz)
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Length of message is longer than the size of Buffer !");
            messageBox.setFixedSize(500,200);
            return;
        }
        buildProtocol(2, this->TCP_Server_Kliens_Socket.toUInt(), ui->currentlyOnlineListWidget->selectedItems()[0]->text().toUInt(), message);
        qDebug() << Puffer;
        //memcpy(Puffer, message, strlen(message));
        /*
        if (strcmp(Puffer, "exit") == 0 || strcmp(Puffer, "exit\n") == 0) {
            return;
        }'
        */
        int send_valasz = send(TCP_Kliens_Socket, Puffer, strlen(Puffer), 0);
        if (send_valasz == SOCKET_ERROR)
        {//hiba lepett fel a send soran!
            //cout << "Hiba lepett fel a send soran!\n";
            QMessageBox messageBox;
            messageBox.critical(0,"Error","An error has occured at sending !");
            messageBox.setFixedSize(500,200);
            closesocket(TCP_Kliens_Socket);

            WSACleanup(); //felszabaditom a WSAStartupot

            return; //kilepek a programbol
        }
        ui->messageTextEdit->clear();


        while (send_valasz != strlen(Puffer)) {
            //nem tudtuk elkuldeni a teljes csomagot => megprobalom ujra elkuldeni a csomag azon reszet,amit nem sikerult elkuldeni

            send_valasz = send(TCP_Kliens_Socket, Puffer + send_valasz, strlen(Puffer) - send_valasz, 0);

        }



        //ui->messagesBox->clear();


        //6.lepes: Recv megirasa / visszakapni a valaszt a szervertol


        //cout << "A visszateritett adat: " << Puffer << "\n\n";
        messageThread->wait();
    }
}

void MainWindow::on_currentlyOnlineListWidget_itemClicked(QListWidgetItem *item)
{
    pmPerson.text() = item->text();
}

void MainWindow::on_currentlyOnlineListWidget_itemSelectionChanged()
{

    if(ui->currentlyOnlineListWidget->selectedItems().isEmpty())
    {
        ui->sendPMButton->setEnabled(false);
    }
    else
    {

        ui->sendPMButton->setEnabled(true);

    }
}
