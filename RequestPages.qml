import QtQuick 2.0
import QtQuick.Window 2.11
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3

SwipeView {
    currentIndex: 0
    interactive: false

    function addFormdataElement() {
        page_body_formdata.createChild("FormDataElement.qml")
    }

    function addCookie() {
        page_cookies.createChild("KeyValuePair.qml")
    }

    function addHeader() {
        page_headers.createChild("KeyValuePair.qml")
    }

    function bodyTypeFormdata() {
        page_body_formdata.visible = true
        page_body_raw.visible = false
    }

    function bodyTypeRaw() {
        page_body_formdata.visible = false
        page_body_raw.visible = true

        page_body_raw.hide()
    }

    KeyValueContainer {
        id: page_body_formdata
        title: qsTr("Body")
        emptyText: qsTr("No Formdata Elements...")
    }

    Page {
        id: page_body_raw
        title: qsTr("Raw")
        visible: false
    }

    KeyValueContainer {
        id: page_cookies
        title: qsTr("Cookies")
        emptyText: qsTr("No Cookies...")
    }

    KeyValueContainer {
        id: page_headers
        title: qsTr("Headers")
        emptyText: qsTr("No Headers...")
    }

    ResponsePage {
        id: page_response
        title: qsTr("Response")
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
