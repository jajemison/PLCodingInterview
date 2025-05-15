/**
 * @file tcpClient.cpp
 * @author Jason Jemison
 * @brief Creates the TCP Client 
 */

#include "tcpClient.h"
#include <QDebug>
#include <QTimer>
#include <QTime>

/**
 * @brief Construct a new TCP Client object 
 *
 * @param parent Parent
 */
TCPClient::TCPClient(QObject* parent) : 
    QObject(parent)
{
    // Create TCP Socket for client
    _tcpSocket = new QTcpSocket(this);

    // Connect TCP Client slots
    connect(_tcpSocket, &QTcpSocket::connected, this, &TCPClient::onConnected);
    connect(_tcpSocket, &QTcpSocket::readyRead, this, &TCPClient::onReadyRead);
    connect(_tcpSocket, &QTcpSocket::errorOccurred, this, &TCPClient::errorOccured);

    // Create host port
    _tcpSocket->connectToHost("127.0.0.1", 12345);
    
}

/**
 * @brief Entry point for the TCP Client
 */
void TCPClient::onConnected()
{
    qDebug() << "The client is connected... ";

    // Create timer for sending heartbeat message at regular interval
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]()
    {
        // Create message with current time
        QString msg = "TCP Message sent at " + QTime::currentTime().toString();

        // Write TCP message to socket
        _tcpSocket->write(msg.toUtf8());
    });

    timer->start(_heartbeatRate);
}

/**
 * @brief Client ability to receive message from the TCP server
 */
void TCPClient::onReadyRead()
{
    qDebug() << "The client received the following: " << _tcpSocket->readAll();
}

/**
 * @brief Client ability for detection error in the connectivity
 */
void TCPClient::errorOccured()
{
    qWarning() << "Connection Error Occured: " << _tcpSocket->errorString();
}
