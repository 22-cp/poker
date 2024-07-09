#pragma once
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "desk.h"
#include "people.h"

class qtsocket : public QObject
{
    Q_OBJECT
public:
    qtsocket();
    Q_PROPERTY(int m_Value READ iValue WRITE setValue NOTIFY valueChanged FINAL)
    Q_INVOKABLE void new_connect(const QString &toaddress, QString toport);
    Q_INVOKABLE void send_data(std::vector<int>, int);
    Q_INVOKABLE void socket_close1();
    Q_INVOKABLE void send_data1();
    QByteArray recieve_data;
    QByteArray recieve_buf;
    std::vector<int> a;
    int roleID;

    int iValue();
    Q_INVOKABLE void setValue(int newiValue);

    int m_Value;
    void send_ready();

public slots:
    void write_data();
    void socket_close();
    void sendmassage();

signals:
    void readyRead1();
    void recievedata();
    void valueChanged();

private:
    QTcpSocket *socket;
};
