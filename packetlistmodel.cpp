#include "packetlistmodel.h"
#include <QDebug>
PacketListModel::PacketListModel() :
    m_numOfCount(0)
{
}

PacketListModel::~PacketListModel()
{

}
int PacketListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_numOfCount;
}

QHash<int, QByteArray> PacketListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(PacketId,"packetId");
    roles.insert(packetTitle,"packetTitle");

    return roles;
}

QVariant PacketListModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<"index = "<<index.row()<<" role = "<<role;
    if(index.row()<0 || index.row()>m_numOfCount)
    {
        return QVariant();
    }
    int row = index.row();
    switch (role)
    {
    case PacketId:
        return m_packetList.at(row).m_PacketId;
    case packetTitle:
        return m_packetList.at(row).m_PacketTitle;
    default:
        return QVariant();
    }
}

void PacketListModel::setData(QList<userPacket> &list)
{
    if(!m_packetList.isEmpty())
    {
        m_packetList.clear();
    }
    m_packetList  = list;
    m_numOfCount = m_packetList.count();
    beginResetModel();
    endResetModel();
}

void PacketListModel::addPacket(userPacket newPacket)
{
    qDebug()<<Q_FUNC_INFO<<"newPacket.m_PacketId = "<<newPacket.m_PacketId<<" newPacket.m_PacketTitle = "<<newPacket.m_PacketTitle;
    m_packetList.append(newPacket);
    insertRows(m_numOfCount, 1, QModelIndex());
}

bool PacketListModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent,row,row+count-1);
    m_numOfCount++;
    endInsertRows();
    return true;
}


