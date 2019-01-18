import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3

MenuBar {
    id: menubar_main

    hoverEnabled: true
    wheelEnabled: true

    Menu {
        id: menu_file
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

    Menu {
        id: menu_edit
        title: qsTr("Edit")

        Action {
            text: qsTr("Preferences")
        }
    }

    Menu {
        id: menu_request
        title: qsTr("Request")

        Action {
            text: qsTr("Validate X.509 certificates")
            checkable: true
            checked: true
        }

        Action {
            text: qsTr("Add Formdata Element")

            onTriggered: {
                request_pages.addFormdataElement()
            }
        }

        Action {
            text: qsTr("Add Cookie")

            onTriggered: {
                request_pages.addCookie()
            }
        }

        Action {
            text: qsTr("Add Header")

            onTriggered: {
                request_pages.addHeader()
            }
        }

        Menu {
            title: qsTr("Body Type")

            Action {
                id: req_type_formdata
                text: qsTr("Form Data")
                checkable: true
                checked: true

                onCheckedChanged: {
                    req_type_raw.checked = !checked

                    if (checked) {
                        request_pages.bodyTypeFormdata()
                    }
                }
            }

            Action {
                id: req_type_raw
                text: qsTr("Raw")
                checkable: true
                checked: false

                onCheckedChanged: {
                    req_type_formdata.checked = !checked

                    if (checked) {
                        request_pages.bodyTypeRaw()
                    }
                }
            }
        }
    }

    Menu {
        id: menu_help
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
}
