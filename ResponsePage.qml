import QtQuick 2.0
import QtQuick.Window 2.11
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3

Page {

    CenterTextMessage {
        id: not_sent
        visible: true
        anchors.fill: parent
        title: qsTr("Please send a request...")
    }

    CenterTextMessage {
        id: sending
        visible: false
        anchors.fill: parent
        title: qsTr("Sending request")
    }

    CenterTextMessage {
        id: error
        visible: true
        anchors.fill: parent
        title: qsTr("An error has occured")
        message: qsTr("Something went wrong sending your request...")
    }

    CenterTextMessage {
        id: timed_out
        visible: false
        anchors.fill: parent
        title: qsTr("The request has timed out")
        message: qsTr("The timeout of a request can be set in the preferences window. To disable the timout completely set the value to 0.")
    }

    CenterTextMessage {
        id: invalid_certificate
        visible: false
        anchors.fill: parent
        title: qsTr("Invalid X.509 certificate")
        message: qsTr("The server responded with an invalid X.509 certificate")
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
