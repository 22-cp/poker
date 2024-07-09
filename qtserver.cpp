#include "qtserver.h"
#include <QDebug>
#include "datatype.h"
#include "desk.h"
#include "people.h"

qtserver::qtserver()
{
    tcpserver = new QTcpServer();
    servertcpsocket = new QTcpSocket();
    m_Value = 0;
}

void qtserver::listen_to_client(const QString &adds, QString port)
{
    std::cout << clientlist.size() << std::endl;
    unsigned short port1 = port.toShort();
    if (adds.isEmpty() || port.isEmpty()) {
        std::cout << "pease enter imformation" << std::endl; //
    } else {
        connect(tcpserver, &QTcpServer::newConnection, this, &qtserver::newConnect);
        if (tcpserver->listen(QHostAddress(adds), port1) == true) {
            std::cout << "server_successed" << std::endl;
            setValue(2);
        } else {
            return;
        }
    }
}

void qtserver::listen_close()
{
    tcpserver->close();
}
void qtserver::send_data(std::vector<people::poker> p1Hand, int b)
{
    int n = 17;
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = p1Hand[i].number;
    }
    clientlist.at(b)->write(DataPackage::origin(playID[b], n, &*a));
    clientlist.at(b)->flush();
}

void qtserver::ondisconnect()
{
    servertcpsocket = qobject_cast<QTcpSocket *>(sender());
    clientlist.removeOne(servertcpsocket);
    servertcpsocket->deleteLater();
}

void qtserver::newConnect()
{
    int a = true;
    if (clientlist.size() < 2) {
        servertcpsocket = tcpserver->nextPendingConnection();
        clientlist.prepend(servertcpsocket);
        connect(servertcpsocket, &QTcpSocket::readyRead, this, &qtserver::read_from_client);
        connect(servertcpsocket, &QTcpSocket::disconnected, this, &qtserver::ondisconnect);
    }
    if (clientlist.size() == 2) {
        setValue(2);
    }
    if (clientlist.size() > 2) {
        QTcpSocket *socket = tcpserver->nextPendingConnection();
        delete socket;
        qDebug() << "someone try to connect but the role is empty";
    }
}

void qtserver::read_from_client()
{
    if (servertcpsocket == clientlist.at(0)) {
        readData(playID[0]);
    } else {
        readData(playID[1]);
    }
}

void qtserver::readData(int playrole)
{
    QByteArray data1;
    data1 = servertcpsocket->readAll();
    QDataStream in(data1);
    int type;
    in >> type;
    switch (type) {
    case DataPackage::Cards: {
        int role, num;
        in >> role >> num;
        int s[num];
        for (int i = 0; i < num; i++) {
            in >> s[i];
            clientlist.at(playrole)->write(DataPackage::chupai(playrole, num, &*s));
        }
    }
    case DataPackage::Who: {
        int a, b;
        in >> a >> b;
        setValue(1);
    }
    }
}

int qtserver::iValue()
{
    return m_Value;
}
void qtserver::setValue(int newiValue)
{
    m_Value = newiValue;
    emit valueChanged();
}
