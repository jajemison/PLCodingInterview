/**
 * @file tcpServer.cpp
 * @author Jason Jemison
 * @brief Creates TCP Server 
 */

#include "tcpServer.h"
#include <QDebug>

/**
 * @brief Construct a new TCP Server object 
 *
 * @param parent Parent
 */
TCPServer::TCPServer(QObject* parent) : 
    QObject(parent)
{
    // Create TCP Server
    _tcpServer = new QTcpServer(this);
    connect(_tcpServer, &QTcpServer::newConnection, this, &TCPServer::newTCPConnection);
    // Set server to listen on give host and port
    if (!_tcpServer->listen(QHostAddress::LocalHost, 12345))
    {
        qCritical() << "The TCP Server failed to start... ";
    }
    else
    {
        qDebug() << "The TCP Server is listening on port 12345... ";
    }

}

/**
 * @brief Entry point for the TCP server
 */
void TCPServer::newTCPConnection()
{
    qDebug() << "New TCP Conncetion Established... ";

    // Read for new messages on TCP server
    _tcpSocket = _tcpServer->nextPendingConnection();

    // Connect socket to data handler
    connect(_tcpSocket, &QTcpSocket::readyRead, this, &TCPServer::handleTCPData);

    // Close socket if connection lost
    connect(_tcpSocket, &QTcpSocket::disconnected, [this]()
    {
        _tcpSocket->deleteLater();
        _logFile.close();
    });
}

/**
 * @brief TCP Server Data handler
 */
void TCPServer::handleTCPData()
{
    // Add TCP message data to QByteArray
    _clientData = _tcpSocket->readAll();
    emit tcpMessageReceived(_clientData);

    // Log TCP message data to terminal log
    qDebug() << "Reading Client Data... ";
    qDebug() << _clientData;

    // Log TCP message data to locally stored log file
    QFile _logFile("tcpLog.csv");
    if (_logFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&_logFile);
        stream << _clientData << "\n";
        _logFile.flush();
    } else {
       qDebug() << "Error opening file";
    }
}