#pragma once
#include <QObject>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtGlobal>
#include <QtQml>
#include "datatype.h"
#include "desk.h"
#include "people.h"
#include <iostream>

class qtserver : public QObject
{
    Q_OBJECT
public:
    qtserver();
    Q_PROPERTY(int m_Value READ iValue WRITE setValue NOTIFY valueChanged FINAL)
    Q_INVOKABLE void listen_to_client(const QString &adds, QString port);
    Q_INVOKABLE void listen_close();
    Q_INVOKABLE void send_data(std::vector<people::poker>, int);
    QByteArray get_read_buf();
    QByteArray Ssocket;
    QByteArray data, data1;
    int iValue();
    Q_INVOKABLE void setValue(int newiValue);
    QList<QTcpSocket *> clientlist;
    int playID[2] = {0, 1};
    void readData(int);

public slots:
    void read_from_client();
    void newConnect();
    void ondisconnect();

signals:
    void successed_disconnect_to_server();
    void data_is_coming();
    void valueChanged();

private:
    QTcpServer *tcpserver;
    QTcpSocket *servertcpsocket;
    int m_Value;
};
