#pragma once

#include "people.h"

class desk : public QObject
{
    Q_OBJECT
public:
    desk();

    Q_INVOKABLE void setNum(std::vector<int> num1);
    Q_INVOKABLE std::vector<int> getNum();
    Q_INVOKABLE int getNumRef();
    Q_INVOKABLE void touchCard();
    Q_INVOKABLE std::vector<people::poker> getP1Hand();
    Q_INVOKABLE std::vector<people::poker> getP2Hand();
    Q_INVOKABLE std::vector<people::poker> getP3Hand();

private:
    std::vector<int> num; //第二位存牌型，第三位存最大值，第四位存张数，第一位存谁出的牌
    std::vector<people::poker> library;
    std::vector<people::poker> p1Hand;
    std::vector<people::poker> p2Hand;
    std::vector<people::poker> p3Hand;
};
