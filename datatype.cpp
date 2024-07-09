#include "datatype.h"
#include <QDataStream>
#include <QDebug>
#include <QIODevice>

QByteArray DataPackage::broadcastNum(int num, int playerIDS[], int heads[])
{
    QByteArray bytes;
    QDataStream out(&bytes, QIODevice::WriteOnly);
    out << BroadcastNum;
    out << num;
    for (int i = 0; i < num; i++)
        out << playerIDS[i] << heads[i];
    return bytes;
}

QByteArray DataPackage::origin(int landlordID, int num, int cards[])
{
    QByteArray bytes;
    QDataStream out(&bytes, QIODevice::WriteOnly);
    out << Origin;
    out << landlordID;
    out << num;
    for (int i = 0; i < num; i++) {
        out << cards[i];
    }
    return bytes;
}

QByteArray DataPackage::who(int thID)
{
    QByteArray bytes;
    QDataStream out(&bytes, QIODevice::WriteOnly);
    out << Who;
    out << thID;
    return bytes;
}

QByteArray DataPackage::chupai(int playerID, int num, int cards[])
{
    QByteArray bytes;
    QDataStream out(&bytes, QIODevice::WriteOnly);
    out << Cards;
    out << playerID;
    out << num;
    for (int i = 0; i < num; i++)
        out << cards[i];
    return bytes;
}

QByteArray DataPackage::actionFeedBack(bool res)
{
    QByteArray bytes;
    QDataStream out(&bytes, QIODevice::WriteOnly);
    out << ActionFeedback;
    out << res;
    return bytes;
}
