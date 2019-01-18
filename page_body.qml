import QtQuick 2.0
import QtQuick.Controls 2.3

Page {
    id: page_body
    title: qsTr("Body")

    ComboBox {
        id: cb_method
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 5
        editable: true

        model: [
            "GET", "POST", "PUT", "PATCH", "DELETE", "COPY", "HEAD", "OPTIONS"
        ]
    }

    TextField {
        id: tf_uri
        anchors.left: cb_method.right
        anchors.leftMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        placeholderText: qsTr("http://...")
    }

    DelayButton {
        id: delayButton
        x: 364
        y: 220
        text: qsTr("Delay Button")
        checked: false
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
