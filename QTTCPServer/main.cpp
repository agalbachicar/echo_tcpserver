/**
 * @file    main.cpp
 * @author  Agustin Alba Chicar
 * @brief   Main source file. It creates and starts the server
 * @date    March, 2015
 */

//Includes
#include <QCoreApplication>
#include <QDebug>

#include <stdlib.h>

#include "atcpserver.h"


/**
 * @fn      main(int argc, char *argv[])
 * @param   argc
 * @param   argv
 * @return  the status of the program
 */
int main(int argc, char *argv[])
{
    //It starts the application to the Qt framework
    QCoreApplication a(argc, argv);
    //We create a server which listens to 10000 port
    ATcpServer server;
    server.setPort(quint16(10000));
    //We start the server
    if(server.startServer())
    {
        qDebug() << "It success to start";
    }
    else
    {
        qDebug() << "It fails to start";
    }

    //We run the application
    return a.exec();
}
