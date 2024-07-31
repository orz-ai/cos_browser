
#ifndef MANCLOUD_H
#define MANCLOUD_H


#include <QObject>
#include <QStandardItemModel>

#define MC ManCloud::instance()


class ManCloud : public QObject
{
    Q_OBJECT
public:
    explicit ManCloud(QObject *parent = nullptr);

    static ManCloud* instance();

    void setBucket();

    QStandardItemModel *model() const;

signals:

private:
    QStandardItemModel* m_model = nullptr;

};

#endif // MANCLOUD_H
