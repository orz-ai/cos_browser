
#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>


/**
 * @brief The MyLineEdit class
 * 通过自定义LineEdit控件来实现屏蔽密码框的复制粘贴
 *
 * 也可以通过事件过滤器的方式来实现
 */
class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    MyLineEdit(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *);
};

#endif // MYLINEEDIT_H
