#include "uimain.h"
#include "ui_uimain.h"
#include <src/fend/uilogin/logindialog.h>
#include <QDebug>
#include <QPushButton>

UiMain::UiMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UiMain)
{
    ui->setupUi(this);
    // 设置分割器初始占用比例
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 4);

    connect(ui->widgetToolBar, &ToolBarWidget::buttonClicked, this, &UiMain::onButtonClicked);
}

UiMain::~UiMain()
{
    delete ui;

    // 删除m_loginDialog
    if (m_loginDialog)
    {
        delete m_loginDialog;
    }

}

void UiMain::showLoginDialog()
{
    // 1. 如果当前登录对话框为空，则初始化
    if (this->m_loginDialog == nullptr)
    {
        // 创建
        m_loginDialog = new LoginDialog();
        m_loginDialog->updateLoginInfo();
        connect(m_loginDialog, &LoginDialog::accepted, this, &UiMain::show);
//        connect(ui->widgetToolBar, &ToolBarWidget::quitLogin, this, &UiMain::showLoginDialog);
    }


    // 主窗口隐藏
    hide();

    // 登录窗口显示
    m_loginDialog->show();
}

void UiMain::onUpload()
{

}

void UiMain::onDownload()
{

}

void UiMain::onRefresh()
{

}

void UiMain::onButtonClicked(const QString& text)
{
    if (text == QString::fromLocal8Bit("上传")){

    } else if (text == QString::fromLocal8Bit("退出登录")){
        onUnLogin();
    }
}

void UiMain::onUnLogin()
{
    // 退出登录之后需要显示登录窗口
    showLoginDialog();
}



























