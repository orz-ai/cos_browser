
#include "dbsqlite.h"
#include "qdebug.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

DbSqlite::DbSqlite()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");

}

DbSqlite::~DbSqlite()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

void DbSqlite::connect(const QString &dbpath)
{
    m_db.setDatabaseName(dbpath);
    if(!m_db.open())
    {
        throw QString::fromLocal8Bit("打开数据库失败：%1 %2").arg(dbpath, m_db.lastError().text());
    }
}

QSqlQuery DbSqlite::exec(const QString &sql)
{
    QSqlQuery query;
    if (!query.exec(sql)){
        qDebug() << query.lastError().text();
        throw QString::fromLocal8Bit("执行SQL失败：%1 %2").arg(sql, query.lastError().text());
    }

    return query;
}

QSqlQuery DbSqlite::exec(const QString &sql, const QVariantList &variantList)
{
    QSqlQuery query;
    if(!query.prepare(sql)){
        throw QString::fromLocal8Bit("预编译SQL失败：%1 %2").arg(
            sql,
            query.lastError().text()
        );
    }

    for(const auto& var: variantList){
        query.addBindValue(var);
    }

    if (!query.exec()){
        qDebug() << query.lastError().text();
        throw QString::fromLocal8Bit("执行SQL失败：%1 %2").arg(
            sql,
            query.lastError().text()
        );
    }

    return query;
}

bool DbSqlite::exists(const QString &sql)
{
    QSqlQuery query = exec(sql);
    return query.next();
}

QList<RECORD> DbSqlite::select(const QString& sql)
{
    QList<RECORD> results;
    QSqlQuery query = exec(sql);

    while (query.next()){
        RECORD result;
        QSqlRecord record = query.record();
        for (int i = 0; i < record.count(); ++i) {
            QString name = record.fieldName(i);
            QVariant value = record.value(i);
            result[name] = value;
        }

        qDebug() << QString::fromLocal8Bit("查询出结果：") << result;
        results.append(result);

    }

    return results;

}

