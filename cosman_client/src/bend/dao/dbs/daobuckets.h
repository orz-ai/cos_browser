
#ifndef DAOBUCKETS_H
#define DAOBUCKETS_H


#include<QList>
#include "src/bend/models/mybucket.h"


class DaoBuckets
{
public:
    DaoBuckets();

    QList<MyBucket> bucketsFromMock(const QString &path);

};

#endif // DAOBUCKETS_H
