/**
 * @file    atcpserver.h
 * @author  Agustin Alba Chicar
 * @brief   TCP Multithreaded Server Class
 * @date    March, 2015
 */
#ifndef ATCPSERVER_H
#define ATCPSERVER_H

//Includes
#include <QTcpServer>
#include "athread.h"

/**
 * @class   ATcpServer
 * @brief   The server class description.
 */
class ATcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit ATcpServer(QObject *parent = 0);
    void setPort(quint16 port);
    quint16 getPort();
    bool startServer();

signals:

public slots:
    void onNewConnection();

protected:

private:
    /**
     * @var     port
     * @brief   The port in which this server listens to connections
     */
    quint16 port;
};

#endif // ATCPSERVER_H
