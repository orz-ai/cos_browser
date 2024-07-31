
#include "mandb.h"

#include<src/config/config.h>
#include <QDateTime>


Q_GLOBAL_STATIC(ManDB, ins);

ManDB::ManDB(QObject *parent)
    : QObject{parent}
{

}

ManDB *ManDB::instance()
{
    return ins();
}


void ManDB::init()
{
    m_daoLoinInfo.connect();
    m_daoLoinInfo.createLoginInfoTable();
    m_loginInfoList = m_daoLoinInfo.select();
}

void ManDB::saveLoginInfo(const QString &name, const QString &secret_id, const QString &secret_key, const QString &remark)
{
    LoginInfo info;
    info.name = name;
    info.secret_id = secret_id;
    info.secret_key = secret_key;
    info.remark = remark;

    info.timestamp = QDateTime::currentDateTimeUtc().toTime_t();
    if (m_daoLoinInfo.exists(secret_id)){
        // 如果已经存在走更新逻辑
        m_daoLoinInfo.udpate(info);
        // 更新缓存
        m_loginInfoList[indexOfLoginInfo(secret_id)] = info;
        return;
    }

    // 不存在，直接新增
    m_daoLoinInfo.insert(info);
    // 更新缓存
    m_loginInfoList.append(info);
}

void ManDB::removeLoginInfo(const QString &secret_id)
{
    if (!m_daoLoinInfo.exists(secret_id)){
        return;
    }

    m_daoLoinInfo.remove(secret_id);

    // 删除缓存
    m_loginInfoList.removeAt(indexOfLoginInfo(secret_id));
}

int ManDB::indexOfLoginInfo(const QString &secret_id)
{
    for (int i = 0; i < m_loginInfoList.size(); ++i) {
        if (m_loginInfoList[i].secret_id == secret_id){
            return i;
        }
    }

    throw QString::fromLocal8Bit("获取登录信息索引失败：%1").arg(secret_id);
}

QStringList ManDB::loginNameList()
{
    QStringList words;
    for (int i = 0; i < m_loginInfoList.size(); ++i) {
        words.append(m_loginInfoList[i].name);
    }

    return words;

}

LoginInfo ManDB::loginInfoByName(const QString &name)
{
    for (int i = 0; i < m_loginInfoList.size(); ++i) {
        if(m_loginInfoList[i].name == name){
            return m_loginInfoList[i];
        }
    }

    throw QString::fromLocal8Bit("通过名称查找登录信息失败：%1").arg(name);
}








