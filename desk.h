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

private:
    std::vector<int> num;
    std::vector<people::poker> library;
    people *p1;
    people *p2;
    people *p3;
};
