﻿
#include "filehelper.h"

#include <QDir>
#include <QFile>
#include <QJsonDocument>

FileHelper::FileHelper()
{

}

QString FileHelper::readAllTxt(const QString &filePath)
{
    QFile file(filePath);
    if (file.exists() && file.open(QIODevice::ReadOnly))
    {
        QByteArray data = file.readAll();
        file.close();

        return data;
    }

    throw "读取文件失败";
}

QVariant FileHelper::readAllJson(const QString &filepath)
{
    QString data = FileHelper::readAllTxt(filepath);
    QJsonDocument json = QJsonDocument::fromJson(data.toLocal8Bit());

    return json.toVariant();
}

QString FileHelper::joinPath(const QString &path1, const QString path2)
{
    QString path = path1 + "/" + path2;
    QStringList pathList = path.split(QRegExp("[/\\\\]"), Qt::SkipEmptyParts);
    path = pathList.join("/");
    return QDir::cleanPath(path);
}

bool FileHelper::mkPath(const QString &path)
{
    QDir dir;
    return dir.mkdir(path);
}

