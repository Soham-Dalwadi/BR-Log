#include <QDebug>
#include "mainmodel.h"
#include "maindatabasemodel.h"
#include "packetlistmodel.h"

MainModel::MainModel(QObject *parent) :
    QObject(parent),
    m_dataModel(MainDataBaseModel::instance()),
    m_userName(""),
    m_removePacket(false)
{
    connect(m_dataModel,&MainDataBaseModel::userLoggedin,this,&MainModel::onUserLoggedrIn);
    connect(m_dataModel,&MainDataBaseModel::packetDataChanged,this,&MainModel::onPacketDataUpdate);
    connect(m_dataModel,&MainDataBaseModel::removePacketChanged, this, &MainModel::onPacketRemoved);

    m_packetListModel = new PacketListModel();
    emit packetListModelChanged();
}

MainModel::~MainModel()
{
    delete m_packetListModel;
}

PacketListModel *MainModel::packetListModel()
{
    qDebug()<<m_packetListModel;
    return m_packetListModel;
}

void MainModel::createUser(QString userId, QString password, QString userName)
{
    qDebug()<<Q_FUNC_INFO<<"userId = "<<userId<<" password = "<<password;
    if(!userId.isEmpty() && !password.isEmpty())
    {
        userInfo data(userId, password, userName);
        m_dataModel->createUser(data);
    }
    else
    {
        qDebug()<<"To do diplay error msg of give valid input";
    }
}

void MainModel::loginUser(QString userId, QString password)
{
    qDebug()<<Q_FUNC_INFO<<"userId = "<<userId<<" password = "<<password;
    m_dataModel->loginUser(userId, password);
}

void MainModel::addPacketPress()
{
    emit addPacketChanged();
}

void MainModel::addPacket(QString id, QString title)
{
    m_dataModel->addPacket(id,title);
}

void MainModel::removePacketPress()
{
    m_removePacket = true;
    qDebug()<<Q_FUNC_INFO<<"m_removePacket = "<<m_removePacket;
}

void MainModel::selectItem(int index)
{
    if(m_removePacket == true)
    {
        m_removePacket = false;
        m_dataModel->removePacket(index);
    }
    else
    {

    }
}

QString MainModel::userName() const
{
    return m_userName;
}

void MainModel::onUserLoggedrIn(QString name)
{
    if(m_userName != name)
    {
        m_userName = name;
        emit userNameChanged();
    }
    resetModel();
}

void MainModel::onPacketDataUpdate()
{
    qDebug()<<Q_FUNC_INFO;
    m_packetListModel->addPacket(m_dataModel->getNewlyAddedPacket());
    emit listUpdated();
}

void MainModel::onPacketRemoved(int index)
{
    m_packetListModel->removePacket(index);
}

void MainModel::resetModel()
{
    qDebug()<<Q_FUNC_INFO;
    QList<userPacket> list = m_dataModel->getUserData();
    m_packetListModel->setData(list);
    emit listUpdated();
}

