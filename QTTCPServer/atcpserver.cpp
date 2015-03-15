/**
 * @file    atcpserver.cpp
 * @author  Agustin Alba Chicar
 * @brief   TCP Multithreaded server class implementation
 * @date    March, 2015
 */

//Includes
#include "atcpserver.h"

/**
 * @fn      ATcpServer::ATcpServer(QObject *parent)
 * @brief   The ATcpServer class constructor
 * @param   parent
 */
ATcpServer::ATcpServer(QObject *parent) :
    QTcpServer(parent)
{
    connect(this, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

/**
 * @fn      ATcpServer::setPort(quint16 port)
 * @brief   Getter
 * @param   port
 */
void ATcpServer::setPort(quint16 port)
{
    this->port = port;
}

/**
 * @fn      ATcpServer::getPort()
 * @brief   Setter
 * @retval  port
 */
quint16 ATcpServer::getPort()
{
    return this->port;
}

/**
 * @fn      ATcpServer::startServer()
 * @brief   It starts the server. It begins to linten to connections
 * @retval  true    if it success
 * @retval  flase   if it fails
 */
bool ATcpServer::startServer()
{
    return (this->listen(QHostAddress::Any, this->port));
}

/**
 * @fn      ATcpServer::onNewConnection()
 * @brief   It is called whenever there is a new connection. It creates a new AThread.
 */
void ATcpServer::onNewConnection()
{
    //Check for pending connections
    if(this->hasPendingConnections())
    {
        //It gets the client socket
        QTcpSocket *clientSocket = this->nextPendingConnection();
        //It creates the tcp connection thread
        AThread *thread = new AThread(clientSocket, this);
        //It release the destruction of the object to the Qt thread
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        //It starts the connection server
        thread->start();
    }
}
