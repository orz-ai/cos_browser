
#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginDialog; }
QT_END_NAMESPACE

class LoginDialog : public QDialog

{
    Q_OBJECT

public:
    LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    void updateLoginInfo();

protected:
    // 当函数名变成斜体了说明重写了QWidget中的鼠标按下事件
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    
    // 事件过滤器
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_btnClose_clicked();

    void on_btnLogin_clicked();

private:
    Ui::LoginDialog *ui;
    QPoint m_start;
};

#endif // LOGINDIALOG_H
