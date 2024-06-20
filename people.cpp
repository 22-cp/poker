#include "people.h"

people::people()
{
    std::ifstream file("/root/poker/poker/CardLibrary");
    if (!file.is_open()) {
        std::cerr << "牌库加载失败!" << endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        poker Poker;
        iss >> Poker.num >> Poker.name >> Poker.color;
        library.push_back(Poker);
    }
    file.close();

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(library.begin(), library.end(), g);
}

void people::touchCard() //从牌库中抽取一张牌加入到手牌
{
    for (int i = 0; i < 17; i++) {
        if (library.begin() == library.end()) {
            cout << "No poker in it." << endl;
            return;
        }
        auto c = library.begin();
        hand.push_back(*c);
        library.erase(library.begin());
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

void people::sortHand() //将手牌排序
{
    int n = hand.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (hand[j].num < hand[j + 1].num) {
                std::swap(hand[j], hand[j + 1]);
            }
        }
    }
}

void people::usingCard()
{
    if (output.size() != 0 && output.size() <= hand.size()) {
        int n = output.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (output[j] < output[j + 1]) {
                    std::swap(output[j], output[j + 1]);
                }
                if (output[j] == output[j + 1]) {
                    output.erase(output.begin() + j + 1);
                    output.erase(output.begin() + j);
                    if (output.size() == 0) {
                        cout << "不符合出牌规则" << endl;
                        return;
                    }
                    n = n - 2;
                    j--;
                }
            }
        }
        if (output.back() > hand.size()) {
            cout << "不符合出牌规则" << endl;
            return;
        }
        std::vector<poker> tem; //创建一个临时容器存储要出的牌
        for (int i = 0; i < output.size(); i++) {
            tem.push_back(hand[output[i] - 1]);
        }
        int x;
        x = outPut(tem);
        if (x != 0) {
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
                if (tem[0].num == tem[1].num) {
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
                if (tem[0].num == tem[1].num && tem[1].num == tem[2].num) {
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
        } else {
            cout << "不符合出牌规则" << endl;
        }
    }
    output.clear();
}

