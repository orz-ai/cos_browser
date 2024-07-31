#include "toolbarwidget.h"
#include "ui_toolbarwidget.h"

#include <QSignalMapper>


ToolBarWidget::ToolBarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolBarWidget)
{
    ui->setupUi(this);

    QSignalMapper* mapper = new QSignalMapper(this);
    QList<QPushButton*> btns = findChildren<QPushButton*>();
    for(auto btn: btns)
    {
        connect(btn, SIGNAL(clicked()), mapper, SLOT(map()));
        mapper->setMapping(btn, btn->text());
    }

    connect(mapper, SIGNAL(mapped(QString)), this, SIGNAL(buttonClicked(QString)));
}

ToolBarWidget::~ToolBarWidget()
{
    delete ui;
}
