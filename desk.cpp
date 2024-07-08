#include "desk.h"

desk::desk()
{
    std::ifstream file("./poker/CardLibrary");
    if (!file.is_open()) {
        std::cerr << "牌库加载失败!" << endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        people::poker Poker;
        iss >> Poker.size >> Poker.name >> Poker.number >> Poker.color;
        library.push_back(Poker);
    }
    file.close();

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(library.begin(), library.end(), g);

    temLibrary = library;

    nowPlay = 0;
    already = 0;
    over = 0;
}

void desk::setTemLibrary()
{
    temLibrary = library;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(temLibrary.begin(), temLibrary.end(), g);
}

int desk::getOver()
{
    return over;
}

void desk::setOver(int n)
{
    over = n;
    emit overChanged();
}

void desk::onOverChanged() {}

std::vector<people::poker> desk::getLandlordHand()
{
    return landlordHand;
}

void desk::setAlready(int n)
{
    already = already + n;
    emit alreadyChanged();
}

int desk::getAlready()
{
    return already;
}

void desk::onAlreadyChanged() {}

void desk::onNowPlayChanged() {}

void desk::setNowPlay(int n)
{
    nowPlay = n;
    emit nowPlayChanged();
}

int desk::getNowPlay()
{
    return nowPlay;
}

int desk::getNumRef()
{
    if (!num.empty())
        return num[0];
    else
        return 0;
}

void desk::dealCard() //从牌库中抽取一张牌加入到手牌
{
    p1Hand.clear();
    p2Hand.clear();
    p3Hand.clear();
    for (int i = 0; i < 17; i++) {
        if (temLibrary.begin() == temLibrary.end()) {
            cout << "No poker in it." << endl;
            return;
        }
        auto c = temLibrary.begin();
        p1Hand.push_back(*c);
        temLibrary.erase(temLibrary.begin());
        p2Hand.push_back(*c);
        temLibrary.erase(temLibrary.begin());
        p3Hand.push_back(*c);
        temLibrary.erase(temLibrary.begin());
    }
    landlordHand.clear();
    landlordHand = temLibrary;
    temLibrary.clear();
}
std::vector<int> desk::getNum()
{
    return num;
}

void desk::setNum(std::vector<int> num1)
{
    if (num1.empty())
        return;
    num.clear();
    num = num1;

    emit numChanged();
}

void desk::onNumChanged() {}

void desk::setTemLandlord(int ref)
{
    temLandlord = ref;
    emit temLandlordChanged();
}

int desk::getTemLandlord()
{
    return temLandlord;
}

void desk::onTemLandlordChanged() {}

void desk::setMark(int n)
{
    mark = n;
    emit markChanged();
}

int desk::getMark()
{
    return mark;
}

void desk::onMarkChanged() {}

void desk::setLandlord(int ref)
{
    landlord = ref;
    emit landlordChanged();
}

int desk::getLandlord()
{
    return landlord;
}

void desk::onLandlordChanged() {}

std::vector<people::poker> desk::getP1Hand()
{
    return p1Hand;
}
std::vector<people::poker> desk::getP2Hand()
{
    return p2Hand;
}
std::vector<people::poker> desk::getP3Hand()
{
    return p3Hand;
}
