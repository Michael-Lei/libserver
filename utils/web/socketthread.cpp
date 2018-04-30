#include "socketthread.h"

socketThread::socketThread(qintptr socketDescriptor, QObject *parent):
    QThread(parent), socketDescriptor(socketDescriptor){}

socketThread::~socketThread()
{
    *lstream << "Disconnected from " + tcpsocket->peerAddress().toString();
    tcpsocket->deleteLater();
    exit(0);
}

void socketThread::run()
{
    tcpsocket = new QTcpSocket();
    if (!tcpsocket->setSocketDescriptor(socketDescriptor))
    {
        *lstream << "Error: CANNOT set SocketDescriptor.";
        return;
    }
    *lstream << "New thread for the connection from " + tcpsocket->peerAddress().toString();
    //connect(tcpsocket, &QAbstractSocket::disconnected, this, &socketThread::disconnect);
    connect(tcpsocket, &QAbstractSocket::readyRead, this, &socketThread::Read);
    tcpsocket->write("Welcome to libserver!");
    tcpsocket->flush();
    tcpsocket->waitForDisconnected();
}

void socketThread::Read()
{
    char Data[1024];
    tcpsocket->readLine(Data, 1024);
    *lstream << "Get " + QString(Data);
}
