import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QmlPeople

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("hello, world")

    People{
        id:p1
    }

    Rectangle{
        width: 100;height: 100
        color: "red"
        TapHandler{
            onTapped: {
                p1.touchCard()
                p1.sortHand()
                p1.output1()
            }
        }
    }

    Row{
        anchors.centerIn: parent;
        spacing: 10

        Repeater{
            model: 20
            delegate: Rectangle{
                width: 20;height: 20;color: "grey"
                property bool isRed:false

                Text{
                    anchors.centerIn: parent
                    text: index+1
                }

                TapHandler{
                    onTapped: {
                        p1.select(index+1)
                        parent.color=isRed?"grey":"red"
                        isRed=!isRed
                    }
                }
            }
        }

        Rectangle{
            width: 20;height: 20;color: "grey"

            Text{
                anchors.centerIn:parent
                text:qsTr("出牌")
            }

            TapHandler{
                onTapped: {
                    p1.usingCard()
                    p1.output1()
                }
            }
        }
    }
}
