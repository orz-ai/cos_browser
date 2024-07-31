
#include "bucketdelegate.h"

#include <QComboBox>

BucketDelegate::BucketDelegate(QObject *parent) : QStyledItemDelegate{parent}
{

}

QWidget *BucketDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
//    if(index.column() != 1){
//        return QStyledItemDelegate::createEditor(parent, option, index);
//    }

    QComboBox* box = new QComboBox(parent);
    box->addItem("ap-beijing");
    box->addItem("ap-shanghai");
    box->addItem("ap-hangzhou");
    box->setFrame(false);

    return box;
}

void BucketDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
//    if(index.column() != 1){
//        return QStyledItemDelegate::setEditorData(editor, index);
//    }

    QComboBox* box = static_cast<QComboBox*>(editor);
    QString text = index.data(Qt::EditRole).toString();
    box->setCurrentText(text);

}

void BucketDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
//    if(index.column() != 1){
//        return QStyledItemDelegate::setModelData(editor, model, index);
//    }

    QComboBox* box = static_cast<QComboBox*>(editor);
    model->setData(index, box->currentText());

}
