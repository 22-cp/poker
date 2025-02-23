#include "people.h"
#include "desk.h"

people::people()
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
}

void people::mplay(std::vector<int> num)
{
    if (num[1] == 1) {
        for (int i = hand.size() - 1; i > -1; i--) {
            if (hand[i].size > num[2]) {
                select(i + 1);
                usingCard(num);
                break;
            }
        }
    } else if (num[1] == 2) {
        for (int i = hand.size() - 1; i > 0; i--) {
            if (hand[i].size > num[2] && hand[i - 1].size == hand[i].size) {
                select(i + 1);
                select(i);
                usingCard(num);
                break;
            }
        }
    } else {
        for (int i = hand.size(); i > 1; i--) {
            if (hand[i].size > num[2] && hand[i].size == hand[i - 2].size) {
                select(i + 1);
                select(i);
                select(i - 1);
                usingCard(num);
                break;
            }
        }
    }
}

void people::output1()
{
    int l = 1;
    for (const auto &poker : hand) {
        cout << l << "  ";
        cout << poker.color << " " << poker.name;
        cout << endl;
        l++;
    }
}

void people::setHand1(std::vector<int> x)
{
    x.erase(x.begin());
    int n = x.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (x[j] < x[j + 1]) {
                std::swap(x[j], x[j + 1]);
            }
        }
    }
    int j = 0;
    for (int i = 0; i < library.size(); i++) {
        if (library[i].number == x[j]) {
            hand.push_back(library[i]);
            j++;
        }
    }
}

void people::setRef(int n)
{
    ref = n;
    emit refChanged();
}

int people::getRef()
{
    return ref;
}

void people::onRefChanged() {}

void people::toushCard(std::vector<poker> card)
{
    if (hand.size() == 17) {
        for (int i = 0; i < 3; i++) {
            auto c = card.begin();
            hand.push_back(*c);
            card.erase(card.begin());
        }
    }
    sortHand();
}

void people::sortHand() //将手牌排序
{
    int n = hand.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (hand[j].size < hand[j + 1].size) {
                std::swap(hand[j], hand[j + 1]);
            }
        }
    }
}
std::vector<people::poker> people::getTem()
{
    return tem;
}

bool people::pushCard(std::vector<int> num)
{
    if (num.empty())
        return true;

    if (num1.empty())
        return false;

    if (num[0] == num1[0])
        return true;

    if (num[1] == 100)
        return false;

    if (num1[1] == 100)
        return true;

    if (num1[1] == 5 && num[1] != 5)
        return true;

    if (num1[1] != num[1] || num1[2] <= num[2] || num1[3] != num[3])
        return false;

    return true;
}

void people::usingCard(std::vector<int> num)
{
    num1.clear();
    if (output.size() != 0) {
        int n = output.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (output[j] < output[j + 1]) {
                    std::swap(output[j], output[j + 1]);
                }
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (output[i] == output[i + 1]) {
                output.erase(output.begin() + i + 1);
                output.erase(output.begin() + i);
                if (output.size() == 0 && output.size() <= hand.size()) {
                    cout << "不符合出牌规则" << endl;
                    return;
                }
                n = n - 2;
                i--;
            }
        }
        if (output.back() > hand.size()) {
            cout << "不符合出牌规则" << endl;
            return;
        }
        tem.clear(); //创建一个临时容器存储要出的牌
        for (int i = 0; i < output.size(); i++) {
            tem.push_back(hand[output[i] - 1]);
        }
        int x;
        outPut(tem);
        x = num1[1];
        if (x != 0) {
            if (!pushCard(num)) {
                cout << "不符合出牌规则" << endl;
                return;
            }
            if (x == 1) {
                cout << tem[0].color << tem[0].name << endl;
            }
            if (x == 2) {
                cout << "对" << tem[0].name << endl;
            }
            if (x == 3) {
                cout << "三个" << tem[0].name << endl;
            }
            if (x == 4) {
                if (tem[0].size == tem[1].size) {
                    cout << "三个" << tem[1].name << "带" << tem[3].name << endl;
                } else {
                    cout << "三个" << tem[1].name << "带" << tem[0].name << endl;
                }
            }
            if (x == 5) {
                cout << "四个" << tem[0].name << "炸" << endl;
            }
            if (x == 6) {
                for (const auto &poker : tem) {
                    cout << poker.name;
                }
                cout << "顺子" << endl;
            }
            if (x == 7) {
                if (tem[0].size == tem[1].size && tem[1].size == tem[2].size) {
                    cout << "三个" << tem[0].name << "带一对" << tem[4].name << endl;
                } else {
                    cout << "三个" << tem[2].name << "带一对" << tem[0].name << endl;
                }
            }
            if (x == 8) {
                for (const auto &poker : tem) {
                    cout << poker.name;
                }
                cout << "连对" << endl;
            }
            if (x == 9 || x == 10 || x == 11) {
                for (const auto &poker : tem) {
                    cout << poker.name;
                }
                cout << "飞机" << endl;
            }
            if (x == 100) {
                cout << "王炸" << endl;
            }

            //将出的牌从手牌中删除
            for (int i = 0; i < output.size(); i++) {
                hand.erase(hand.begin() + output[i] - 1);
            }
            cout << endl;
            output.clear();
        } else {
            cout << "不符合出牌规则" << endl;
        }
    }
}

