import QtQuick 2.2
import QtQuick.Controls 1.2
import BR.Work.Log 0.0

Rectangle {
    id:base
    width: 640
    height: 480
    color:'grey'

    Label {
        id:userid
        anchors
        {
            left: base.left
            top: base.top
            leftMargin: 165
            topMargin: 130
        }

        width: 145
        height: 35
        text: "Packet ID: "
        style: Text.Normal
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 18
    }

    Label {
        id:password
        width: 145
        height: 35
        anchors
        {
            left: base.left
            top: userid.bottom
            leftMargin: 165
            topMargin: 20
        }
        text: "Packet Title: "
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 18
    }

    TextInput {
        id: textInput1
        width: 145
        height: 35
        anchors
        {
            left: userid.right
            top: base.top
            leftMargin: 20
            topMargin: 130
        }
        text: qsTr("")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 18
    }

    TextInput {
        id: textInput2
        width: 145
        height: 35
        anchors
        {
            left: userid.right
            top: textInput1.bottom
            leftMargin: 20
            topMargin: 20
        }
        text: qsTr("")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        inputMask: qsTr("")
        font.pixelSize: 18
    }

    Button {
        id: button1
        width: 145
        height: 35
        anchors
        {
            left: base.left
            top: password.bottom
            leftMargin: 165
            topMargin: 20
        }
        text: qsTr("Create")
        onClicked:
        {
           MainModel.addPacket(textInput1.text, textInput2.text)
        }
    }

    Button {
        id: button2
        width: 145
        height: 35
        anchors
        {
            left: button1.right
            top: textInput2.bottom
            leftMargin: 20
            topMargin: 20
        }
        text: qsTr("Cancel")
        onClicked:
        {
            loadScreen.source = "MainUserScreen.qml"
        }
    }
}

