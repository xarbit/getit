import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.3

Page {
    id: page_body_formdata

    function addFormdataElement() {
        col_formdata_elements.createChild("FormDataElement.qml")
    }

    KeyValueContainer {
        id: col_formdata_elements
        anchors.fill: parent
        anchors.margins: 5
        emptyText: qsTr("No formdata elements...")
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
