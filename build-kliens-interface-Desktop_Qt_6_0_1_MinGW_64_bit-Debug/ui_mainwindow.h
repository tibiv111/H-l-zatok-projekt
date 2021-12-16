/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *messageTextEdit;
    QLabel *typeYourMessageLabel;
    QPushButton *sendToEveryoneButton;
    QPushButton *sendPMButton;
    QListView *chatGroupsListView;
    QLabel *chatGroupsLabel;
    QLabel *currentlyOnlineLabel;
    QLabel *extra;
    QPushButton *sendFileButton;
    QLabel *messagesLabel;
    QTextEdit *messagesBox;
    QPushButton *exitButton;
    QListWidget *currentlyOnlineListWidget;
    QTextEdit *username;
    QMenuBar *menubar;
    QMenu *menuChat_app;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        messageTextEdit = new QTextEdit(centralwidget);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));
        messageTextEdit->setGeometry(QRect(20, 380, 421, 87));
        typeYourMessageLabel = new QLabel(centralwidget);
        typeYourMessageLabel->setObjectName(QString::fromUtf8("typeYourMessageLabel"));
        typeYourMessageLabel->setGeometry(QRect(20, 360, 131, 16));
        sendToEveryoneButton = new QPushButton(centralwidget);
        sendToEveryoneButton->setObjectName(QString::fromUtf8("sendToEveryoneButton"));
        sendToEveryoneButton->setEnabled(false);
        sendToEveryoneButton->setGeometry(QRect(20, 470, 151, 31));
        sendPMButton = new QPushButton(centralwidget);
        sendPMButton->setObjectName(QString::fromUtf8("sendPMButton"));
        sendPMButton->setEnabled(false);
        sendPMButton->setGeometry(QRect(20, 510, 151, 28));
        chatGroupsListView = new QListView(centralwidget);
        chatGroupsListView->setObjectName(QString::fromUtf8("chatGroupsListView"));
        chatGroupsListView->setGeometry(QRect(470, 380, 281, 111));
        chatGroupsLabel = new QLabel(centralwidget);
        chatGroupsLabel->setObjectName(QString::fromUtf8("chatGroupsLabel"));
        chatGroupsLabel->setGeometry(QRect(470, 360, 131, 16));
        currentlyOnlineLabel = new QLabel(centralwidget);
        currentlyOnlineLabel->setObjectName(QString::fromUtf8("currentlyOnlineLabel"));
        currentlyOnlineLabel->setGeometry(QRect(470, 30, 131, 16));
        extra = new QLabel(centralwidget);
        extra->setObjectName(QString::fromUtf8("extra"));
        extra->setGeometry(QRect(180, 510, 161, 31));
        sendFileButton = new QPushButton(centralwidget);
        sendFileButton->setObjectName(QString::fromUtf8("sendFileButton"));
        sendFileButton->setEnabled(false);
        sendFileButton->setGeometry(QRect(180, 470, 261, 31));
        messagesLabel = new QLabel(centralwidget);
        messagesLabel->setObjectName(QString::fromUtf8("messagesLabel"));
        messagesLabel->setGeometry(QRect(20, 30, 131, 16));
        messagesBox = new QTextEdit(centralwidget);
        messagesBox->setObjectName(QString::fromUtf8("messagesBox"));
        messagesBox->setGeometry(QRect(20, 50, 421, 301));
        messagesBox->setReadOnly(true);
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(500, 510, 251, 31));
        currentlyOnlineListWidget = new QListWidget(centralwidget);
        currentlyOnlineListWidget->setObjectName(QString::fromUtf8("currentlyOnlineListWidget"));
        currentlyOnlineListWidget->setGeometry(QRect(470, 50, 281, 301));
        username = new QTextEdit(centralwidget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(640, 10, 111, 31));
        username->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuChat_app = new QMenu(menubar);
        menuChat_app->setObjectName(QString::fromUtf8("menuChat_app"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuChat_app->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        typeYourMessageLabel->setText(QCoreApplication::translate("MainWindow", "Type your message:", nullptr));
        sendToEveryoneButton->setText(QCoreApplication::translate("MainWindow", "Send to everyone", nullptr));
        sendPMButton->setText(QCoreApplication::translate("MainWindow", "Send PM", nullptr));
        chatGroupsLabel->setText(QCoreApplication::translate("MainWindow", "Chatgroups:", nullptr));
        currentlyOnlineLabel->setText(QCoreApplication::translate("MainWindow", "Currently online:", nullptr));
        extra->setText(QCoreApplication::translate("MainWindow", "(Choose someone online)", nullptr));
        sendFileButton->setText(QCoreApplication::translate("MainWindow", "Send file", nullptr));
        messagesLabel->setText(QCoreApplication::translate("MainWindow", "Messages:", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menuChat_app->setTitle(QCoreApplication::translate("MainWindow", "Chat-app", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
