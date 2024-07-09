#include "qtsocket.h"
#include "datatype.h"
#include "desk.h"
#include "people.h"
#include <iostream>

qtsocket::qtsocket()
{
    socket = new QTcpSocket(this);
    m_Value = 0;
}

void qtsocket::write_data()
{
    recieve_buf = socket->readAll();
    QDataStream in(recieve_buf);
    int type;
    in >> type;
    switch (type) {
    case DataPackage::Origin: {
        int landlordID, num, tmp;
        std::vector<int> cards;
        in >> landlordID >> num;
        roleID = landlordID;
        for (int i = 0; i < num; i++) {
            in >> tmp;
            cards.push_back(tmp);
            qDebug() << tmp;
            emit recievedata();
        }
    }
    case DataPackage::Cards: {
        int playID, num, tep;
        std::vector<int> cards;
        in >> playID >> num;
        for (int i = 0; i < num; i++) {
            in >> tep;
            cards.push_back(tep);
        }
    }
    case DataPackage::Who: {
        int playId, state;
        in >> playId >> state;
    }
    case DataPackage::BroadcastNum: {
        emit readyRead1();
    }
    }
}

void qtsocket::new_connect(const QString &toaddress, QString toport)
{
    unsigned short port2 = toport.toShort();
    socket->connectToHost(QHostAddress(toaddress), port2);
    setValue(1);
    connect(socket, &QTcpSocket::connected, this, &qtsocket::sendmassage);
    connect(socket, &QTcpSocket::readyRead, this, &qtsocket::write_data);
}

void qtsocket::send_data1()
{
    int a = 1;
    socket->write(DataPackage::who(a));
}
void qtsocket::send_data(std::vector<int> a, int num)
{
    int s[num];
    for (int i = 0; i < num; i++) {
        s[i] = a[i];
    }
    socket->write(DataPackage::chupai(roleID, num, &*s));
    socket->flush();
}

void qtsocket::socket_close()
{
    socket->close();
}
void qtsocket::socket_close1()
{
    socket->close();
}
void qtsocket::sendmassage()
{
    qDebug() << "connect seccessed";
}

int qtsocket::iValue()
{
    return m_Value;
}
void qtsocket::setValue(int newiValue)
{
    m_Value = newiValue;
    emit valueChanged();
}
