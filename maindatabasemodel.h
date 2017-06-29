#ifndef MAINDATABASEMODEL_H
#define MAINDATABASEMODEL_H

#include <QObject>
#include <QtSql>
#include "datatypes.h"

class MainDataBaseModel : public QObject
{
    Q_OBJECT
    explicit MainDataBaseModel(QObject *parent = 0);
public:
    ~MainDataBaseModel();
    static MainDataBaseModel* instance();
    void createUser(userInfo data);
    void loginUser(QString userId, QString password);
    bool checkForDuplicateData(QString userId);
    bool isValidUser(QString userId, QString password);
    QList<userPacket> getUserData();
    void addPacket(QString id, QString title);
    userPacket getNewlyAddedPacket();

signals:
    void userLoggedin(QString name);
    void packetDataChanged();

public slots:
private:
    QSqlQueryModel * m_sqlModel;
    QSqlDatabase mydb;
    QString m_userId;
    QList<userPacket> m_packetList;
    void connClose();
    bool connOpen();
};

#endif // MAINDATABASEMODEL_H
