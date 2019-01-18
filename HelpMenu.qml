import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3

Menu {
    title: qsTr("Help")

    Action {
        text: qsTr("Shortcuts")
    }

    Action {
        text: qsTr("About")
    }

    Action {
        text: qsTr("About Qt")
    }

    MenuSeparator{}

    Action {
        text: qsTr("View on GitHub")
    }
}
