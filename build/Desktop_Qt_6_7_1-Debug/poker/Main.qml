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
        onNowPlayChanged: {
            if(desk.nowPlay===1){
                console.log("111")
                p1b.visible=true
                p2b.visible=false
                p3b.visible=false
            }
            else if(desk.nowPlay===2){
                console.log("222")
                p2b.visible=true
                p1b.visible=false
                p3b.visible=false
            }
            else{
                console.log("333")
                p3b.visible=true
                p2b.visible=false
                p1b.visible=false
            }
        }
        onAlreadyChanged: {
            if(desk.already===3){
                desk.dealCard()
                p1.setHand(desk.getP1Hand())
                p1.sortHand()
                p2.setHand(desk.getP2Hand())
                p2.sortHand()
                p3.setHand(desk.getP3Hand())
                p3.sortHand()
                p1c.visible=false
                p2c.visible=false
                p3c.visible=false
                p1a.visible=true
                //p2a.visible=true
                //p3a.visible=true
                n1=p1.getHandSize()
                n2=p2.getHandSize()
                n3=p3.getHandSize()
            }
        }
        onMarkChanged: {
            if(desk.mark===3){
                p1a.visible=false
                p2a.visible=false
                p3a.visible=false
                desk.landlord=desk.temLandlord
                //desk.nowPlay=desk.landlord
            }
        }
        onLandlordChanged: {
            desk.nowPlay=desk.landlord
        }
    }

    People{
        id:p1
        ref: 1
    }

    People{
        id:p2
        ref:2
    }

    People{
        id:p3
        ref:3
    }

    property int tem: 1
    property int n1: p1.getHandSize()
    property int n2: p2.getHandSize()
    property int n3: p3.getHandSize()
    property int n2m: 3
    property int n3m: 3



    Column{
        anchors.centerIn: parent
        spacing: 40

    Column{
        spacing: 10
        Row{
            spacing: 10
            id:p1b
            visible: false

            Rectangle{
                width: 20;height: 20;color: "grey"

                Text{
                    anchors.centerIn:parent
                    text:qsTr("不出")

                    TapHandler{
                        onTapped: {
                            if(desk.getNumRef()!==0&&desk.getNumRef()!==p1.ref){
                                desk.nowPlay=2
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
                        p1.usingCard(desk.getNum())
                        if(p1.pushCard(desk.getNum())){
                            desk.num=p1.getNum1()
                            p1.setPlayCard(false)
                            p2.setPlayCard(true)
                            n1=p1.getHandSize()
                        }
                    }
                }
            }

        }

        Row{
            id:p1a
            spacing: 10
            visible: false
            Rectangle{
                width: 20;height: 20;color: "grey"
                Text {
                    anchors.centerIn: parent
                    text: qsTr("不叫") 
                }
                TapHandler{
                    onTapped: {
                        desk.temLandlord=p1.ref;
                        p1a.visible=false
                        p2a.visible=true
                        tem++
                        desk.mark=0;
                        n2m=3-desk.mark
                    }
                }
            }

            Repeater{
                model:3
                delegate: Rectangle{
                    width: 20;height: 20;color: "grey"
                    Text{
                        anchors.centerIn: parent
                        text: 3-index+"分"
                    }
                    TapHandler{
                        onTapped: {
                            desk.temLandlord=p1.ref
                            p1a.visible=false
                            p2a.visible=true
                            tem++
                            desk.mark=3-index
                            if(desk.mark!=3){
                            n2m=3-desk.mark
                            }
                        }
                    }
                }
            }
        }

        Rectangle{
            id:p1c
            width: 120;height: 50;color: "#FFFF00"
            radius: 10
            Text {
                anchors.centerIn: parent
                color: "red"
                text: qsTr("开始游戏")
                font.pointSize: 20
            }
            TapHandler{
                onTapped: {
                    parent.color="grey"
                    desk.setAlready(1)
                    enabled=false
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
            id:p2b
            spacing: 10
            visible: false

            Rectangle{
                width: 20;height: 20;color: "grey"

                Text{
                    anchors.centerIn:parent
                    text:qsTr("不出")

                    TapHandler{
                        onTapped: {
                            if(desk.getNumRef()!==0&&desk.getNumRef()!==p2.ref){
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
                            desk.num=p2.getNum1()
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
            id:p2a
            spacing: 10
            visible: false
            Rectangle{
                width: 20;height: 20;color: "grey"
                Text {
                    anchors.centerIn: parent
                    text: qsTr("不叫")
                    TapHandler{
                        onTapped: {
                            p2a.visible=false
                            p3a.visible=true
                        }
                    }
                }
            }

            Repeater{
                id:p2mark
                model:n2m
                delegate: Rectangle{
                    width: 20;height: 20;color: "blue"
                    Text{
                        anchors.centerIn: parent
                        text: 3-index+"分"
                    }
                    TapHandler{
                        onTapped: {
                            desk.temLandlord=p2.ref
                            p2a.visible=false
                            p3a.visible=true
                            tem++
                            desk.mark=3-index
                            if(desk.mark!=3){
                            n3m=3-desk.mark
                            }
                        }
                    }
                }
            }
        }

        Rectangle{
            id:p2c
            width: 120;height: 50;color: "#FFFF00"
            radius: 10
            Text {
                anchors.centerIn: parent
                color: "red"
                text: qsTr("开始游戏")
                font.pointSize: 20
            }
            TapHandler{
                onTapped: {
                    parent.color="grey"
                    desk.setAlready(1)
                    enabled=false
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
            id:p3b
            spacing: 10
            visible: false
            Rectangle{
                width: 20;height: 20;color: "grey"

                Text{
                    anchors.centerIn:parent
                    text:qsTr("不出")

                    TapHandler{
                        onTapped: {
                            if(desk.getNumRef()!==0&&desk.getNumRef()!==p3.ref){
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
                            desk.num=p3.getNum1()
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
            id:p3a
            spacing: 10
            visible: false
            Rectangle{
                width: 20;height: 20;color: "grey"
                Text {
                    anchors.centerIn: parent
                    text: qsTr("不叫")

                }
                TapHandler{
                    onTapped: {
                        desk.setLandlords(p3.ref,0)
                        p3a.visible=false
                        desk.landlord=desk.getLandlords()
                    }
                }
            }

            Repeater{
                model:n3m
                delegate: Rectangle{
                    width: 20;height: 20;color: "grey"
                    Text{
                        anchors.centerIn: parent
                        text: 3-index+"分"
                    }
                    TapHandler{
                        onTapped: {
                            desk.temLandlord=p3.ref
                            p1a.visible=false
                            p2a.visible=true
                            tem++
                            desk.mark=3-index
                        }
                    }
                }
            }
        }

        Rectangle{
            id:p3c
            width: 120;height: 50;color: "#FFFF00"
            radius: 10
            Text {
                anchors.centerIn: parent
                color: "red"
                text: qsTr("开始游戏")
                font.pointSize: 20
            }
            TapHandler{
                onTapped: {
                    parent.color="grey"
                    desk.setAlready(1)
                    enabled=false
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
