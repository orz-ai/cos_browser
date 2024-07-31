#include "bucketwidget.h"
#include "src/bend/man/mancloud.h"
#include "ui_bucketwidget.h"

BucketWidget::BucketWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BucketWidget)
{
    ui->setupUi(this);
    ui->listView->setModel(MC->model());
}

BucketWidget::~BucketWidget()
{
    delete ui;
}
