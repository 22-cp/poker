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

    People{
        id:p1
    }

    People{
        id:p2
    }

    People{
        id:p3
    }

    property int n1: p1.getHandSize()
    property int n2: p2.getHandSize()
    property int n3: p3.getHandSize()

    Rectangle{
        width: 100;height: 100
        color: "red"
        TapHandler{
            onTapped: {
                desk.touchCard()
                p1.setHand(desk.getP1Hand())
                p1.sortHand()
                p1.setPlayCard(true)
                p1.setRef(1)
                p2.setHand(desk.getP2Hand())
                p2.sortHand()
                p2.setPlayCard(false)
                p2.setRef(2)
                p3.setHand(desk.getP3Hand())
                p3.sortHand()
                p3.setPlayCard(false)
                p3.setRef(3)
                n1=p1.getHandSize()
                n2=p2.getHandSize()
                n3=p3.getHandSize()
                parent.visible=false
            }
        }
    }

    Column{
        anchors.centerIn: parent
        spacing: 40
    Column{
        spacing: 10
        Row{
            spacing: 10

            Rectangle{
                width: 20;height: 20;color: "grey"

                Text{
                    anchors.centerIn:parent
                    text:qsTr("不出")

                    TapHandler{
                        onTapped: {
                            if(desk.getNumRef()!==0&&desk.getNumRef()!==p1.getRef()){
                            p1.setPlayCard(false)
                            p2.setPlayCard(true)
                            }
                            else{
                                console.log("当前该你出牌！")
                            }
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
                        if(p1.getPlayCard()){
                        p1.usingCard(desk.getNum())
                        if(p1.pushCard(desk.getNum())){
                            desk.setNum(p1.getNum1())
                            p1.setPlayCard(false)
                            p2.setPlayCard(true)
                            n1=p1.getHandSize()
                        }
                        }
                    }
                }
            }

        }

    Row{
        spacing: 10

        Repeater{
            model: n1
            delegate: Rectangle{
                width: 20;height: 20;color: "grey"
                property bool isRed:false

                Text{
                    anchors.centerIn: parent
                    text: p1.getCardName(index)
                }

                TapHandler{
                    onTapped: {
                        p1.select(index+1)
                        parent.color=isRed?"grey":"red"
                        isRed=!isRed
                    }
                }
            }
            onModelChanged: {
                parent.update()
            }
        }
    }
    }
    Column{
        spacing: 10
        Row{
            spacing: 10

            Rectangle{
                width: 20;height: 20;color: "grey"

                Text{
                    anchors.centerIn:parent
                    text:qsTr("不出")

                    TapHandler{
                        onTapped: {
                            if(desk.getNumRef()!==0&&desk.getNumRef()!==p2.getRef()){
                            p2.setPlayCard(false)
                            p3.setPlayCard(true)
                            }
                            else{
                                console.log("当前该你出牌！")
                            }
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
                        if(p2.getPlayCard()){
                        p2.usingCard(desk.getNum())
                        if(p2.pushCard(desk.getNum())){
                            desk.setNum(p2.getNum1())
                            p2.setPlayCard(false)
                            p3.setPlayCard(true)
                            n2=p2.getHandSize()
                        }
                    }
                    }
                }
            }

        }

    Row{
        spacing: 10

        Repeater{
            model: n2
            delegate: Rectangle{
                width: 20;height: 20;color: "grey"
                property bool isRed:false

                Text{
                    anchors.centerIn: parent
                    text: p2.getCardName(index)
                }

                TapHandler{
                    onTapped: {
                        p2.select(index+1)
                        parent.color=isRed?"grey":"red"
                        isRed=!isRed
                    }
                }
            }
            onModelChanged: {
                parent.update()
            }
        }
    }
    }
    Column{
        spacing: 10
        Row{
            spacing: 10

            Rectangle{
                width: 20;height: 20;color: "grey"

                Text{
                    anchors.centerIn:parent
                    text:qsTr("不出")

                    TapHandler{
                        onTapped: {
                            if(desk.getNumRef()!==0&&desk.getNumRef()!==p3.getRef()){
                            p3.setPlayCard(false)
                            p1.setPlayCard(true)
                            }
                            else{
                                console.log("当前该你出牌！")
                            }
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
                        if(p3.getPlayCard()){
                        p3.usingCard(desk.getNum())
                        if(p3.pushCard(desk.getNum())){
                            desk.setNum(p3.getNum1())
                            p3.setPlayCard(false)
                            p1.setPlayCard(true)
                            n3=p3.getHandSize()
                        }
                    }
                    }
                }
            }

        }

    Row{
        spacing: 10

        Repeater{
            model: n3
            delegate: Rectangle{
                width: 20;height: 20;color: "grey"
                property bool isRed:false

                Text{
                    anchors.centerIn: parent
                    text: p3.getCardName(index)
                }

                TapHandler{
                    onTapped: {
                        p3.select(index+1)
                        parent.color=isRed?"grey":"red"
                        isRed=!isRed
                    }
                }
            }
            onModelChanged: {
                parent.update()
            }
        }
    }
    }
    }
}
