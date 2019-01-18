import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.3

Page {
    property string emptyText

    function createChild(qmlFile) {
        var component = Qt.createComponent(qmlFile)
        component.createObject(col_children, {
                              width: col_children.width
                          })
    }

    ScrollView {
        clip: true
        anchors.fill: parent

        ColumnLayout {
            id: col_children
            visible: false
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.top: parent.top
            spacing: 5
            anchors.margins: 5

            onHeightChanged: {
                var hasChildren         = height > 0
                col_children.visible    = hasChildren
                txt_empty.visible       = !hasChildren
            }
        }

        CenterTextMessage {
            id: txt_empty
            anchors.fill: parent
            title: emptyText
        }
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
