#pragma once

#include <QDebug>
#include <QObject>
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
        int num;
        std::string name;
        std::string color;
    };

    //Q_INVOKABLE void touchCard();
    Q_INVOKABLE void output1();
    Q_INVOKABLE void sortHand();
    Q_INVOKABLE void usingCard();
    Q_INVOKABLE void select(int n);

    int outPut(std::vector<poker> tem);
    int straight(std::vector<poker> tem);
    int pairs(std::vector<poker> tem);
    int air1(std::vector<poker> tem);
    int air2(std::vector<poker> tem);
    int air3(std::vector<poker> tem);
    void setHand(std::vector<poker> Poker);

private:
    std::vector<poker> hand;
    //std::vector<poker> library;
    std::vector<int> output;
};
