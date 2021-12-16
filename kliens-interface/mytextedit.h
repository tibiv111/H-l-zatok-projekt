#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QObject>
#include <QKeyEvent>
#include <QTextEdit>
#include <QPushButton>


class MyTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    MyTextEdit(QPushButton* button);
    void keyPressEvent(QKeyEvent *event);
private:
    QPushButton* button;
signals:
    void sendMessageOnEnter(QPushButton* button);

};

#endif // MYTEXTEDIT_H



