/**
 * @file    athread.h
 * @author  Agustin Alba Chicar
 * @brief   TCP Connection thread
 * @date    March, 2015
 */
#ifndef ATHREAD_H
#define ATHREAD_H

//Includes
#include <QThread>
#include <QTcpSocket>
#include <QByteArray>
#include <QDebug>

/**
 * @class   AThread
 * @brief   The TCP thread class
 */
class AThread : public QThread
{
    Q_OBJECT
public:
    explicit AThread(QTcpSocket *socket, QObject *parent = 0);
    void run();

signals:
    void error(QString string);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
};

#endif // ATHREAD_H
