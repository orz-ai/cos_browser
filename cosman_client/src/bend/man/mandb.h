
#ifndef MANDB_H
#define MANDB_H


#include <QList>
#include <QObject>
#include "src/bend/dao/dbs/daologininfosqlite.h"


#define MDB ManDB::instance()

class ManDB : public QObject
{
    Q_OBJECT
public:
    explicit ManDB(QObject *parent = nullptr);

    static ManDB* instance();

    void init();

    void saveLoginInfo(const QString& name, const QString& secret_id, const QString& secret_key, const QString& remark);
    void removeLoginInfo(const QString& secret_id);
    int indexOfLoginInfo(const QString& secret_id);
    QStringList loginNameList();
    LoginInfo loginInfoByName(const QString& name);

signals:

private:
    DaoLoginInfoSqlite m_daoLoinInfo;

    QList<LoginInfo> m_loginInfoList;

};

#endif // MANDB_H
