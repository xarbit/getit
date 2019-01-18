import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3

Menu {
    title: qsTr("File")

    Action {
        text: qsTr("New")
        shortcut: "ctrl+n"
    }

    MenuSeparator{}

    Action {
        text: qsTr("Save")
    }

    Action {
        text: qsTr("Save As...")
    }

    MenuSeparator{}

    Action {
        text: qsTr("Open")
    }
}
