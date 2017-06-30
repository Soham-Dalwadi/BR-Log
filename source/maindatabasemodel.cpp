#include "maindatabasemodel.h"
#include <QDebug>

MainDataBaseModel::MainDataBaseModel(QObject *parent) :
    QObject(parent),
    m_sqlModel(new QSqlQueryModel()),
    m_userId("")
{
    connClose();
    connOpen();
}

MainDataBaseModel::~MainDataBaseModel()
{
    delete m_sqlModel;
}

MainDataBaseModel *MainDataBaseModel::instance()
{
    static MainDataBaseModel obj;
    return &obj;
}

void MainDataBaseModel::createUser(userInfo data)
{
    if(checkForDuplicateData(data.m_userId) == false)
    {
        QSqlQuery *qry = new QSqlQuery(mydb);

        qry->prepare("INSERT INTO user_list(user_name, user_id, user_password) values(:user_name, :user_id, :user_password)");

        qry->bindValue(":user_name", data.m_userName);
        qry->bindValue(":user_id", data.m_userId);
        qry->bindValue(":user_password", data.m_password);

        qDebug()<<qry->exec();
        delete qry;
        QSqlQuery *qry2 = new QSqlQuery(mydb);
        qry2->prepare("CREATE TABLE `packet_list_"+data.m_userId+"` (`packet_id` TEXT NOT NULL UNIQUE, `packet_title` TEXT NOT NULL)");
        qDebug()<<qry2->exec();
    }
}

bool MainDataBaseModel::checkForDuplicateData(QString userId)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM user_list where user_id = '"+userId+"'");

    bool isFound = false;
    if(qry.exec())
    {
        int count = 0;
        while(qry.next())
        {
            count++;
        }

        if(count > 0)
        {
            qDebug()<<Q_FUNC_INFO<<"duplicate user found";
            isFound = true;
        }
        else if(count == 0)
        {
            qDebug()<<Q_FUNC_INFO<<"No duplicate found";
        }
    }
    return isFound;
}

void MainDataBaseModel::loginUser(QString userId, QString password)
{
    qDebug()<<Q_FUNC_INFO<<"userId = "<<userId<<" password = "<<password;
    if(isValidUser(userId, password) == true)
    {
        QSqlQuery * qry = new QSqlQuery(mydb);
        qry->prepare("SELECT user_name FROM user_list where user_id = '"+userId+"'");
        qry->exec();
        m_sqlModel->setQuery(*qry);
        delete qry;
        m_userId = userId;
        qDebug()<<m_sqlModel->record(0).value(0).toString();
        emit userLoggedin(m_sqlModel->record(0).value(0).toString());
    }
}

bool MainDataBaseModel::isValidUser(QString userId, QString password)
{
    QSqlQuery qry;
    qry.prepare("SELECT user_id,user_password FROM user_list where user_id = '"+userId+"'and user_password = '"+password+"'");
    bool isFound = false;
    if(qry.exec())
    {
        int count = 0;
        while(qry.next())
        {
            count++;
        }

        if(count == 1)
        {
            qDebug()<<Q_FUNC_INFO<<"Valid user found";
            isFound = true;
        }
        else if(count != 1)
        {
            qDebug()<<Q_FUNC_INFO<<"No user found";
        }
        qDebug()<<Q_FUNC_INFO<<"count = "<<count;
    }
    return isFound;
}

QList<userPacket> MainDataBaseModel::getUserData()
{
    if(!m_packetList.isEmpty())
    {
        m_packetList.clear();
    }
    QSqlQuery *qry = new QSqlQuery(mydb);
    qry->prepare("SELECT * FROM packet_list_"+m_userId);
    if(qry->exec())
    {
        m_sqlModel->setQuery(*qry);
        qDebug()<<"rows = "<<m_sqlModel->rowCount();
        int count = m_sqlModel->rowCount();
        for(int i = 0; i< count;++i)
        {
            m_packetList.append(userPacket(m_sqlModel->record(i).value(0).toString(),m_sqlModel->record(i).value(1).toString()));
        }
    }
    return m_packetList;
}

void MainDataBaseModel::addPacket(QString id, QString title)
{
    QSqlQuery *qry = new QSqlQuery(mydb);
    qry->prepare("INSERT INTO packet_list_"+m_userId+"(packet_id, packet_title) values(:packet_id, :packet_title)");
    qry->bindValue(":packet_id", id);
    qry->bindValue(":packet_title", title);
    qDebug()<<qry->exec();

    qry->prepare("SELECT * FROM packet_list_"+m_userId);
    qDebug()<<qry->exec();
    m_sqlModel->setQuery(*qry);
    delete qry;

    m_packetList.append(userPacket(m_sqlModel->record(m_sqlModel->rowCount() - 1).value(0).toString(),m_sqlModel->record(m_sqlModel->rowCount() - 1).value(1).toString()));
    emit packetDataChanged();
}

void MainDataBaseModel::removePacket(int index)
{
    qDebug()<<Q_FUNC_INFO<<"index = "<<index;
    emit removePacketChanged(index);
}

userPacket MainDataBaseModel::getNewlyAddedPacket()
{
    userPacket obj;
    if(!m_packetList.isEmpty())
    {
        obj.m_PacketId = m_packetList.last().m_PacketId;
        obj.m_PacketTitle = m_packetList.last().m_PacketTitle;
    }
    qDebug()<<Q_FUNC_INFO<<"obj.m_PacketId = "<<obj.m_PacketId<<" obj.m_PacketTitle = "<<obj.m_PacketTitle;
    return obj;
}

void MainDataBaseModel::connClose()
{
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
}

bool MainDataBaseModel::connOpen()
{
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("workbook.db");

    if(!mydb.open())
    {
        qDebug() << "DataBase is not connected";
        return false;
    }
    else
    {
        qDebug() << "Database is connected";
        return true;
    }
}

