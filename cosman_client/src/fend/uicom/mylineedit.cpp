
#include "mylineedit.h"

#include <QKeyEvent>

MyLineEdit::MyLineEdit(QWidget *parent): QLineEdit(parent)
{

}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    // 捕捉ctrl+c和ctrl+v，屏蔽密码框的复制粘贴
    if (event->modifiers() == Qt::ControlModifier)
    {
        if(event->key() == Qt::Key_C || event->key() == Qt::Key_V)
        {
            return;
        }
    }

    QLineEdit::keyPressEvent(event);
}

