#ifndef DATATYPES
#define DATATYPES
#include <QtCore>
struct userInfo{
    QString m_userId;
    QString m_password;
    QString m_userName;
    userInfo(QString userId, QString password, QString userName):
        m_userId(userId),
        m_password(password),
        m_userName(userName)
    {

    }
};

struct userPacket{
    QString m_PacketId;
    QString m_PacketTitle;
    userPacket(QString packetId,QString packetTitle):
        m_PacketId(packetId),
        m_PacketTitle(packetTitle)
    {

    }
};

#endif // DATATYPES

