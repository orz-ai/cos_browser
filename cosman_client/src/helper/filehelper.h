
#ifndef FILEHELPER_H
#define FILEHELPER_H


#include<QString>
#include <QVariant>

class FileHelper
{
public:
    FileHelper();

    static QString readAllTxt(const QString& filePath);
    static QVariant readAllJson(const QString& filepath);

    static QString joinPath(const QString& path1, const QString path2);
    static bool mkPath(const QString& path);
};

#endif // FILEHELPER_H
