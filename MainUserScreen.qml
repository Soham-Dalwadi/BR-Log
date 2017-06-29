import QtQuick 2.2
import QtQuick.Controls 1.2
import BR.Work.Log 0.0

FocusScope
{
    Rectangle
    {
        id:base
        width: 640
        height: 480
        anchors.centerIn: parent.Center
        color:'grey'
        Item
        {
            width: parent.width
            anchors.top: base.top
            anchors.bottom:listContainer.top
            Label
            {
                id:userId
                width: 145
                height: 35
                text: "User ID: " + MainModel.userName
                style: Text.Normal
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 18
                anchors.verticalCenter: parent.verticalCenter
            }
            Button
            {
                id:addButton
                width: 145
                height: 35
                text: "Add"
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                onClicked: {
                    MainModel.addPacketPress()
                }
            }
        }

        Item
        {
            id:listContainer
            width: 640
            height: 380
            anchors.bottom:base.bottom
            ListView
            {
                snapMode: ListView.SnapToItem
                spacing: 2
                boundsBehavior: Flickable.StopAtBounds
                anchors.fill: parent
                clip:true
                delegate:
                    Rectangle{
                    id:baseDelegat
                    width:680
                    height:98.5
                    color:'lightgreen'
                    Text{
                        width:50
                        height:50
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        horizontalAlignment: Text.AlignLeft
                        font.pixelSize: 30
                        color:'black'
                        text: model.packetId ? model.packetId + "          " + model.packetTitle : ""
                    }

                }
                model: MainModel.packetListModel
            }
        }


    }
}


