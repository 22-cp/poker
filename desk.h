#pragma once

#include "people.h"

class desk : public QObject
{
    Q_OBJECT
public:
    desk();
    void setNum(std::vector<int> num);
    std::vector<int> getNum();

    Q_INVOKABLE void touchCard();
    Q_INVOKABLE void p1output1();
    Q_INVOKABLE void p1select();
    Q_INVOKABLE void p1usingCard();

private:
    std::vector<int> num;
    std::vector<people::poker> library;
    people *p1;
    people *p2;
    people *p3;
};
