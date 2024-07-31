
#include "daologininfosqlite.h"
#include "src/config/config.h"

DaoLoginInfoSqlite::DaoLoginInfoSqlite()
{

}


bool DaoLoginInfoSqlite::exists(const QString &secretId)
{
    QString sql = QString(
                      "select id from %1 where secret_id = '%2';"
                      ).arg(CONF::TABLES::LOGIN_INFO, secretId);

    return m_db.exists(sql);
}

void DaoLoginInfoSqlite::insert(const LoginInfo &info)
{
    QString sql = QString(
                      "insert into %1 (name, secret_id, secret_key, remark, timestamp) values (?, ?, ?, ?, ?)"
                      ).arg(CONF::TABLES::LOGIN_INFO);
    QVariantList variantList;
    variantList << info.name
                << info.secret_id
                << info.secret_key
                << info.remark
                << info.timestamp;

    m_db.exec(sql, variantList);

}

void DaoLoginInfoSqlite::udpate(const LoginInfo &info)
{
    QString sql = QString(
                      "update %1 "
                      "set name= ?, "
                      "secret_key = ?, "
                      "remark = ?, "
                      "timestamp = ? "
                      "where secret_id = ?"
                      ).arg(CONF::TABLES::LOGIN_INFO);

    QVariantList variantList;
    variantList << info.name
                << info.secret_key
                << info.remark
                << info.timestamp
                << info.secret_id;

    m_db.exec(sql, variantList);
}

void DaoLoginInfoSqlite::remove(const QString &secretId)
{
    QString sql = QString(
                      "delete from %1 where secret_id = ?"
                      ).arg(CONF::TABLES::LOGIN_INFO);

    QVariantList variantList;
    variantList << secretId;

    m_db.exec(sql, variantList);
}

QList<LoginInfo> DaoLoginInfoSqlite::select()
{
    QList<LoginInfo> result;
    QString sql = QString(
                      "select name, secret_id, secret_key, remark from %1 order by timestamp desc;"
                      ).arg(
                          CONF::TABLES::LOGIN_INFO
                          );

    QList<RECORD> records = m_db.select(sql);
    foreach (const auto& record, records)
    {
        LoginInfo info;
        info.name = record["name"].toString();
        info.secret_id = record["secret_id"].toString();
        info.secret_key = record["secret_key"].toString();
        info.remark = record["remark"].toString();

        result.append(info);
    }

    return result;
}

void DaoLoginInfoSqlite::connect()
{
    m_db.connect(CONF::SQLITE::NAME);
}

void DaoLoginInfoSqlite::createLoginInfoTable()
{
    QString sql = FileHelper::readAllTxt(CONF::SQL::LOGIN_INFO_TABLE);
    m_db.exec(sql);
}