std::vector<int> people::getNum1()
{
    return num1;
}

int people::straight(std::vector<people::poker> tem)
{
    num1.clear();
    if (tem[tem.size() - 1].size > 12) {
        return 0;
    }
    int x = 1;
    for (int i = 0; i < tem.size() - 1; i++) {
        if (tem[i].size != tem[i + 1].size - 1) {
            x = 0;
            break;
        }
    }
    num1.push_back(ref);
    num1.push_back(6);
    num1.push_back(tem[tem.size() - 1].size);
    num1.push_back(tem.size());
    return x;
}
int people::pairs(std::vector<people::poker> tem)
{
    num1.clear();
    if (tem[tem.size() - 1].size > 12) {
        return 0;
    }
    int x = 1;
    for (int i = 0; i < tem.size(); i++) {
        if (tem[0].size != tem[i].size - i / 2) {
            x = 0;
            break;
        }
    }
    num1.push_back(ref);
    num1.push_back(8);
    num1.push_back(tem[tem.size() - 1].size);
    num1.push_back(tem.size());
    return x;
}
int people::air1(std::vector<people::poker> tem)
{
    num1.clear();
    if (tem[tem.size() - 1].size > 12) {
        return 0;
    }
    int x = 0;
    for (int i = 0; i < tem.size() - 2; i++) {
        if (tem[i].size == tem[i + 2].size) {
            x++;
            if (i + 3 >= tem.size() - 2)
                break;
            if (tem[i].size != tem[i + 3].size - 1)
                break;
            i = i + 2;
        }
    }
    num1.push_back(ref);
    num1.push_back(9);
    num1.push_back(tem[tem.size() - 1].size);
    num1.push_back(tem.size());
    return x;
}
int people::air2(std::vector<people::poker> tem)
{
    num1.clear();
    int x = 0;
    int i;
    for (i = 0; i < tem.size() - 2; i++) {
        if (tem[i].size == tem[i + 2].size) {
            x++;
            if (i + 3 >= tem.size() - 2)
                break;
            if (tem[i].size != tem[i + 3].size - 1)
                break;
            i = i + 2;
        }
        if (i > x + tem.size() / 4)
            break;
    }
    num1.push_back(ref);
    num1.push_back(10);
    num1.push_back(tem[i].size);
    num1.push_back(tem.size());
    return x;
}
int people::air3(std::vector<people::poker> tem)
{
    num1.clear();
    int x = 0;
    int i;
    for (i = 0; i < tem.size() - 2; i++) {
        if (tem[i].size == tem[i + 2].size) {
            x++;
            if (i + 3 >= tem.size() - 2)
                break;
            if (tem[i].size != tem[i + 3].size - 1)
                break;
            i = i + 2;
        } else if (tem[i].size == tem[i + 1].size) {
            i = i + 1;
        }
        if (i > x + tem.size() / 5)
            break;
    }
    num1.push_back(ref);
    num1.push_back(11);
    num1.push_back(tem[i].size);
    num1.push_back(tem.size());
    return x;
}
void people::outPut(std::vector<people::poker> tem)
{
    if (tem.size() == 1) {
        num1.push_back(ref);
        num1.push_back(1);
        num1.push_back(tem[0].size);
        num1.push_back(tem.size());
        return; //单牌
    } else if (tem.size() == 2) {
        if (tem[0].size == tem[1].size) {
            num1.push_back(ref);
            num1.push_back(2);
            num1.push_back(tem[0].size);
            num1.push_back(tem.size());
            return; //对子
        }
        if (tem[0].size == 14 && tem[1].size == 15) {
            num1.push_back(ref);
            num1.push_back(100);
            num1.push_back(tem[0].size);
            num1.push_back(tem.size());
            return;
        }
    } else if (tem.size() == 3) {
        if (tem[0].size == tem[2].size) {
            num1.push_back(ref);
            num1.push_back(3);
            num1.push_back(tem[0].size);
            num1.push_back(tem.size());
            return; //三不带
        }
    } else if (tem.size() == 4) {
        if ((tem[0].size == tem[2].size && tem[0].size != tem[3].size)
            || (tem[1].size == tem[3].size && tem[0].size != tem[3].size)) {
            num1.push_back(ref);
            num1.push_back(4);
            num1.push_back(tem[2].size);
            num1.push_back(tem.size());
            return; //三带一
        } else if (tem[0].size == tem[3].size) {
            num1.push_back(ref);
            num1.push_back(5);
            num1.push_back(tem[0].size);
            num1.push_back(tem.size());
            return; //炸弹
        }
    } else if (tem.size() == 5) {
        if ((tem[4].size == tem[3].size + 1) && (tem[3].size == tem[2].size + 1)
            && (tem[2].size == tem[1].size + 1) && (tem[1].size == tem[0].size + 1)) {
            if (tem[4].size <= 12) {
                num1.push_back(ref);
                num1.push_back(6);
                num1.push_back(tem[4].size);
                num1.push_back(tem.size());
                return;
            }
        }
        if ((tem[0].size == tem[2].size && tem[3].size == tem[4].size)
            || tem[2].size == tem[4].size && tem[0].size == tem[1].size) {
            num1.push_back(ref);
            num1.push_back(7);
            num1.push_back(tem[2].size);
            num1.push_back(tem.size());
            return; //三带一对
        }
    } else if (tem.size() == 6) {
        if (tem[tem.size() - 1].size > 12) {
            num1.push_back(0);
            return;
        }
        int x = straight(tem);
        if (x)
            return;

        x = pairs(tem);
        if (x)
            return;

        x = air1(tem);
        if (x == tem.size() / 3)
            return;
    } else if (tem.size() == 7 || tem.size() == 11) {
        num1.clear();
        if (tem[tem.size() - 1].size > 12) {
            num1.push_back(0);
            return;
        }
        int x = straight(tem);
        if (x)
            return;
    } else if (tem.size() == 8) {
        num1.clear();
        int x = straight(tem);
        if (x)
            return;

        x = pairs(tem);
        if (x)
            return;

        x = air2(tem);
        if (x == tem.size() / 4)
            return; //飞机带单

    } else if (tem.size() == 9) {
        int x = straight(tem);
        if (x)
            return;

        x = air1(tem);
        if (x == tem.size() / 3)
            return;
    } else if (tem.size() == 10) {
        int x = straight(tem);
        if (x)
            return;

        x = pairs(tem);
        if (x)
            return;

        x = air3(tem);
        if (x == tem.size() / 5)
            return; //飞机带对
    } else if (tem.size() == 12) {
        int x = straight(tem);
        if (x)
            return;

        x = pairs(tem);
        if (x)
            return;

        x = air1(tem);
        if (x == tem.size() / 3)
            return;

        x = air2(tem);
        if (x == tem.size() / 4)
            return; //飞机带单
    } else if (tem.size() == 14) {
        int x = pairs(tem);
        if (x)
            return;
    } else if (tem.size() == 15) {
        int x = air1(tem);
        if (x == tem.size() / 3)
            return; //飞机不带

        x = air3(tem);
        if (x == tem.size() / 5)
            return; //飞机带对
    } else if (tem.size() == 16) {
        int x = pairs(tem);
        if (x)
            return;

        x = air2(tem);
        if (x == tem.size() / 4)
            return; //飞机带单
    } else if (tem.size() == 18) {
        int x = pairs(tem);
        if (x)
            return;

        x = air1(tem);
        if (x == tem.size() / 3)
            return;
    } else if (tem.size() == 20) {
        int x = pairs(tem);
        if (x)
            return;

        x = air2(tem);
        if (x == tem.size() / 4)
            return; //飞机带单

        x = air3(tem);
        if (x == tem.size() / 5)
            return; //飞机带对
    }
    num1.clear();
    num1.push_back(0);
}

void people::select(int n)
{
    output.push_back(n);
}

void people::setHand(std::vector<poker> Poker)
{
    if (Poker.empty())
        return;
    hand.clear();
    hand = Poker;
}

QString people::getCardName(int n)
{
    QString name;
    name = QString::fromStdString(hand[n].name);
    return name;
}

int people::getCardNumber(int n)
{
    return hand[n].number;
}

int people::getTemNumber(int n)
{
    return tem[n].number;
}

int people::getHandSize()
{
    return hand.size();
}

std::vector<people::poker> people::getHand()
{
    return hand;
}
