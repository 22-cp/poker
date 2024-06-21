import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QmlPeople
import QmlDesk

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("hello, world")

    Desk{
        id:desk
    }

    property int n: desk.p1GetHandSize()

    Rectangle{
        width: 100;height: 100
        color: "red"
        TapHandler{
            onTapped: {
                desk.touchCard()
                desk.p1output1()
                n=desk.p1GetHandSize()
            }
        }
    }

    Row{
        anchors.centerIn: parent;
        spacing: 10

        Repeater{
            model: n
            delegate: Rectangle{
                width: 20;height: 20;color: "grey"
                property bool isRed:false

                Text{
                    anchors.centerIn: parent
                    text: desk.p1GetCard(index)
                }

                TapHandler{
                    onTapped: {
                        desk.p1select(index+1)
                        parent.color=isRed?"grey":"red"
                        isRed=!isRed
                    }
                }
            }
            onModelChanged: {
                parent.update()
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
                    desk.p1usingCard()
                    desk.p1output1()
                    n=desk.p1GetHandSize()
                }
            }
        }
    }
}
