import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QmlPeople
import QmlDesk

ApplicationWindow {
    width: 1600
    height: 800
    visible: true
    title: qsTr("hello, world")

    Desk{
        id:desk
        onNowPlayChanged: {
            if(desk.nowPlay===p1.ref){
                p1b.visible=true
                p2b.visible=false
                p3b.visible=false
            }
            else if(desk.nowPlay===p2.ref){
                p2b.visible=true
                p1b.visible=false
                p3b.visible=false
            }
            else{
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
                n1=p1.getHandSize()
                n2=p2.getHandSize()
                n3=p3.getHandSize()
                p1d.visible=true
                p2d.visible=true
                p3d.visible=true
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
            if(desk.landlord===1){
                desk.num[0]=p1.ref
                p1.toushCard(desk.getLandlordHand());
                n1=p1.getHandSize();
            }
            else if(desk.landlord===2){
                desk.num[0]=p2.ref
                p2.toushCard(desk.getLandlordHand());
                n2=p2.getHandSize();
            }
            else{
                desk.num[0]=p3.ref
                p3.toushCard(desk.getLandlordHand());
                n3=p3.getHandSize();
            }

            desk.nowPlay=desk.landlord
        }
        onOverChanged: {
            n1=0
            n2=0
            n3=0
            p1b.visible=false
            p2b.visible=false
            p3b.visible=false
            p1d.visible=false
            p2d.visible=false
            p3d.visible=false
            if(over===landlord){
                if(landlord===p1.ref){
                    p1win.visible=true
                    p2fail.visible=true
                    p3fail.visible=true
                }
                else if(landlord===p2.ref){
                    p1fail.visible=true
                    p2win.visible=true
                    p3fail.visible=true
                }
                else{
                    p1fail.visible=true
                    p2fail.visible=true
                    p3win.visible=true
                }
            }
            else{
                if(landlord===p1.ref){
                    p1fail.visible=true
                    p2win.visible=true
                    p3win.visible=true
                }
                else if(landlord===p2.ref){
                    p1win.visible=true
                    p2fail.visible=true
                    p3win.visible=true
                }
                else{
                    p1win.visible=true
                    p2win.visible=true
                    p3fail.visible=true
                }
            }
            countdownTimer1.start()
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

    property int n1: p1.getHandSize()
    property int n2: p2.getHandSize()
    property int n3: p3.getHandSize()
    property int n2m: 3
    property int n3m: 3
    property int countdownTime: 15
    property int countdownTime1: 5
    property string source1: "qrc:/images/"
    property string source2: ".png"

    Timer{
        id:countdownTimer
        interval: 1000
        repeat: true
        running: false
        onTriggered: {
            if(countdownTime>0){
                countdownTime--
            }
            else{
                countdownTimer.stop()
                if(desk.nowPlay===p1.ref){
                    desk.nowPlay=p2.ref
                    countdownTime=15
                    if(desk.num[0]!==0&&desk.num[0]!==p2.ref){
                        p1time.visible=false
                        p2time.visible=true
                        countdownTimer.start()
                    }
                }
                else if(desk.nowPlay===p2.ref){
                    desk.nowPlay=p3.ref
                    countdownTime=15
                    if(desk.num[0]!==0&&desk.num[0]!==p3.ref){
                        p2time.visible=false
                        p3time.visible=true
                        countdownTimer.start()
                    }
                }
                else{
                    desk.nowPlay=p1.ref
                    countdownTime=15
                    if(desk.num[0]!==0&&desk.num[0]!==p1.ref){
                        p3time.visible=false
                        p1time.visible=true
                        countdownTimer.start()
                    }
                }
            }
        }
    }

    Timer{
        id:countdownTimer1
        interval: 1000
        repeat: true
        running: false
        onTriggered: {
            if(countdownTime1>0){
                countdownTime1--
            }
            else{
                countdownTimer1.stop()
                countdownTime1=5
                p1win.visible=false
                p1fail.visible=false
                p2win.visible=false
                p2fail.visible=false
                p3win.visible=false
                p3fail.visible=false
                desk.setAlready(-3)
                desk.mark=0;
                desk.temLandlord=0
                p1c.color="#FFFF00"
                p2c.color="#FFFF00"
                p3c.color="#FFFF00"
                p1cc.enabled=true
                p2cc.enabled=true
                p3cc.enabled=true
                p1c.visible=true
                p2c.visible=true
                p3c.visible=true
                desk.setTemLibrary()
            }
        }
    }



    Column{
        anchors.centerIn: parent
        spacing: 40

    Column{
        spacing: 20
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
                                desk.nowPlay=p2.ref
                                countdownTimer.stop()
                                countdownTime=15
                                p1time.visible=false
                                if(desk.num[0]!==0&&desk.num[0]!==p2.ref){
                                    p2time.visible=true
                                    countdownTimer.start()
                                }
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
                            if(p1.getHandSize()){
                            n1=p1.getHandSize()
                            desk.nowPlay=p2.ref
                            countdownTimer.stop()
                            countdownTime=15
                            p1time.visible=false
                            if(desk.num[0]!==0&&desk.num[0]!==p2.ref){
                                p2time.visible=true
                                countdownTimer.start()
                            }

                            }
                            else{
                                desk.over=p1.ref
                            }
                        }
                    }
                }
            }
            Rectangle{
                id:p1time
                width: 20;height: 20;color: "grey"
                visible: false
                Text {
                    anchors.centerIn: parent
                    text: countdownTime
                }
            }
        }

        Row{
            id:p1win
            visible: false
            spacing: 10
            Rectangle{
                width: 120;height: 30;color: "transparent"
                Text{
                    anchors.centerIn: parent
                    text: qsTr("你赢了！")
                    color: "red"
                    font.pointSize: 20
            }
            }
        }

        Row{
            id:p1fail
            visible: false
            spacing: 10
            Rectangle{
                width: 120;height: 30;color: "transparent"
                Text{
                    anchors.centerIn: parent
                    text: qsTr("你输了！")
                    color: "red"
                    font.pointSize: 20
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
                            desk.mark=3-index
                            if(desk.mark!==3){
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
                id:p1cc
                onTapped: {
                    parent.color="grey"
                    desk.setAlready(1)
                    enabled=false
                }
            }
        }

    Row{
        spacing: 10
        id:p1d
        Repeater{
            model: n1
            delegate: Rectangle{
                width: 60;height: 80;color: "grey"
                property bool isRed:false
                Image {
                    anchors.fill: parent
                    source: source1+p1.getCardNumber(index)+source2
                }

                TapHandler{
                    onTapped: {
                        p1.select(index+1)
                        parent.color=isRed?"grey":"red"
                        parent.y=isRed?parent.y+10:parent.y-10
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
                                desk.nowPlay=p3.ref
                                countdownTimer.stop()
                                countdownTime=15
                                p2time.visible=false
                                if(desk.num[0]!==0&&desk.num[0]!==p3.ref){
                                    p3time.visible=true
                                    countdownTimer.start()
                                }
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
                        p2.usingCard(desk.getNum())
                        if(p2.pushCard(desk.getNum())){
                            desk.num=p2.getNum1()
                            if(p2.getHandSize()){
                            n2=p2.getHandSize()
                            desk.nowPlay=p3.ref
                            countdownTimer.stop()
                            countdownTime=15
                            p2time.visible=false
                            if(desk.num[0]!==0&&desk.num[0]!==p3.ref){
                                    p3time.visible=true
                                    countdownTimer.start()
                                }
                            }
                            else{
                                desk.over=p2.ref
                            }
                        }
                    }
                }
            }
            Rectangle{
                id:p2time
                width: 20;height: 20;color: "grey"
                visible: false
                Text {
                    anchors.centerIn: parent
                    text: countdownTime
                }
            }

        }
        Row{
            id:p2win
            visible: false
            spacing: 10
            Rectangle{
                width: 120;height: 30;color: "transparent"
                Text{
                    anchors.centerIn: parent
                    text: qsTr("你赢了！")
                    color: "red"
                    font.pointSize: 20
            }
            }
        }

        Row{
            id:p2fail
            visible: false
            spacing: 10
            Rectangle{
                width: 120;height: 30;color: "transparent"
                Text{
                    anchors.centerIn: parent
                    text: qsTr("你输了！")
                    color: "red"
                    font.pointSize: 20
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
                            desk.mark=3-index
                            if(desk.mark!==3){
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
                id:p2cc
                onTapped: {
                    parent.color="grey"
                    desk.setAlready(1)
                    enabled=false
                }
            }
        }
    Row{
        spacing: 10
        id:p2d
        Repeater{
            model: n2
            delegate: Rectangle{
                width: 60;height: 90;color: "grey"
                property bool isRed:false
                Image {
                    anchors.fill: parent
                    source: source1+p2.getCardNumber(index)+source2
                }

                TapHandler{
                    onTapped: {
                        p2.select(index+1)
                        parent.color=isRed?"grey":"red"
                        parent.y=isRed?parent.y+10:parent.y-10
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
                                desk.nowPlay=p1.ref
                                countdownTimer.stop()
                                countdownTime=15
                                p3time.visible=false
                                if(desk.num[0]!==0&&desk.num[0]!==p1.ref){
                                    p1time.visible=true
                                    countdownTimer.start()
                                }
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
                        p3.usingCard(desk.getNum())
                        if(p3.pushCard(desk.getNum())){
                            desk.num=p3.getNum1()
                            if(p3.getHandSize()){
                            n3=p3.getHandSize()
                            desk.nowPlay=p1.ref
                            countdownTimer.stop()
                            countdownTime=15
                            p3time.visible=false
                            if(desk.num[0]!==0&&desk.num[0]!==p1.ref){
                                    p1time.visible=true
                                    countdownTimer.start()
                                }
                            }
                            else{
                                desk.over=p3.ref
                            }
                        }
                    }
                }
            }
            Rectangle{
                id:p3time
                width: 20;height: 20;color: "grey"
                visible: false
                Text {
                    anchors.centerIn: parent
                    text: countdownTime
                }
            }

        }

        Row{
            id:p3win
            visible: false
            spacing: 10
            Rectangle{
                width: 120;height: 30;color: "transparent"
                Text{
                    anchors.centerIn: parent
                    text: qsTr("你赢了！")
                    color: "red"
                    font.pointSize: 20
            }
            }
        }

        Row{
            id:p3fail
            visible: false
            spacing: 10
            Rectangle{
                width: 120;height: 30;color: "transparent"
                Text{
                    anchors.centerIn: parent
                    text: qsTr("你输了！")
                    color: "red"
                    font.pointSize: 20
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
                        p3a.visible=false
                        desk.landlord=desk.temLandlord
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
                            desk.mark=3-index
                            desk.landlord=desk.temLandlord
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
                id:p3cc
                onTapped: {
                    parent.color="grey"
                    desk.setAlready(1)
                    enabled=false
                }
            }
        }
    Row{
        spacing: 10
        id:p3d
        Repeater{
            model: n3
            delegate: Rectangle{
                width: 60;height: 80;color: "grey"
                property bool isRed:false
                Image {
                    anchors.fill: parent
                    source: source1+p3.getCardNumber(index)+source2
                }

                TapHandler{
                    onTapped: {
                        p3.select(index+1)
                        parent.color=isRed?"grey":"red"
                        parent.y=isRed?parent.y+10:parent.y-10
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
