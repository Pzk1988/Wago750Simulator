#include "wagomodule.h"
#include <QDebug>
#include <QTcpSocket>

WagoModule::WagoModule()
{
    server = new QTcpServer();
    modbusTcp = new ModbusTcp(slotVector);

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
}

void WagoModule::NewConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), SLOT(ReadReady()));
    connect(socket, SIGNAL(disconnected()), SLOT(Disconnect()));
    clientsList.append(socket);
    qDebug() << "Connected cliens " << clientsList.size();
}

void WagoModule::ReadReady()
{
     QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
     QByteArray array = socket->readAll();
     QByteArray* response = modbusTcp->HandlePacket(array);
     if( response != nullptr)
     {
         socket->write(response);
     }
}

void WagoModule::Disconnect()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    socket->close();
    socket->deleteLater();
    clientsList.removeOne(socket);
    qDebug() << "Connected cliens " << clientsList.size();
}
