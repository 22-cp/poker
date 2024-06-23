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
    Q_INVOKABLE void usingCard(std::vector<int> &num);
    Q_INVOKABLE void select(int n);

    void outPut(std::vector<poker> tem, std::vector<int> &num1);
    int straight(std::vector<poker> tem, std::vector<int> &num1);
    int pairs(std::vector<poker> tem, std::vector<int> &num1);
    int air1(std::vector<poker> tem, std::vector<int> &num1);
    int air2(std::vector<poker> tem, std::vector<int> &num1);
    int air3(std::vector<poker> tem, std::vector<int> &num1);
    void setHand(std::vector<poker> Poker);
    bool pushCard(std::vector<int> &num, std::vector<int> num1);
    std::vector<poker> getHand();

    std::vector<int> num1;

private:
    std::vector<poker> hand;
    std::vector<int> output;
};
