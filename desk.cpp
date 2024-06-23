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

    p1 = new people;
    p2 = new people;
    p3 = new people;
}

void desk::touchCard() //从牌库中抽取一张牌加入到手牌
{
    std::vector<people::poker> p1Hand;
    std::vector<people::poker> p2Hand;
    std::vector<people::poker> p3Hand;
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
    p1->setHand(p1Hand);
    p1->sortHand();
    p2->setHand(p2Hand);
    p2->sortHand();
    p3->setHand(p3Hand);
    p3->sortHand();
}

void desk::p1output1()
{
    p1->output1();
}

void desk::p1select(int n)
{
    p1->select(n);
}

void desk::p1usingCard()
{
    p1->usingCard(num);
}

int desk::p1GetHandSize()
{
    std::vector<people::poker> hand1;
    hand1 = p1->getHand();
    return hand1.size();
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

QString desk::p1GetCard(int n)
{
    std::vector<people::poker> hand1;
    hand1 = p1->getHand();
    QString str = QString::fromStdString(hand1[n].name);
    return str;
}
