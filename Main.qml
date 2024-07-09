import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QmlPeople
import QmlDesk
import Qtserver
import Qtsocket
import QtMultimedia

ApplicationWindow {
    width:1400
    height: 800
    visible: true
    title: qsTr("🐮🐮斗地主")
    id:mainwindow

    Rectangle{
        id:gamewindow
        width:1300
        height:800
        visible: true
        anchors.fill:parent
        radius:10
        Image {
            id: mainbackground
            source: "qrc:/images/background1"
            anchors.fill:parent
        }

        Text {
            id: gamename
            visible: true
            text: "🐮🐮斗地主"
            color: "black"
            font.pointSize: 70
            font.family: "Arial"
            anchors.top: mainwindow.top
            anchors.topMargin: 50
            anchors.horizontalCenter: gamewindow.horizontalCenter
        }

        Rectangle{
            id:buttonarea
            width :400
            height:400
            color:"transparent"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 50
            anchors.horizontalCenter: parent.horizontalCenter

            Column{                         //布局管理器
                         anchors.centerIn: parent
                         spacing: 40

                             RoundButton{
                             id:gamestar
                                width: 300
                                height: 80
                                 radius:10
                                 background: Rectangle{
                                     color:"transparent"
                                 }
                                 Image {
                                     id: gamestarbutton
                                    source: "qrc:/images/gamesetting1"
                                     anchors.fill: parent
                                 }
                                 TapHandler{
                                     onTapped: {
                                         gamewindow.visible=false
                                         gamemodechose.visible=true
                                     }
                                 }


                             }

                              RoundButton{
                                  radius:10
                                  width: 300
                                  height:80
                                  background: Rectangle{
                                      color:"transparent"
                                  }
                                  Image {
                                      id: gamebcakbutton
                                      source: "qrc:/images/gamesetting2"
                                       anchors.fill:parent
                                  }
                                 TapHandler{
                                     onTapped:{
                                        Qt.quit()
                                     }
                                 }
                                }

                              RoundButton{
                                 radius:10
                                   width: 300
                                  height: 80
                                  background: Rectangle{
                                      color:"transparent"
                                  }
                                  Image {
                                       id: gamesettings
                                       source: "qrc:/images/gamesetting3"
                                       anchors.fill:parent
                                   }
                                  TapHandler{
                                      onTapped: {
                                          settingwindow.visible=true
                                      }
                                  }
                               }
                             }
                    }

 }//主界面

Rectangle{

        id:gamemodechose
        width:1400
        height:800
        visible: false
        anchors.fill:parent
        radius:10

        Image {
            id: gamemodechosebackground
            source: "qrc:/images/background2"
            anchors.fill: parent
        }

        Row{                        //房主开始或者游客开始
            anchors.centerIn: parent
            spacing: 200

            RoundButton{
                id:hoster
                width:200
                height: 70
                radius: 10
                    Image{
                        source: "qrc:/images/nonbutton"
                        anchors.fill:parent
                    }
                    Text {                 //游戏标题
                        text: qsTr("人机对战")
                        font.pointSize: 30
                        font.family: "Arial"
                        font.weight: Font.Bold
                        anchors.centerIn: parent
                }
                    background: Rectangle{
                        color:"transparent"
                    }
                    TapHandler{
                        onTapped: {
                            playwindow.visible=true
                            gamemodechose.visible=false
                        }
                    }
            }

            RoundButton{
                id:vistor
                width:200
                height: 70
                radius:10
                background: Rectangle{
                    color:"transparent"
                }
                Image {
                    source:"qrc:/images/nonbutton"
                    anchors.fill:parent
                }
                Text {
                    text:qsTr("联机")
                    font.pointSize: 30
                    font.family: "Arial"
                    font.weight: Font.Bold
                    anchors.centerIn: parent
                }
                TapHandler{
                    onTapped: {
                        vistorwindow.visible=true
                        gamemodechose.visible=false
                    }
                }
            }

            RoundButton{
                id:getback
                width:200
                height: 70
                radius: 10
                background: Rectangle{
                    color:"transparent"
                }
                    Image {
                        source: "qrc:/images/nonbutton"
                        anchors.fill:parent
                    }
                    Text {                 //游戏标题
                        text: qsTr("返回主菜单")
                        font.pointSize: 30
                        font.family: "Arial"
                        font.weight: Font.Bold
                        anchors.centerIn: parent
                }
                    TapHandler{
                        onTapped: {
                            gamemodechose.visible=false
                            gamewindow.visible=true
                        }
                    }
            }
        }

        Button{
            id:setbotton
            background: Rectangle{
                color:"transparent"
            }
            width:80
            height: 80
            Image {
                source: "qrc:/images/settings"
                anchors.fill:setbotton
            }
            anchors.right: gamemodechose.right
            anchors.top:gamemodechose.top
            anchors.margins: 70
            TapHandler{
                onTapped: {
                    settingwindow.visible=true

                }
            }
        }
}

Rectangle{
    id:settingwindow
    width:700
    height:700
    visible: false
    anchors.centerIn: parent
    Image {
        source: "qrc:/images/background2"
        anchors.fill:settingwindow
    }

    Row{
        anchors.centerIn: parent
        spacing: 100
        Switch{
            id:backmusic
            transform: Scale{
                xScale: 2
                yScale: 2
            }

            text:qsTr("背景音乐开/关")
            font.pointSize: 10
            TapHandler{
                onTapped: {
                    backmusicbutton.play()
                }
            }
        }

        Switch{
                id:gamemusic
                transform: Scale{
                    xScale: 2
                    yScale: 2
                }
                text: qsTr("游戏音乐开/关")
                font.pointSize: 10
                font.family: "Arial"
                font.weight: Font.Bold
                TapHandler{
                    onTapped: {
                       gamemusicbutton.play()
                    }
                }
        }

    }
    SoundEffect{
              id:backmusicbutton
              source: "qrc:/music/backgroundMusic.mp3"
    }
    SoundEffect{
        id:gamemusicbutton
        source:"qrc:/music/gameMusic.mp3"
    }

    RoundButton{
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 100
         anchors.horizontalCenter: settingwindow.horizontalCenter
        id:getback2
        width:200
        height: 70
        radius: 10
        background: Rectangle{
            color:"transparent"
        }
            Image {
                source: "qrc:/images/nonbutton"
                anchors.fill:parent
            }
            Text {                 //游戏标题
                text: qsTr("返回主菜单")
                font.pointSize: 20
                font.family: "Arial"
                font.weight: Font.Bold
                anchors.centerIn: parent
        }
            TapHandler{
                onTapped: {
                    settingwindow.visible=false
                    gamemodechose.visible=false
                    gamewindow.visible=true
                }
            }
    }

    RoundButton{
        id:closewindow
        width:50
        height:50
        background: Rectangle{
            color:"transparent"
        }
        Image {
            source: "qrc:/images/close"
            anchors.fill:parent
        }
        anchors.right: settingwindow.right
        anchors.top:settingwindow.top
        anchors.margins: 10
        TapHandler{
            onTapped: {
                settingwindow.visible=false
            }
        }
    }

}

property int n: 0
property int n1: 0

// property int n2: p2.getHandSize()
// property int n3: p3.getHandSize()
// property int n2m: 3
// property int n3m: 3

property int countdownTime: 2
property int countdownTime1: 5
property string source1: "qrc:/images/"
property string source2: ".png"



Rectangle{                     //hosterwidnow
       id:playwindow
       width: 1400
       height: 700
       visible: false
       anchors.fill:parent

       Image {
           source: "qrc:/images/background5"
           anchors.fill:parent
       }
       People{
           id:p
           ref:1
       }

       People{
           id:p1
           ref:2
       }
       People{
           id:p2
           ref: 3
       }

       Desk{
               id:desk
               onNowPlayChanged: {
                   if(desk.nowPlay===p.ref){
                       nult.visible=false
                       playrow.visible=true
                   }
                   else{
                       nult.visible=true
                       playrow.visible=false
                       countdownTimer.start()
                   }
               }
               onAlreadyChanged: {
                   if(desk.already===1){
                       desk.dealCard()
                       p.setHand(desk.getP1Hand())
                       p.sortHand()
                       p1.setHand(desk.getP2Hand())
                       p1.sortHand()
                       p2.setHand(desk.getP3Hand())
                       p2.sortHand()
                       readyrow.visible=false
                       playcolumn.visible=true
                       markrow.visible=true
                       cardrow.visible=true
                       n=p.getHandSize()
                  }
               }
               onMarkChanged: {
                   if(desk.mark===3){
                       markrow.visible=false
                       desk.landlord=desk.temLandlord
                   }
               }
               onLandlordChanged: {
                   if(desk.landlord===1){
                       desk.num[0]=p.ref
                       p.toushCard(desk.getLandlordHand());
                       n=p.getHandSize();
                   }
                   desk.nowPlay=desk.landlord
               }

               onOverChanged: {
                   playrow.visible=false
                   cardrow.visible=false
                       if(landlord===p.ref){
                           win.visible=true
                       }
                       else{
                           fail.visible=true
                       }
                   countdownTimer1.start()
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
                       win.visible=false
                       fail.visible=false
                       desk.setAlready(-1)
                       desk.mark=0;
                       desk.temLandlord=0
                       readyrow.visible=true
                       readybutton.enabled=true
                       desk.setTemLibrary()
                       n1=0
                   }
               }
           }

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
                       countdownTime=2
                       if(desk.nowPlay===p1.ref){
                           if(desk.num[0]!==p1.ref){
                               if(desk.num[1]!==1&&desk.num[1]!==2&&desk.num[1]!==3){
                                   desk.nowPlay=p2.ref
                               }
                               else{
                                   p1.mplay(desk.getNum())
                                   if(p1.pushCard(desk.getNum())){
                                    desk.num=p1.getNum1()
                                    desk.setTem(p1.getTem())
                                    n1=desk.num[3]
                                    n1=n1-1
                                    n1=n1+1
                                   }
                                   if(p1.getHandSize()){
                                   desk.nowPlay=p2.ref
                                   }
                                   else{
                                       desk.over=p1.ref
                                   }
                               }
                           }
                           else{
                               p1.select(p1.getHandSize()-1)
                               p1.usingCard(desk.getNum())
                               desk.num=p1.getNum1()
                               desk.setTem(p1.getTem())
                               n1=desk.num[3]
                               n1=n1-1
                               n1=n1+1
                               if(p1.getHandSize()){
                               desk.nowPlay=p2.ref
                               }
                               else{
                                   desk.over=p1.ref
                               }
                           }
                       }
                       else if(desk.nowPlay===p2.ref){
                           if(desk.num[0]!==p2.ref){
                               if(desk.num[1]!==1&&desk.num[1]!==2&&desk.num[1]!==3){
                                   desk.nowPlay=p.ref
                               }
                               else{
                                   p2.mplay(desk.getNum())
                                   if(p2.pushCard(desk.getNum())){
                                       desk.num=p2.getNum1()
                                       desk.setTem(p2.getTem())
                                       n1=desk.num[3]
                                       n1=n1-1
                                       n1=n1+1
                                   }
                                   if(p2.getHandSize()){
                                   desk.nowPlay=p.ref
                                   }
                                   else{
                                       desk.over=p2.ref
                                   }
                               }
                           }
                           else{
                               p2.select(p2.getHandSize()-1)
                               p2.usingCard(desk.getNum())
                               desk.num=p2.getNum1()
                               desk.setTem(p2.getTem())
                               n1=desk.num[3]
                               n1=n1-1
                               n1=n1+1
                               if(p2.getHandSize()){
                               desk.nowPlay=p.ref
                               }
                               else{
                                   desk.over=p2.ref
                               }
                           }
                       }
                   }
               }
           }

           Row{
               id:showcard
               anchors.top: parent.top
               anchors.horizontalCenter: parent.horizontalCenter
               height: 150
               width: parent.width
               spacing: -15
               Repeater{
                   model: n1
                   delegate: Rectangle{
                       width: 80
                       height: 130
                       color: "transparent"
                       Image {
                           anchors.fill: parent
                           source: source1+desk.getTem(index)+source2
                       }
                   }
                   onModelChanged: {
                       parent.update()
                   }
               }
           }

       Row{
           id:readyrow
           anchors.bottom: parent.bottom
           anchors.horizontalCenter: parent.horizontalCenter
           anchors.bottomMargin: 150
           height: 200
           width: parent.width
           spacing:100

           RoundButton{
               id:readybutton
               width: 300
               height: 100
               anchors.top: parent.top
               anchors.horizontalCenter: parent.horizontalCenter
               Image {
                   source: "qrc:/images/nonbutton"
                   anchors.fill:parent
               }
               Text {
                   text: qsTr("准备")
                   anchors.centerIn: parent
                   font.pointSize: 30
               }
               enabled: true
                 TapHandler{
                     onTapped: {
                         parent.enabled=false
                         desk.setAlready(1)
                     }
                 }
           }
       }

           Column{
               id:playcolumn
               visible: false
               width: parent.width
               height: 300
               anchors.bottom: parent.bottom
               anchors.horizontalCenter: parent.horizontalCenter
               spacing: 15
               Row{
                   id:markrow
                   width: parent.width
                   height: 90
                   visible: true
                   spacing: 20

                   RoundButton{
                     width: 100
                     height: 50
               Image {
                   source: "qrc:/images/nonbutton"
                   anchors.fill:parent
               }

               Text {
                   text: qsTr("不叫")
                   anchors.centerIn: parent
                   font.pointSize: 24
               }

               enabled: true
                 TapHandler{
                     onTapped: {
                         markrow.visible=false
                         playrow.visible=true
                     }
                 }
           }

                   Repeater{
                        model:3
                        delegate: RoundButton{
                        width: 100;height: 50
                        Image {
                            source: "qrc:/images/nonbutton"
                            anchors.fill:parent
                        }

                        Text{
                            anchors.centerIn: parent
                            text: 3-index+"分"
                            font.pointSize: 24
                        }

                         TapHandler{
                            onTapped: {
                                desk.temLandlord=p.ref
                                markrow.visible=false
                                playrow.visible=true
                                desk.mark=3-index
                             }
                         }
                    }
           }
               }

               Row{
                   id:nult
                   width: parent.width
                   height: 90
                   visible: false
               }

               Row{
                   id:playrow
                   width: parent.width
                   height: 90
                   visible: false
                   spacing: 20
                   RoundButton{
                     width: 100
                     height: 50
               Image {
                   source: "qrc:/images/nonbutton"
                   anchors.fill:parent
               }
               Text {
                   text: qsTr("不出")
                   anchors.centerIn: parent
                   font.pointSize: 24
               }
               enabled: true
                 TapHandler{
                     onTapped: {
                         if(desk.num[0]!==p.ref){
                             desk.nowPlay=2
                         }
                     }
                 }
           }
                   RoundButton{
                     width: 100
                     height: 50
               Image {
                   source: "qrc:/images/nonbutton"
                   anchors.fill:parent
               }
               Text {
                   text: qsTr("出牌")
                   anchors.centerIn: parent
                   font.pointSize: 24
               }
               enabled: true
                 TapHandler{
                     onTapped: {
                         p.usingCard(desk.getNum())
                         if(p.pushCard(desk.getNum())){
                             desk.num=p.getNum1()
                             desk.setTem(p.getTem())
                             n1=desk.num[3]
                             n1=n1-1
                             n1=n1+1
                             if(p.getHandSize()){
                                 n=p.getHandSize()
                                 desk.nowPlay=p1.ref
                             }
                             else{
                                 desk.over=p.ref
                             }
                         }
                     }
                 }
           }
               }

               Row{
                   id:cardrow
                   visible: true
                   spacing: -15
                   width: parent.width
                   height: 160

                   Repeater{
                        model:n
                        delegate: Rectangle{
                        width: 80;height: 130
                        property bool isclicked: false
                        Image {
                            source: source1+p.getCardNumber(index)+source2
                            anchors.fill:parent
                        }
                         TapHandler{
                            onTapped: {
                                p.select(index+1)
                                parent.y=isclicked?parent.y+10:parent.y-10
                                isclicked=!isclicked
                                 }
                             }
                         }
                        onModelChanged: {
                            parent.update()
                        }
                    }
               }

               Rectangle{
                   id:win
                   visible: false
                   anchors.centerIn: parent
                   color:"transparent"
                   width: 300
                   height: 100
                   Text{
                       text: qsTr("你赢了！")
                       font.pointSize: 60
                       anchors.centerIn: parent
                       color: "red"
                   }
               }

               Rectangle{
                   id:fail
                   visible: false
                   anchors.centerIn: parent
                   color:"transparent"
                   width: 300
                   height: 100
                   Text{
                       text: qsTr("你输了！")
                       font.pointSize: 60
                       anchors.centerIn: parent
                       color: "red"
                   }
               }
       }

}

