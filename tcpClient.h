/**
 * @file tcpClient.h
 * @author Jason Jemison
 * @brief Creates the TCP Client 
 */

#ifndef TCPCLIENT_H_
#define TCPCLIENT_H_

#include <QTcpSocket>
#include <QObject>
#include <iostream>
#include <stdlib.h>

class TCPClient : public QObject 
{
    Q_OBJECT

public:

    TCPClient(QObject* parent = nullptr);

private slots:
    void onConnected();
    void onReadyRead();
    void errorOccured();

private:
    /// @brief  tcpSocket
    QTcpSocket *_tcpSocket;

private:
    /// @brief heartbeat interval in milliseconds
    int _heartbeatRate = 1000;

};



#endif // TCPCLIENT_H_