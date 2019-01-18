import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.3

RowLayout {
    id: itm_formdata
    spacing: 5

    Switch {
        id: sw_enabled
        checked: true
    }

    TextField {
        id: tf_key
        Layout.fillWidth: true
        placeholderText: qsTr("Key")

    }

    TextField {
        id: tf_value
        Layout.fillWidth: true
        placeholderText: qsTr("Value")
    }

    Button {
        id: btn_delete
        height: 40
        display: AbstractButton.IconOnly
        icon.source: "icons/getit-delete-symbolic.svg"

        Material.background: Material.Red
        Material.foreground: "#fff"

        onClicked: {
            itm_formdata.destroy();
        }
    }
}