Rectangle{                                    //游客界面
    id:vistorwindow
    width: 1400
    height: 700
    visible: false
    anchors.fill:parent
    Image {
        source: "qrc:/images/background5"
        anchors.fill:parent
    }
Row{
    anchors.centerIn: parent
    spacing:100
    RoundButton{
        id:readybutton2
        width: 300
        height: 100
        Image {
            source: "qrc:/images/nonbutton"
            anchors.fill:parent
        }
        Text {
            text: qsTr("准备")
            anchors.centerIn: parent
            font.pointSize: 30
        }
        enabled: true
          TapHandler{
              onTapped: {
                  parent.enabled=false
                  tcpfile.visible=true
                  //playcolumn.visible=true
              }
          }
    }
    RoundButton{
        id:getback3
        width:300
        height:100
        radius: 10
        background: Rectangle{
            color:"transparent"
        }
            Image {
                source: "qrc:/images/nonbutton"
                anchors.fill:parent
            }
            Text {                 //游戏标题
                text: qsTr("返回主菜单")
                font.pointSize: 30
                font.family: "Arial"
                anchors.centerIn: parent
        }

            TapHandler{
                onTapped: {
                    vistorwindow.visible=false
                    gamewindow.visible=true
                }
            }
    }
}
}
Server{
    id:qtserver1
    onValueChanged:{
        if(qtserver1.m_Value===2){
            playcard.visible = true
            tcpfile.visible = false
        }
        if(qtserver1.m_Value===1){
            desk.setAlready(1);
            qtserver1.setValue(0)
        }
    }
}
Socket{
    id:qtsocket1
    onValueChanged: {
        if(qtsocket1.m_Value===1)
        {
            playcard.visible = true
            tcpfile.visible = false
        }
        if(qtsocket1.m_Value===3)
        {
            send_data1()
        }
    }
}
Rectangle{
    Rectangle{
        width:1700
        height:800
        color:"#424242"
        id:tcpfile
        visible:false
        Column{
            id:column1
            spacing: 5
            anchors.centerIn: parent
            Button{
                text:qsTr("server")
                onClicked:{
                    server1.visible = true
                    socket1.visible = false
                    column1.visible = false
                }
            }
            Button{
                text:qsTr("socket")
                onClicked:{
                    server1.visible = false
                    socket1.visible = true
                    column1.visible = false
                }
            }
        }
        Column{
            id:server1;visible: false
            anchors.centerIn: parent;spacing: 5
            Row{
                spacing:5
                Rectangle{
                    clip:true
                    width:200;height: 30
                    color:"white"
                    TextInput{
                        text:qsTr("127.0.0.1")
                        id:textinput1
                        width:200;height:30
                        font.pointSize: 15
                    }
                }
                Rectangle{
                    width:100;height:30
                    Button{
                        width:100;height:30
                        text:qsTr("buildserver")
                        onClicked: {
                            qtserver1.listen_to_client(textinput1.text,textinput2.text)
                        }
                    }

                }
            }
            Row{
                spacing:5
                Rectangle{
                    clip:true;width:200;height: 30
                    color:"white"
                    TextInput{
                        text:qsTr("10058")
                        id:textinput2
                        width:200;height:30
                        font.pointSize: 15
                    }
                }
                Rectangle{
                    width:100;height:30
                    Button{
                        width:100;height:30
                        text:qsTr("disconnect")
                    }
                }
            }
        }
        Column{
            id:socket1;visible: false
            anchors.centerIn: parent;spacing: 5
            Row{
                spacing:5
                Rectangle{
                    clip:true
                    width:200;height: 30
                    color:"white"
                    TextInput{
                        text:qsTr("127.0.0.1")
                        id:textinput3
                        width:200;height:30
                        font.pointSize: 15
                    }
                }
                Rectangle{
                    width:100;height:30
                    Button{
                        width:100;height:30
                        text:qsTr("connect")
                        onClicked: {
                            qtsocket1.new_connect(textinput3.text,textinput4.text)
                        }
                    }
                }
            }
            Row{
                spacing:5
                Rectangle{
                    clip:true
                    width:200;height: 30
                    color:"white"
                    TextInput{
                        text:qsTr("10058")
                        id:textinput4
                        width:200;height:30
                        font.pointSize: 15
                    }
                }
                Rectangle{
                    width:100;height:30
                    Button{
                        width:100;height:30
                        text:qsTr("disconnect")
                    }
                }
            }
        }
    }
}
}

