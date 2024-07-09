import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QmlPeople
import QmlDesk
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
            visible: ture
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
                        text: qsTr("房主开始")
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
                    text:qsTr("游客开始")
                    font.pointSize: 30
                    font.family: "Arial"
                    font.weight: Font.Bold
                    anchors.centerIn: parent
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
                    playwindow.visible=false
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



// Rectangle{
//     id:playwindow
//     width:1400
//     height:800
//     visible: false
//     anchors.fill:parent
//     radius:10

//     Image {
//         source: "qrc:/images/background4"
//         anchors.fill:parent
//     }

//     Button{
//         id:setbotton1
//         background: Rectangle{
//             color:"transparent"
//         }
//         width:80
//         height: 80
//         Image {
//             source: "qrc:/images/settings"
//             anchors.fill:setbotton
//         }
//         anchors.right: playwindow.right
//         anchors.top:playwindow.top
//         anchors.margins: 70
//         TapHandler{
//             onTapped: {
//                 settingwindow.visible=true
//             }
//         }
//     }

property int n: 0
property int n1: 0
// property int n2: p2.getHandSize()
// property int n3: p3.getHandSize()
// property int n2m: 3
// property int n3m: 3
property int countdownTime: 15
property int countdownTime1: 5
property string source1: "qrc:/images/"
property string source2: ".png"

Rectangle{
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
       }
       People{
           id:p2
       }

       Desk{
               id:desk
               onNowPlayChanged: {
                   if(desk.nowPlay===p.ref){
                       pb.visible=true
                   }
                   else if(desk.nowPlay===p2.ref){
                   }
                   else{
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
                       // p2c.visible=false
                       // p3c.visible=false
                       playcolumn.visible=true
                       markrow.visible=true
                       cardrow.visible=true
                       n=p.getHandSize()
                       // n2=p2.getHandSize()
                       // n3=p3.getHandSize()
                       // p2d.visible=truea
                       // p3d.visible=true
                  }
               }
               onMarkChanged: {
                   if(desk.mark===3){
                       markrow.visible=false
                       // p2a.visible=false
                       // p3a.visible=false
                       desk.landlord=desk.temLandlord
                       //desk.nowPlay=desk.landlord
                   }
               }
               onLandlordChanged: {
                   if(desk.landlord===1){
                       desk.num[0]=p.ref
                       p.toushCard(desk.getLandlordHand());
                       n=p.getHandSize();
                   }
                   else if(desk.landlord===2){
                       // desk.num[0]=p2.ref
                       // p2.toushCard(desk.getLandlordHand());
                       // n2=p2.getHandSize();
                   }
                   else{
                       // desk.num[0]=p3.ref
                       // p3.toushCard(desk.getLandlordHand());
                       // n3=p3.getHandSize();
                   }

                   desk.nowPlay=desk.landlord
               }
               onOverChanged: {
                   playrow.visible=false
                   // p2b.visible=false
                   // p3b.visible=false
                   cardrow.visible=false
                   // p2d.visible=false
                   // p3d.visible=false
                   if(over===landlord){
                       if(landlord===p.ref){
                           win.visible=true
                           // p2fail.visible=true
                           // p3fail.visible=true
                       }
                       else if(landlord===p2.ref){
                           fail.visible=true
                           // p2win.visible=true
                           // p3fail.visible=true
                       }
                       else{
                           fail.visible=true
                           // p2fail.visible=true
                           // p3win.visible=true
                       }
                   }
                   else{
                       if(landlord===p.ref){
                           fail.visible=true
                           // p2win.visible=true
                           // p3win.visible=true
                       }
                       // else if(landlord===p2.ref){
                       //     p1win.visible=true
                       //     p2fail.visible=true
                       //     p3win.visible=true
                       // }
                       // else{
                       //     p1win.visible=true
                       //     p2win.visible=true
                       //     p3fail.visible=true
                       // }
                   }
                   countdownTimer1.start()
               }
           }
        //    Timer{
        //        id:countdownTimer
        //        interval: 1000
        //        repeat: true
        //        running: false
        //        onTriggered: {
        //            if(countdownTime>0){
        //                countdownTime--
        //            }
        //            else{
        //                countdownTimer.stop()
        //                if(desk.nowPlay===p1.ref){
        //                    desk.nowPlay=p2.ref
        //                    countdownTime=15
        //                    if(desk.num[0]!==0&&desk.num[0]!==p2.ref){
        //                        p1time.visible=false
        //                        p2time.visible=true
        //                        countdownTimer.start()
        //                    }
        //                }
        //                else if(desk.nowPlay===p2.ref){
        //                    desk.nowPlay=p3.ref
        //                    countdownTime=15
        //                    if(desk.num[0]!==0&&desk.num[0]!==p3.ref){
        //                        p2time.visible=false
        //                        p3time.visible=true
        //                        countdownTimer.start()
        //                    }
        //                }
        //                else{
        //                    desk.nowPlay=p1.ref
        //                    countdownTime=15
        //                    if(desk.num[0]!==0&&desk.num[0]!==p1.ref){
        //                        p3time.visible=false
        //                        p1time.visible=true
        //                        countdownTimer.start()
        //                    }
        //                }
        //            }
        //        }n
        // }

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
                       // p2win.visible=false
                       // p2fail.visible=false
                       // p3win.visible=false
                       // p3fail.visible=false
                       desk.setAlready(-1)
                       desk.mark=0;
                       desk.temLandlord=0
                       readyrow.visible=true
                       // p2c.color="#FFFF00"
                       // p3c.color="#FFFF00"
                       readybutton.enabled=true
                       // p2cc.enabled=true
                       // p3cc.enabled=true
                       // p2c.visible=true
                       // p3c.visible=true
                       desk.setTemLibrary()
                       n1=0
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
                           source: source1+p.getTemNumber(index)+source2
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
           height: 200
           width: parent.width
           spacing:100

           RoundButton{
               id:readybutton
               width: 200
               height: 70
               anchors.top: parent.top
               anchors.horizontalCenter: parent.horizontalCenter
               Image {
                   source: "qrc:/images/nonbutton"
                   anchors.fill:parent
               }
               Text {
                   text: qsTr("ready")
                   anchors.centerIn: parent
                   font.pointSize: 24
               }
               enabled: true
                 TapHandler{
                     onTapped: {
                         parent.enabled=false
                         desk.setAlready(1)
                         //playcolumn.visible=true
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
                             n1=desk.num[3]
                             n1=n1-1
                             n1=n1+1
                             if(p.getHandSize()){
                                 n=p.getHandSize()
                                 desk.nowPlay=p.ref
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
}
