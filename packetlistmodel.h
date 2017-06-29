#ifndef PACKETLISTMODEL_H
#define PACKETLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <datatypes.h>

class PacketListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum roles{
        PacketId = 0,
        packetTitle
    };

    explicit PacketListModel();
    int rowCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    void setData(QList<userPacket> &list);
    ~PacketListModel();

signals:

public slots:
private:
    int m_numOfCount;
    QList<userPacket> m_packetList;
};

#endif // PACKETLISTMODEL_H
