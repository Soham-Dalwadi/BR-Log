import QtQuick 2.4
import QtQuick.Controls 1.2
import BR.Work.Log 0.0

FocusScope
{
    Rectangle {
        id:base
        width: 640
        height: 480
        anchors.centerIn: parent.Center
        color:'grey'

        Label {
            id:userid
            anchors
            {
                left: base.left
                top: base.top
                leftMargin: 163
                topMargin: 130
            }

            width: 145
            height: 35
            text: "User ID"
            style: Text.Normal
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
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
                leftMargin: 163
                topMargin: 20
            }
            text: "Password"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
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
                leftMargin: 18
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
                leftMargin: 18
                topMargin: 20
            }
            text: qsTr("")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            echoMode: TextInput.Password
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
                leftMargin: 163
                topMargin: 20
            }
            text: qsTr("Create")
            onClicked:
            {
                MainModel.createUser(textInput1.text, textInput2.text, textInput3.text)
                loadScreen.source = ""
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
                leftMargin: 18
                topMargin: 20
            }
            text: qsTr("Cancel")
            onClicked:
            {
                loadScreen.source = ""
            }
        }

        TextInput {
            id: textInput3
            x: 330
            y: 0
            width: 145
            height: 35
            text: qsTr("")
            selectionColor: "#1c19a6"
            anchors.leftMargin: 18
            anchors.left: userid.right
            anchors.topMargin: 70
            anchors.top: base.top
            font.pixelSize: 18
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Label {
            id: userName
            x: -1
            y: 0
            width: 145
            height: 35
            text: "User Name"
            style: Text.Normal
            anchors.leftMargin: 163
            anchors.left: base.left
            font.pointSize: 18
            anchors.topMargin: 70
            anchors.top: base.top
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }
    }


}

