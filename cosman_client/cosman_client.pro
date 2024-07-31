QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/bend/dao/clouds/daocloudsmock.cpp \
    src/bend/dao/dbs/daologininfo.cpp \
    src/bend/dao/dbs/daologininfosqlite.cpp \
    src/bend/man/mancloud.cpp \
    src/bend/man/mandb.cpp \
    src/fend/uicom/breadwidget.cpp \
    src/fend/uicom/mylineedit.cpp \
    src/fend/uicom/pagewidget.cpp \
    src/fend/uidelegates/bucketdelegate.cpp \
    src/fend/uilogin/logindialog.cpp \
    src/fend/uimain/bucketwidget.cpp \
    src/fend/uimain/objectswidget.cpp \
    src/fend/uimain/toolbarwidget.cpp \
    src/fend/uimain/uimain.cpp \
    src/helper/dbsqlite.cpp \
    src/helper/filehelper.cpp \
    src/middle/models/cloudmodels.cpp \
    src/plugins/manplugin.cpp

HEADERS += \
    src/bend/dao/clouds/daoclouds.h \
    src/bend/dao/clouds/daocloudsmock.h \
    src/bend/dao/dbs/daologininfo.h \
    src/bend/dao/dbs/daologininfosqlite.h \
    src/bend/man/mancloud.h \
    src/bend/man/mandb.h \
    src/config/config.h \
    src/fend/uicom/breadwidget.h \
    src/fend/uicom/mylineedit.h \
    src/fend/uicom/pagewidget.h \
    src/fend/uidelegates/bucketdelegate.h \
    src/fend/uilogin/logindialog.h \
    src/fend/uimain/bucketwidget.h \
    src/fend/uimain/objectswidget.h \
    src/fend/uimain/toolbarwidget.h \
    src/fend/uimain/uimain.h \
    src/helper/dbsqlite.h \
    src/helper/filehelper.h \
    src/middle/models/cloudmodels.h \
    src/middle/models/dbmodels.h \
    src/plugins/manplugin.h

FORMS += \
    src/fend/uicom/breadwidget.ui \
    src/fend/uicom/pagewidget.ui \
    src/fend/uilogin/logindialog.ui \
    src/fend/uimain/bucketwidget.ui \
    src/fend/uimain/objectswidget.ui \
    src/fend/uimain/toolbarwidget.ui \
    src/fend/uimain/uimain.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/third/cos/libs/x64/ -lcossdk
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/third/cos/libs/x64/ -lcossdkd
else:unix: LIBS += -L$$PWD/third/cos/libs/x64/ -lcossdk

# 引入PocoFoundation.lib
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/third/cos/third_party/lib/x64/poco -lPocoFoundation
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/third/cos/third_party/lib/x64/poco -lPocoFoundation
else:unix: LIBS += -L$$PWD/third/cos/third_party/lib/x64/poco -lPocoFoundation

INCLUDEPATH += $$PWD/third/cos/include \
$$PWD/third/cos/third_party/include

DEPENDPATH += $$PWD/third/cos/include
