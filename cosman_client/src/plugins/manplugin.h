
#ifndef MANPLUGIN_H
#define MANPLUGIN_H


#include <QObject>

class DaoClouds;


# define MP ManPlugin::instance()


class ManPlugin: public QObject
{
    Q_OBJECT
public:
    explicit ManPlugin(QObject *parent = nullptr);

    static ManPlugin* instance();

    DaoClouds *clouds() const;

private:
    // 不能使用派生类作为他的模型
    DaoClouds* m_clouds;

    void installPlugins();

};

#endif // MANPLUGIN_H
