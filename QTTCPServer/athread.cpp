/**
 * @file    athread.cpp
 * @author  Agustin Alba Chicar
 * @brief   TCP Connection socket class description
 * @date    March, 2015
 */

//Includes
#include "athread.h"

/**
 * @fn      AThread::AThread(QTcpSocket *socket, QObject *parent)
 * @brief   The TCP socket thread class constructor
 * @param   socket
 * @param   parent
 */
AThread::AThread(QTcpSocket *socket, QObject *parent) :
    QThread(parent)
{
    this->socket = socket;
}

/**
 * @fn      AThread::run()
 * @brief   It connects the some signals and initializes the thread
 */
void AThread::run()
{
    qDebug() << "Thread [" << QThread::currentThreadId() << "]: connected.";

    //Check the socket reference
    if(this->socket == NULL)
    {
        //Socket pointer is wrong
        emit error(QString("socket is NULL"));
        return;
    }

    //We connect the socket reception of data and disconnection of the socket events
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    //Let the thread run in a loop
    exec();
}

/**
 * @fn      AThread::readyRead()
 * @brief   This function is thrown when the socket receives data. We echo it.
 */
void AThread::readyRead()
{
    //We read all the data of the socket
    QByteArray data = socket->readAll();
    //We echo the incomming data
    socket->write(data);
}

/**
 * @fn      AThread::disconnected()
 * @brief   This function is thrown when the socket is disconnected
 */
void AThread::disconnected()
{
    qDebug() << "Thread [" << QThread::currentThreadId() << "]: disconnected.";
    //It deletes later the instace of the socket
    socket->deleteLater();
    //Thread exit
    exit(0);
}
