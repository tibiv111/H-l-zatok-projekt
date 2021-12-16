#include "messagesreceiver.h"
#include <winsock2.h>
#include <QMessageBox>

//A hatterszal frissitest kuld a threadnek hogy lehet frissiteni a windowt


MessagesReceiver::MessagesReceiver(SOCKET TCP_Kliens_Socket, QString TCP_Server_Kliens_Socket, QTextEdit *messageWindow, QListWidget *currentlyOnlineListWidget, QTextEdit * username)
{
    this->TCP_Kliens_Socket = TCP_Kliens_Socket;
    this->TCP_Server_Kliens_Socket = TCP_Server_Kliens_Socket;
    this->messageWindow = messageWindow;
    this->currentlyOnlineListWidget = currentlyOnlineListWidget;
    this->username = username;
}

void MessagesReceiver::parseHeader()
{
    /*
   if(Puffer[strlen(Puffer)-1] == '~')
   {
       Puffer[strlen(Puffer)-1] = '\0';
   }
   */

    QString puf = Puffer;
    header = puf.split("~");

   //tokenize(Puffer,'~',header);

}

void MessagesReceiver::tokenize(std::string const& str, const char delim,
    QVector<QString>& out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(QString::fromStdString(str.substr(start, end - start)));
    }

}

void MessagesReceiver::run()
{
    int recv_valasz = recv(TCP_Kliens_Socket, Puffer, PufferHossz, 0);
    qDebug() << Puffer;

    //parseHeader();
    //Puffer[header[0].toInt()] = '\0';
    //header[header.size()-1] = Regex.Replace(s, @"[^\u0000-\u007F]+", QString.Empty);
    parseHeader();
    qDebug() << header;
     //qDebug() << TCP_Kliens_Socket;
    //qDebug() << header;
    QString allMessages;




    if (recv_valasz == SOCKET_ERROR) {
        //cout << "Hiba lepett fel a recv soran!\n";
        QMessageBox messageBox;
        messageBox.critical(0,"Error","An error has occured at recv !");
        messageBox.setFixedSize(500,200);

        closesocket(TCP_Kliens_Socket);

        WSACleanup(); //felszabaditom a WSAStartupot

        return; //kilepek a programbol
    }

    QVector<QString> onlinePeople;
    //qDebug() << onlinePeople.size();


    if(header[1].compare("0") == 0)
    {
        qDebug() << "getUsers method";
        qDebug() << "TCP_Server_Kliens_Socket = " << TCP_Server_Kliens_Socket;
        if(TCP_Server_Kliens_Socket.compare("-1") == 0)
        {
            TCP_Server_Kliens_Socket = header[2];
            if(header.size() > 5)
            {
                for(int i = 4; i < header.size(); ++i)
                {
                    if(TCP_Server_Kliens_Socket.compare(header[i]) != 0)
                    {
                        onlinePeople.push_back(header[i]);
                    }

                }

            }
        }
        else
        {
            onlinePeople.push_back(header[2]);
        }
        QString kilepettbe = header[2];






        allMessages = messageWindow->toPlainText() + "\n" + " User" + kilepettbe + " logged in" + "\n";
        /*
        if(header.size()>4)
        {
            qDebug() << "Online emberek:";
            if(header[3].compare(TCP_Server_Kliens_Socket) == 0)
            {
                for(int i = 4; i < header.size(); ++i)
                {
                    if (header[i] != TCP_Server_Kliens_Socket)
                    {
                        qDebug() << header[i] << "\n";
                        onlinePeople.push_back(header[i]);
                    }
                }
            }



        }
        */


    }
    else if(header[1].compare("1") == 0)
    {
        qDebug() << "message sent if";

        allMessages = messageWindow->toPlainText() + "\n" + "User" + header[2] + ": " + header[4] + "\n";
    }
    else if(header[1].compare("2") == 0)
    {
        allMessages = messageWindow->toPlainText() + "\n" + "User" + header[2] + "(PM): " + header[4] + "\n";
    }



    //kiirni az adatot
    Puffer[recv_valasz] = '\0';

    qDebug() << "Ez a QT SOCKET a recv mellett : " << TCP_Kliens_Socket << "\n";
    std::sort( onlinePeople.begin(), onlinePeople.end() );
    onlinePeople.erase( std::unique( onlinePeople.begin(), onlinePeople.end() ), onlinePeople.end() );

    emit refreshWindow(allMessages, onlinePeople, TCP_Server_Kliens_Socket);

    //ui->messagesBox->setText(Puffer);
    //memcpy(Puffer, "\0", PufferHossz);
}


