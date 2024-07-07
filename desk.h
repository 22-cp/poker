#pragma once

#include "people.h"

class desk : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int nowPlay READ getNowPlay WRITE setNowPlay NOTIFY nowPlayChanged FINAL)
    Q_PROPERTY(std::vector<int> num READ getNum WRITE setNum NOTIFY numChanged FINAL)
    Q_PROPERTY(int landlord READ getLandlord WRITE setLandlord NOTIFY landlordChanged FINAL)
    Q_PROPERTY(int already READ getAlready WRITE setAlready NOTIFY alreadyChanged FINAL)
    Q_PROPERTY(
        int temLandlord READ getTemLandlord WRITE setTemLandlord NOTIFY temLandlordChanged FINAL)
    Q_PROPERTY(int mark READ getMark WRITE setMark NOTIFY markChanged FINAL)
    Q_PROPERTY(int over READ getOver WRITE setOver NOTIFY overChanged FINAL)

public:
    desk();

    Q_INVOKABLE int getNumRef();
    Q_INVOKABLE void dealCard();
    Q_INVOKABLE std::vector<people::poker> getP1Hand();
    Q_INVOKABLE std::vector<people::poker> getP2Hand();
    Q_INVOKABLE std::vector<people::poker> getP3Hand();
    Q_INVOKABLE std::vector<people::poker> getLandlordHand();
    Q_INVOKABLE void setTemLibrary();

    void setTemLandlord(int ref);
    int getTemLandlord();
    void setMark(int n);
    int getMark();
    void setLandlord(int ref);
    int getLandlord();
    void setNowPlay(int n);
    int getNowPlay();
    void setNum(std::vector<int> num1);
    Q_INVOKABLE std::vector<int> getNum();
    Q_INVOKABLE void setAlready(int n);
    int getAlready();
    void setOver(int n);
    int getOver();

signals:
    void nowPlayChanged();
    void numChanged();
    void landlordChanged();
    void alreadyChanged();
    void temLandlordChanged();
    void markChanged();
    void overChanged();

public slots:
    void onNowPlayChanged();
    void onNumChanged();
    void onLandlordChanged();
    void onAlreadyChanged();
    void onTemLandlordChanged();
    void onMarkChanged();
    void onOverChanged();

private:
    std::vector<int> num; //第二位存牌型，第三位存最大值，第四位存张数，第一位存谁出的牌
    std::vector<people::poker> library;      //牌库
    std::vector<people::poker> temLibrary;   //临时牌库
    std::vector<people::poker> p1Hand;       //p1手牌
    std::vector<people::poker> p2Hand;       //p2手牌
    std::vector<people::poker> p3Hand;       //p3手牌
    std::vector<people::poker> landlordHand; //地主牌
    int temLandlord;                         //临时地主
    int mark;                                //叫分
    int landlord;                            //地主
    int nowPlay;                             //当前出牌人
    int already;                             //准备人数
    int over;
};
