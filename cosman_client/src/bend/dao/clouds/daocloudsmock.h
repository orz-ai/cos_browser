﻿
#ifndef DAOCLOUDSMOCK_H
#define DAOCLOUDSMOCK_H

#include "daoclouds.h"

#include <QJsonValue>
#include <QList>
class DaoCloudsMock: public DaoClouds
{

public:
    DaoCloudsMock(const QString& path);

    virtual QList<MyBucket> buckets();

private:
    QJsonValue m_mock;
};

#endif // DAOCLOUDSMOCK_H
