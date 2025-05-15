/**
 * @file tcpServer.h
 * @author Jason Jemison
 * @brief Creates TCP Server
 */

#ifndef TCPSERVER_H_
#define TCPSERVER_H_

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include <QFile>

class TCPServer : public QObject 
{
    Q_OBJECT

public:
    TCPServer(QObject* parent = nullptr);

private slots:
    void newTCPConnection();
    void handleTCPData();

signals:
    void tcpMessageReceived(const QString& message);

private:
    /// @brief  TCP Socket
    QTcpSocket *_tcpSocket;

    /// @brief  TCP Server
    QTcpServer *_tcpServer;

    /// @brief  TCP Message data
    QByteArray _clientData;

    /// @brief  Log file
    QFile _logFile;

};

#endif // TCPSERVER_H_