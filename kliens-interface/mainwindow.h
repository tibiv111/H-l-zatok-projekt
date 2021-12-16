#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "messagesreceiver.h"
#include "mytextedit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
struct protocol{
    char const* length;
    char const*  type;
    char const*  from;
    char const*  to;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:

    MainWindow(QWidget *parent = nullptr);
    void ThreadObserver();
    bool connectToServer();
    bool getConnectedUsers();
    void buildProtocol(int, int, int, char*);
    ~MainWindow();

private slots:
    void on_sendToEveryoneButton_clicked();
    void exitApp();
    void on_refreshWindow(QString message, QVector<QString> onlinePeople, QString username);
    void on_sendMessageOnEnter(QPushButton* button);
    void on_MainWindow_destroyed();
    //void on_serverConnectBtn_clicked();

    void on_exitButton_clicked();

    void on_sendPMButton_clicked();

    void on_currentlyOnlineListWidget_itemClicked(QListWidgetItem *item);

    void on_currentlyOnlineListWidget_itemSelectionChanged();

private:
    Ui::MainWindow *ui;
    MessagesReceiver* messageThread;
    QListWidgetItem pmPerson;
    QTextEdit * username;
    SOCKET TCP_Kliens_Socket;
    QString TCP_Server_Kliens_Socket = "-1";
    int PufferHossz = 1024;
    char* Puffer = (char*) malloc(PufferHossz* sizeof(char)) ;
};
#endif // MAINWINDOW_H
