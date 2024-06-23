#pragma once

#include "people.h"

class desk : public QObject
{
    Q_OBJECT
public:
    desk();
    void setNum(std::vector<int> num1);
    std::vector<int> getNum();

    Q_INVOKABLE void touchCard();
    Q_INVOKABLE void p1output1();
    Q_INVOKABLE void p1select(int n);
    Q_INVOKABLE void p1usingCard();
    Q_INVOKABLE int p1GetHandSize();
    Q_INVOKABLE QString p1GetCard(int n);

private:
    std::vector<int> num; //第一位存牌型，第二位存最大值，第三位存张数
    std::vector<people::poker> library;
    people *p1;
    people *p2;
    people *p3;
};
