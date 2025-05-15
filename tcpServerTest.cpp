/**
 * @file tcpServerTest.cpp
 * @author Jason Jemison
 * @brief Application for running tests for determine TCP Client and Server Stability
 */

#include <QtTest>
#include <QTcpSocket>
#include <QTime>
#include "tcpServer.h"

/**
 * @brief Server Test Object
 * 
 */
class TCPServerTest : public QObject {
    Q_OBJECT

private slots:
    void testMessageMatchesExpected(); // your test case
    void testMessageDoesNotMatchExpected();
};

/**
 * @test Check for correct TCP message recieved
 * 
 * @brief Passing Test
 */
void TCPServerTest::testMessageMatchesExpected() {
    // Create server using Server Class
    TCPServer server;
    QSignalSpy spy(&server, &TCPServer::tcpMessageReceived);

    // Connect to server using same port
    QTcpSocket client;
    client.connectToHost("127.0.0.1", 12345);
    QVERIFY(client.waitForConnected(1000));

    // Expected TCP Message
    QString expected = "TCP message sent at " + QTime::currentTime().toString();
    // QString expected = "Hello";
    client.write(expected.toUtf8());
    client.flush();

    QVERIFY(spy.wait(1000));
    QCOMPARE(spy.count(), 1);
    QString received = spy.takeFirst().at(0).toString();

    // Compare TCP Messages -- should pass
    QCOMPARE(received, expected);
}

/** 
 * @test Check for incorrect TCP message received
 * @brief Failing Test
 */
void TCPServerTest::testMessageDoesNotMatchExpected() {
    // Create server using Server Class
    TCPServer server;
    QSignalSpy spy(&server, &TCPServer::tcpMessageReceived);

    QTcpSocket client;
    client.connectToHost("127.0.0.1", 12345);
    QVERIFY(client.waitForConnected(1000));

    // Expected TCP Message
    QString actualMessage = "TCP message sent at " + QTime::currentTime().toString();
    client.write(actualMessage.toUtf8());
    client.flush();

    QVERIFY(spy.wait(1000));
    QCOMPARE(spy.count(), 1);

    QString received = spy.takeFirst().at(0).toString();

    // Expected Incorrect TCP message -- no text at beginning
    QString incorrectExpected = QTime::currentTime().toString();

    // Compare TCP Message -- Should fail
    QCOMPARE(received, incorrectExpected);
}

// Required for moc and to generate `main()`
QTEST_MAIN(TCPServerTest)
#include "tcpServerTest.moc"