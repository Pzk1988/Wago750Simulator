#include "WagoModule.h"
#include <QDebug>
#include <QTcpSocket>
#include "WagoSlot.h"

WagoModule::WagoModule()
{
    server = new QTcpServer();
    modbusTcp = new ModbusTcp(internalMemory);

    connect(server, SIGNAL(newConnection()),
            this, SLOT(NewConnection()));

    connect(&internalMemory, SIGNAL(OutputChanged(quint8, quint16)),
            this, SIGNAL(OutputChanged(quint8,quint16)));

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
    quint8 response[MAX_RESP_LEN];
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    QByteArray request = socket->readAll();

    qint64 len = modbusTcp->HandleRequest(request, response);
    if( len != 0)
    {
        socket->write((const char*)response, len);
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

void WagoModule::InputChanged(quint16 value)
{
    WagoSlot* wagoSlot = static_cast<WagoSlot*>(QObject::sender());
    int slotId = wagoSlot->GetId();
    internalMemory.SetReadData(slotId, &value, 1);
}
