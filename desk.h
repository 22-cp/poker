#pragma once

#include "people.h"

class desk : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int nowPlay READ getNowPlay WRITE setNowPlay NOTIFY nowPlayChanged FINAL)
    Q_PROPERTY(std::vector<int> num READ getNum WRITE setNum NOTIFY numChanged FINAL)
    Q_PROPERTY(int landlord READ getLandlord WRITE setLandlord NOTIFY landlordChanged FINAL)

public:
    desk();

    Q_INVOKABLE int getNumRef();
    Q_INVOKABLE void dealCard();
    Q_INVOKABLE std::vector<people::poker> getP1Hand();
    Q_INVOKABLE std::vector<people::poker> getP2Hand();
    Q_INVOKABLE std::vector<people::poker> getP3Hand();
    Q_INVOKABLE void setLandlords(int ref, int mark);
    Q_INVOKABLE std::vector<int> getLandlords();

    void setLandlord(int ref);
    Q_INVOKABLE int getLandlord();
    void setNowPlay(int n);
    Q_INVOKABLE int getNowPlay();
    void setNum(std::vector<int> num1);
    Q_INVOKABLE std::vector<int> getNum();

signals:
    void nowPlayChanged();
    void numChanged();
    void landlordChanged();

public slots:
    void onNowPlayChanged();
    void onNumChanged();
    void onLandlordChanged();

private:
    std::vector<int> num; //第二位存牌型，第三位存最大值，第四位存张数，第一位存谁出的牌
    std::vector<people::poker> library;
    std::vector<people::poker> p1Hand;
    std::vector<people::poker> p2Hand;
    std::vector<people::poker> p3Hand;
    std::vector<int> landlords;
    int landlord;
    int nowPlay;
};
