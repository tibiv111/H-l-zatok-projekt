#ifndef MESSAGESRECEIVER_H
#define MESSAGESRECEIVER_H

#include <QListView>
#include <QListWidget>
#include <QTextEdit>
#include <QThread>
#include <QVector>
#include <winsock2.h>




class MessagesReceiver : public QThread
{
    Q_OBJECT
public:
    MessagesReceiver(SOCKET TCP_Kliens_Socket, QString TCP_Server_Kliens_Socket, QTextEdit* messageWindow, QListWidget *currentlyOnlineListWidget, QTextEdit * username);
    void parseHeader();
    void tokenize(std::string const&, const char, QVector<QString>&);

    void run();

private:
    SOCKET TCP_Kliens_Socket;

    QString TCP_Server_Kliens_Socket;
    char Puffer[1024];
    int PufferHossz = 1024;
    QTextEdit *messageWindow;
    QListWidget *currentlyOnlineListWidget;
    QTextEdit *username;

    QStringList header;

signals:
    void refreshWindow(QString message, QVector<QString> onlinePeople, QString username);



};

#endif // MESSAGESRECEIVER_H
