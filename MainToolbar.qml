import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3

ToolBar {
    id: toolbar
    height: 100

    // Request information
    ComboBox {
        id: cb_method
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 5
        editable: true
        Material.foreground: "#fff"

        model: [
            "GET", "POST", "PUT", "PATCH", "DELETE", "COPY", "HEAD", "OPTIONS"
        ]
    }

    TextField {
        id: tf_uri
        height: cb_method.height

        anchors.left: cb_method.right
        anchors.leftMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.right: tb_btn_send.left
        anchors.rightMargin: 5
        placeholderText: qsTr("http://...")
        Material.foreground: "#fff"
    }

    // Send/cancel button
    Button {
        id: tb_btn_send
        text: qsTr("Send")
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        width: 75
        Material.background: Material.accent

        onClicked: {
            tb_btn_send.visible = false
            tb_btn_cancel.visible = true
            tb_bi_loading.running = true
        }
    }

    Button {
        id: tb_btn_cancel
        text: qsTr("Cancel")
        anchors.top: parent.top
        anchors.topMargin: 5
        visible: false
        anchors.right: parent.right
        anchors.rightMargin: 5
        width: 75
        Material.background: Material.Red

        onClicked: {
            tb_btn_send.visible = true
            tb_btn_cancel.visible = false
            tb_bi_loading.running = false
        }
    }


    // Pages
    PageIndicator {
        id: page_indicator
        height: tb_btn_send.height
        padding: 0
        wheelEnabled: true
        anchors.left: parent.left
        anchors.leftMargin: 5
        interactive: true
        count: request_pages.count
        currentIndex: request_pages.currentIndex
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        spacing: 0

        delegate: Button {
            text: request_pages.itemAt(index).title
            checkable: true
            autoExclusive: true
            width: 100
            checked: request_pages.currentIndex === index
            Material.background: Material.primary
            Material.elevation: 0

            onClicked: {
                request_pages.setCurrentIndex(index)
            }
        }
    }

    // Loading indicator
    BusyIndicator {
        id: tb_bi_loading
        anchors.right: parent.right
        anchors.rightMargin: 5
        width: 40
        running: false
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
    }
}
