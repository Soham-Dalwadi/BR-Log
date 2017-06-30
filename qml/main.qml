import QtQuick 2.2
import QtQuick.Window 2.2
import BR.Work.Log 0.0

Window
{
    id: root
    visible: true
    width: 640
    height: 480
    property alias loadScreen: loaderObj

    LoginScreen{
        id: idLoginScreen
        anchors.fill: parent
    }

    Loader {
        id: loaderObj
        anchors.fill: parent
    }

    Connections {
        target: MainModel
        onListUpdated:{
            loaderObj.source = "MainUserScreen.qml";
        }
        onAddPacketChanged:{
            loaderObj.source = "";
            loaderObj.source = "PacketDetailScreen.qml";
        }
    }
}
