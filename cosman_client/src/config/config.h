
#ifndef CONFIG_H
#define CONFIG_H

#endif // CONFIG_H

#include<QString>
#include<QDir>

#include <src/helper/filehelper.h>

namespace CONF {

    namespace PATH {
        static const QString WORK = QDir::currentPath();
        static const QString TEMP = FileHelper::joinPath(WORK, "temp");
    };

    namespace SQLITE {
        static const QString NAME= FileHelper::joinPath(PATH::TEMP, "cos.db");
    }

    namespace SQL {
        static const QString LOGIN_INFO_TABLE= ":/static/sql/login_info.sql";
    }

    namespace TABLES {
        static const QString LOGIN_INFO= "login_info";
    }

    static bool init() {
        return FileHelper::mkPath(PATH::TEMP);
    }

    // 启动的时候初始化SQLITE数据库目录
    static bool OK = init();

}
