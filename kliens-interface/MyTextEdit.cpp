#include "mytextedit.h"

MyTextEdit::MyTextEdit(QPushButton* button)
{
    this->button = button;
}

void MyTextEdit::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return)
    {
         emit(sendMessageOnEnter(this->button));// or rather emit submitted() or something along this way
    }
    else
    {
        QTextEdit::keyPressEvent(event);
    }
}
