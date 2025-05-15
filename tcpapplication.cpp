/**
 * @file tcpapplication.cpp
 * @author Jason Jemison
 * @brief Main Application
 */

#include <QCoreApplication>
#include "tcpClient.h"
#include "tcpServer.h"

/**
 * @brief Construct a new TCP Application
 *
 * @param argc Number of CLI arguments
 * @param argv CLI arguments
 */
int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    // Create the TCP Client and Server
    TCPServer server;
    TCPClient client;

    return app.exec();
}