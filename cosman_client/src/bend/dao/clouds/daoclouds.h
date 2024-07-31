
#ifndef DAOCLOUDS_H
#define DAOCLOUDS_H

#include "src/middle/models/cloudmodels.h"

#include <QList>


class DaoClouds
{

public:
    DaoClouds(){};

    virtual QList<MyBucket> buckets()=0;
};

#endif // DAOCLOUDS_H
