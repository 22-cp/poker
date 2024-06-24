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
        iss >> Poker.num >> Poker.name >> Poker.number >> Poker.color;
        library.push_back(Poker);
    }
    file.close();

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(library.begin(), library.end(), g);
}

int desk::getNumRef()
{
    if (!num.empty())
        return num[0];
    else
        return 0;
}

void desk::touchCard() //从牌库中抽取一张牌加入到手牌
{
    for (int i = 0; i < 17; i++) {
        if (library.begin() == library.end()) {
            cout << "No poker in it." << endl;
            return;
        }
        auto c = library.begin();
        p1Hand.push_back(*c);
        library.erase(library.begin());
        p2Hand.push_back(*c);
        library.erase(library.begin());
        p3Hand.push_back(*c);
        library.erase(library.begin());
    }
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
}
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
