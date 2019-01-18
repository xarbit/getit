import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3

Window {
    id: window
    visible: true
    width: 1000
    height: 600
    title: qsTr("GetIt")

    Material.theme: Material.Light
    Material.primary: Material.BlueGrey
    Material.accent: Material.Green

    MainMenu {
        id: menu_main
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
    }

    MainToolbar {
        id: toolbar
        anchors.top: menu_main.bottom
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
    }


    RequestPages {
        id: request_pages
        anchors.top: toolbar.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.margins: 5
    }
}
