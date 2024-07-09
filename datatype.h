#ifndef DATAPACKAGE
#define DATAPACKAGE

#include <QByteArray>
#include <QString>

class DataPackage
{
public:
    static QByteArray login(const QString& username, const QString& password);

    static QByteArray loginResult(bool res, int playerID, int head);

    static QByteArray broadcastNum(int num, int playerIDS[], int heads[]);

    static QByteArray progress(bool gameState, int winnerID);

    static QByteArray origin(int landlordID, int num, int cards[]);

    static QByteArray who(int thID);

    static QByteArray chupai(int playerID, int num, int cards[]);

    static QByteArray actionFeedBack(bool res);

    const static int BroadcastNum = 1;
    const static int Origin = 5;
    const static int Who = 6;
    const static int Cards = 7;
    const static int ActionFeedback = 8;
    const static int EnterRoom = 9;
};

#endif
