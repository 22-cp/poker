#pragma once

#include <QDebug>
#include <QObject>
#include <QString>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

class people : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int ref READ getRef WRITE setRef NOTIFY refChanged FINAL)
    //Q_PROPERTY(bool playCard READ getPlayCard WRITE setPlayCard NOTIFY playCardChanged FINAL)

public:
    people();
    struct poker
    {
        int number;        //序号
        int size;          //大小
        std::string name;  //牌名
        std::string color; //花色
    };

    Q_INVOKABLE void output1();
    Q_INVOKABLE void sortHand();
    Q_INVOKABLE void usingCard(std::vector<int> num);
    Q_INVOKABLE void select(int n);
    Q_INVOKABLE void setHand(std::vector<poker> Poker);
    Q_INVOKABLE QString getCardName(int n);
    Q_INVOKABLE int getCardNumber(int n);
    Q_INVOKABLE int getTemNumber(int n);
    Q_INVOKABLE int getHandSize();
    Q_INVOKABLE std::vector<int> getNum1();
    Q_INVOKABLE bool pushCard(std::vector<int> num);
    Q_INVOKABLE void toushCard(std::vector<poker> card);

    // Q_INVOKABLE void setPlayCard(bool s);
    // Q_INVOKABLE bool getPlayCard();

    void outPut(std::vector<poker> tem);
    int straight(std::vector<poker> tem);
    int pairs(std::vector<poker> tem);
    int air1(std::vector<poker> tem);
    int air2(std::vector<poker> tem);
    int air3(std::vector<poker> tem);

    std::vector<poker> getHand();

    void setRef(int n);
    int getRef();

signals:
    void refChanged();
    //void playCardChanged();

public slots:
    void onRefChanged();
    //void onPlayCardChanged();

private:
    std::vector<int> num1;   //存储出牌信息
    std::vector<poker> hand; //手牌
    std::vector<int> output; //存储出牌的牌
    int ref;                 //序号
    bool playCard;
    std::vector<poker> tem; //存储出的牌的详细信息
};
