#ifndef MAINMODEL_H
#define MAINMODEL_H
#include <QObject>
#include "datatypes.h"


class MainDataBaseModel;
class PacketListModel;

class MainModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PacketListModel* packetListModel READ packetListModel  NOTIFY packetListModelChanged)
    Q_PROPERTY(QString userName READ userName  NOTIFY userNameChanged)

public:
    Q_DISABLE_COPY(MainModel)
    explicit MainModel(QObject *parent = 0);
    Q_INVOKABLE void createUser(QString userId, QString password, QString userName);
    Q_INVOKABLE void loginUser(QString userId, QString password);
    Q_INVOKABLE void addPacketPress();
    Q_INVOKABLE void addPacket(QString id, QString title);

    Q_INVOKABLE void removePacketPress();
    Q_INVOKABLE void selectItem(int index);

    QString userName() const;

    PacketListModel *packetListModel();
    ~MainModel();

signals:
    void packetListModelChanged();
    void listUpdated();
    void addPacketChanged();
    void userNameChanged();

public slots:
    void onUserLoggedrIn(QString name);
    void onPacketDataUpdate();
    void onPacketRemoved(int index);

private:
    MainDataBaseModel *m_dataModel;
    PacketListModel *m_packetListModel;
    QString m_userName;
    bool m_removePacket;
    void resetModel();
};

#endif // MAINMODEL_H
