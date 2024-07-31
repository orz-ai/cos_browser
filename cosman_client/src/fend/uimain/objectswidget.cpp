//#if _MSC_VER >=1600    // MSVC2015>1899,对于MSVC2010以上版本都可以使用
//#pragma execution_character_set("utf-8")
//#endif

#include "objectswidget.h"
#include "src/bend/man/mancloud.h"
#include "ui_objectswidget.h"

#include <src/fend/uidelegates/bucketdelegate.h>

#include <QStringList>
#include <QString>

ObjectsWidget::ObjectsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ObjectsWidget)
{
    ui->setupUi(this);
    ui->tableView->setModel(MC->model());

    // 设置delegate
//    ui->tableView->setItemDelegate(new BucketDelegate());
    ui->tableView->setItemDelegateForColumn(1, new BucketDelegate());

    // 设置标题内容
    QStandardItemModel* model = MC->model();
    QStringList labels;
    labels << QString::fromLocal8Bit("桶名称") << QString::fromLocal8Bit("地区") << QString::fromLocal8Bit("创建时间");

    model->setColumnCount(labels.size());
    model->setHorizontalHeaderLabels(labels);

    // 设置列宽度
    ui->tableView->setColumnWidth(0, 200);
    ui->tableView->setColumnWidth(1,200);
//    ui->tableView->setColumnWidth(2,200);
    // 设置最后一列占满宽度
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    // 隐藏垂直标题
    ui->tableView->verticalHeader()->setHidden(true);
    // 鼠标点击排序
    ui->tableView->setSortingEnabled(true);

}

ObjectsWidget::~ObjectsWidget()
{
    delete ui;
}
