#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "mainmodel.h"
#include "packetlistmodel.h"

static QObject *createInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    static MainModel *m_model = new MainModel();
    return m_model;

}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType<MainModel>("BR.Work.Log",0,0,"MainModel",createInstance);
    qmlRegisterType<PacketListModel>("BR.Work.Log",0,0,"packetListModel");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("main.qml")));

    return app.exec();
}
