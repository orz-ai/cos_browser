
#include "mancloud.h"
#include "src/plugins/manplugin.h"
#include<QDebug>
#include <src/bend/dao/clouds/daocloudsmock.h>


Q_GLOBAL_STATIC(ManCloud, ins);


ManCloud::ManCloud(QObject *parent)
    : QObject{parent}
{
    m_model = new QStandardItemModel(this);
}

ManCloud* ManCloud::instance()
{
    return ins();
}

void ManCloud::setBucket()
{
    DaoClouds* dao = MP->clouds();
    QList<MyBucket> buckets = dao->buckets();

    m_model->setRowCount(buckets.size());
//    m_model->setColumnCount(3);

    for (int i = 0; i < buckets.length(); ++i) {
        const MyBucket& bucket = buckets[i];

        QModelIndex index0 = m_model->index(i, 0);
        m_model->setData(index0, bucket.name);
        // 显示tooltips
        m_model->setData(index0, QString("存储桶名称： %1").arg(bucket.name), Qt::ToolTipRole);

        QModelIndex index1 = m_model->index(i, 1);
        m_model->setData(index1, bucket.location);

        QModelIndex index2 = m_model->index(i, 2);
        m_model->setData(index2, bucket.create_date);
    }

    // 设置默认按时间降序排序
    m_model->sort(2, Qt::DescendingOrder);

}

QStandardItemModel* ManCloud::model() const
{
    return m_model;
}
