#include "WagoModule.h"
#include <QDebug>
#include <QTcpSocket>

WagoModule::WagoModule()
{
    server = new QTcpServer();
    modbusTcp = new ModbusTcp(internalMemory);

    connect(server, SIGNAL(newConnection()),
                     this, SLOT(NewConnection()));
    if(!server->listen(QHostAddress::Any, 802))
    {
        qDebug() << "Could not start tcp server";
    }
    else
    {
        qDebug() << "Connected to server";
    }
    emit ConnectionStatus(false);
}

WagoModule::~WagoModule()
{
    server->close();
    server->deleteLater();
    delete server;

    delete modbusTcp;
}

void WagoModule::NewConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), SLOT(ReadReady()));
    connect(socket, SIGNAL(disconnected()), SLOT(Disconnect()));
    clientsList.append(socket);
    emit ConnectionStatus(true);
    qDebug() << "Connected cliens " << clientsList.size();
}

void WagoModule::ReadReady()
{
     QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
     QByteArray array = socket->readAll();
     QByteArray* response = modbusTcp->HandleRequest(array);
     if( response != nullptr)
     {
         socket->write(*response);
         delete response;
     }
}

void WagoModule::Disconnect()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    socket->close();
    socket->deleteLater();
    clientsList.removeOne(socket);
    qDebug() << "Connected cliens " << clientsList.size();

    if(clientsList.size() == 0)
    {
        emit ConnectionStatus(false);
    }
}
