#include "logindialog.h"
#include "src/bend/man/mandb.h"
#include "ui_logindialog.h"

#include <QCompleter>
#include <QMessageBox>
#include <QMouseEvent>
#include <QString>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);


//    QPixmap pixmap("D:/project/qt/cos_browser/static/img/logo.png");
//    ui->labelLogo->setPixmap(pixmap.scaled(ui->labelLogo->size()));

    // 注册事件过滤器：通过事件过滤器来屏蔽密码框的复制粘贴功能
    ui->lineSecretKey->installEventFilter(this);

    ui->labelTitle->setProperty("style", "h3");
    ui->labelLoginName->setProperty("style", "h5");
    ui->labelSecretId->setProperty("style", "h5");
    ui->labelSecretKey->setProperty("style", "h5");
    ui->labelComment->setProperty("style", "h5");
    ui->btnClose->setProperty("style", "h5");
    ui->btnLogin->setProperty("style", "h5");


}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::updateLoginInfo()
{
    // 添加候选填充功能
    QStringList words = MDB->loginNameList();
    QCompleter* completer = new QCompleter(words);

    ui->lineLoginName->setCompleter(completer);
    connect(completer, static_cast<void (QCompleter::*)(const QString&)>(&QCompleter::activated), [&](const QString& name){
        LoginInfo info = MDB->loginInfoByName(name);
        ui->lineSecretId->setText(info.secret_id);
        ui->lineSecretKey->setText(info.secret_key);
        ui->lineRemark->setText(info.remark);
        ui->checkSaveSession->setChecked(true);
    });
}

/**
 * @brief LoginDialog::mousePressEvent
 * @param event
 * 点击事件，记录鼠标在主体上点击的初始位置。
 */
void LoginDialog::mousePressEvent(QMouseEvent *event)
{
    // 记录当前鼠标点击的位置，相对于父控件坐标原点的位置。
    if (event->button() == Qt::LeftButton)
    {
        m_start = event->pos();
    }

    QDialog::mousePressEvent(event);
}

/**
 * @brief LoginDialog::mouseMoveEvent
 * @param event
 * 将窗体移动到鼠标移动的位置，实现左击可以移动窗体。
 */
void LoginDialog::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        QPoint targetPos = event->pos() - this->m_start + this->pos();
        this->move(targetPos);
    }

    QDialog::mouseMoveEvent(event);
}

bool LoginDialog::eventFilter(QObject* watched, QEvent* event)
{
    // watched 表示需要关注的控件对象
    // event表示传递给事假对象的事件
    if(watched == ui->lineSecretKey)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->modifiers() == Qt::ControlModifier)
            {
                if (keyEvent->key() == Qt::Key_C || keyEvent->key() == Qt::Key_V)
                {
                    // true：事件处理，不在传递
                    // false: 继续向下传递
                    return true;
                }
            }
        }
    }

    return false;
}



void LoginDialog::on_btnClose_clicked()
{
    reject();
}


void LoginDialog::on_btnLogin_clicked()
{
    // 登录信息验证
    QString secrite_id = ui->lineSecretId->text().trimmed();
    QString secrite_key = ui->lineSecretKey->text().trimmed();
//    if (secrite_id != "1" || secrite_key != "1"){
//        // 提示登录失败
//        QMessageBox::warning(
//            this,
//            QString::fromLocal8Bit("登录失败"),
//            QString::fromLocal8Bit("请检查secret_id或者secret_key是否正确")
//        );

//        return;
//    }

    accept();

    QString name = ui->lineLoginName->text().trimmed();
    QString remark = ui->lineRemark->text().trimmed();

    if (ui->checkSaveSession->isChecked()){
        // 保存登录信息到数据库
        MDB->saveLoginInfo(
            name,
            secrite_id,
            secrite_key,
            remark
        );
    } else {
        // 删除库里的登录信息
        MDB->removeLoginInfo(secrite_id);
    }

    updateLoginInfo();
}

