
#ifndef DAOLOGININFO_H
#define DAOLOGININFO_H

#include "src/middle/models/dbmodels.h"
#include <src/helper/dbsqlite.h>


class DaoLoginInfo
{
public:
    DaoLoginInfo();

    virtual bool exists(const QString& secretId)=0;
    virtual void insert(const LoginInfo& info)=0;
    virtual void udpate(const LoginInfo& info)=0;
    virtual void remove(const QString& secretId)=0;
    virtual QList<LoginInfo> select()=0;


    virtual void connect()=0;
    virtual void createLoginInfoTable()=0;
};

#endif // DAOLOGININFO_H
