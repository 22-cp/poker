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

public:
    desk();

    Q_INVOKABLE int getNumRef();
    Q_INVOKABLE void dealCard();
    Q_INVOKABLE std::vector<people::poker> getP1Hand();
    Q_INVOKABLE std::vector<people::poker> getP2Hand();
    Q_INVOKABLE std::vector<people::poker> getP3Hand();
    Q_INVOKABLE std::vector<people::poker> getLandlordHand();

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

signals:
    void nowPlayChanged();
    void numChanged();
    void landlordChanged();
    void alreadyChanged();
    void temLandlordChanged();
    void markChanged();

public slots:
    void onNowPlayChanged();
    void onNumChanged();
    void onLandlordChanged();
    void onAlreadyChanged();
    void onTemLandlordChanged();
    void onMarkChanged();

private:
    std::vector<int> num; //第二位存牌型，第三位存最大值，第四位存张数，第一位存谁出的牌
    std::vector<people::poker> library;
    std::vector<people::poker> p1Hand;
    std::vector<people::poker> p2Hand;
    std::vector<people::poker> p3Hand;
    std::vector<people::poker> landlordHand;
    int temLandlord;
    int mark;
    int landlord;
    int nowPlay;
    int already;
};
