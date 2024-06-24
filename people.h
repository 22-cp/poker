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
public:
    people();
    struct poker
    {
        std::string number;
        int num;
        std::string name;
        std::string color;
    };

    Q_INVOKABLE void output1();
    Q_INVOKABLE void sortHand();
    Q_INVOKABLE void usingCard(std::vector<int> num);
    Q_INVOKABLE void select(int n);
    Q_INVOKABLE void setHand(std::vector<poker> Poker);
    Q_INVOKABLE QString getCardName(int n);
    Q_INVOKABLE void setRef(int n);
    Q_INVOKABLE int getRef();
    Q_INVOKABLE int getHandSize();
    Q_INVOKABLE std::vector<int> getNum1();
    Q_INVOKABLE bool pushCard(std::vector<int> num);
    Q_INVOKABLE void setPlayCard(bool s);
    Q_INVOKABLE bool getPlayCard();

    void outPut(std::vector<poker> tem);
    int straight(std::vector<poker> tem);
    int pairs(std::vector<poker> tem);
    int air1(std::vector<poker> tem);
    int air2(std::vector<poker> tem);
    int air3(std::vector<poker> tem);

    std::vector<poker> getHand();

private:
    std::vector<int> num1;
    std::vector<poker> hand;
    std::vector<int> output;
    int ref;
    bool playCard;
};
