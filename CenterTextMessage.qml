import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.3

Pane {
    property string title
    property string message

    Text {
        id: txt_title
        width: parent.width
        anchors.top: parent.top
        anchors.topMargin: parent.height / 2
        text: title
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 13
    }

    Text {
        width: parent.width
        anchors.top: txt_title.bottom
        anchors.topMargin: 5
        text: message
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 11
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