int people::straight(std::vector<people::poker> tem)
{
    int x = 1;
    for (int i = 0; i < tem.size() - 1; i++) {
        if (tem[i].num != tem[i + 1].num - 1) {
            x = 0;
            break;
        }
    }
    return x;
}
int people::pairs(std::vector<people::poker> tem)
{
    int x = 1;
    for (int i = 0; i < tem.size(); i++) {
        if (tem[0].num != tem[i].num - i / 2) {
            x = 0;
            break;
        }
    }
    return x;
}
int people::air1(std::vector<people::poker> tem)
{
    int x = 0;
    for (int i = 0; i < tem.size() - 2; i++) {
        if (tem[i].num == tem[i + 2].num) {
            x++;
            if (i + 3 >= tem.size() - 2)
                break;
            if (tem[i].num != tem[i + 3].num - 1)
                break;
            i = i + 2;
        }
    }
    return x;
}
int people::air2(std::vector<people::poker> tem)
{
    int x = 0;
    for (int i = 0; i < tem.size() - 2; i++) {
        if (tem[i].num == tem[i + 2].num) {
            x++;
            if (i + 3 >= tem.size() - 2)
                break;
            if (tem[i].num != tem[i + 3].num - 1)
                break;
            i = i + 2;
        }
        if (i > x + tem.size() / 4)
            break;
    }
    return x;
}
int people::air3(std::vector<people::poker> tem)
{
    int x = 0;
    for (int i = 0; i < tem.size() - 2; i++) {
        if (tem[i].num == tem[i + 2].num) {
            x++;
            if (i + 3 >= tem.size() - 2)
                break;
            if (tem[i].num != tem[i + 3].num - 1)
                break;
            i = i + 2;
        } else if (tem[i].num == tem[i + 1].num) {
            i = i + 1;
        }
        if (i > x + tem.size() / 5)
            break;
    }
    return x;
}
int people::outPut(std::vector<people::poker> tem)
{
    if (tem.size() == 1) {
        return 1; //单牌
    } else if (tem.size() == 2) {
        if (tem[0].num == tem[1].num) {
            return 2; //对子
        }
        if (tem[0].num == 14 && tem[1].num == 15) {
            return 100;
        }
    } else if (tem.size() == 3) {
        if (tem[0].num == tem[2].num)
            return 3; //三不带
    } else if (tem.size() == 4) {
        if ((tem[0].num == tem[2].num && tem[0].num != tem[3].num)
            || (tem[1].num == tem[3].num && tem[0].num != tem[3].num))
            return 4; //三带一
        else if (tem[0].num == tem[3].num)
            return 5; //炸弹
    } else if (tem.size() == 5) {
        if ((tem[4].num == tem[3].num + 1) && (tem[3].num == tem[2].num + 1)
            && (tem[2].num == tem[1].num + 1) && (tem[1].num == tem[0].num + 1)) {
            if (tem[4].num <= 12)
                return 6;
        }
        if ((tem[0].num == tem[2].num && tem[3].num == tem[4].num)
            || tem[2].num == tem[4].num && tem[0].num == tem[1].num) {
            return 7; //三带一对
        }
    } else if (tem.size() == 6) {
        if (tem[tem.size() - 1].num > 12)
            return 0;
        int x = straight(tem);
        if (x)
            return 6;

        x = pairs(tem);
        if (x)
            return 8;

        x = air1(tem);
        if (x == tem.size() / 3)
            return 9;
    } else if (tem.size() == 7 || tem.size() == 11) {
        if (tem[tem.size() - 1].num > 12)
            return 0;
        int x = straight(tem);
        if (x)
            return 6;
    } else if (tem.size() == 8) {
        if (tem[tem.size() - 1].num > 12)
            return 0;
        int x = straight(tem);
        if (x)
            return 6;

        x = pairs(tem);
        if (x)
            return 8;

        x = air2(tem);
        if (x == tem.size() / 4)
            return 10; //飞机带单

    } else if (tem.size() == 9) {
        if (tem[tem.size() - 1].num > 12)
            return 0;
        int x = straight(tem);
        if (x)
            return 6;

        x = air1(tem);
        if (x == tem.size() / 3)
            return 9;
    } else if (tem.size() == 10) {
        if (tem[tem.size() - 1].num > 12)
            return 0;
        int x = straight(tem);
        if (x)
            return 6;

        x = pairs(tem);
        if (x)
            return 8;

        x = air3(tem);
        if (x == tem.size() / 5)
            return 11; //飞机带对
    } else if (tem.size() == 12) {
        if (tem[tem.size() - 1].num > 12)
            return 0;
        int x = straight(tem);
        if (x)
            return 6;

        x = pairs(tem);
        if (x)
            return 8;

        x = air1(tem);
        if (x == tem.size() / 3)
            return 9;

        x = air2(tem);
        if (x == tem.size() / 4)
            return 10; //飞机带单
    } else if (tem.size() == 14) {
        if (tem[tem.size() - 1].num > 12)
            return 0;
        int x = pairs(tem);
        if (x)
            return 8;
    } else if (tem.size() == 15) {
        if (tem[tem.size() - 1].num > 12)
            return 0;
        int x = air1(tem);
        if (x == tem.size() / 3)
            return 9; //飞机不带

        x = air3(tem);
        if (x == tem.size() / 5)
            return 11; //飞机带对
    } else if (tem.size() == 16) {
        if (tem[tem.size() - 1].num > 12)
            return 0;
        int x = pairs(tem);
        if (x)
            return 8;

        x = air2(tem);
        if (x == tem.size() / 4)
            return 10; //飞机带单
    } else if (tem.size() == 18) {
        if (tem[tem.size() - 1].num > 12)
            return 0;
        int x = pairs(tem);
        if (x)
            return 8;

        x = air1(tem);
        if (x == tem.size() / 3)
            return 9;
    } else if (tem.size() == 20) {
        if (tem[tem.size() - 1].num > 12)
            return 0;
        int x = pairs(tem);
        if (x)
            return 8;

        x = air2(tem);
        if (x == tem.size() / 4)
            return 10; //飞机带单

        x = air3(tem);
        if (x == tem.size() / 5)
            return 11; //飞机带对
    }
    return 0;
}

void people::select(int n)
{
    output.push_back(n);
}
