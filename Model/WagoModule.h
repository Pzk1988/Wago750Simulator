#ifndef WAGOMODULE_H
#define WAGOMODULE_H

#include "WagoModule.h"

// Qt includes
#include <QTcpServer>
#include <QObject>

// Local includes
#include "InternalMemory.h"
#include "ModbusTcp.h"

class WagoModule: public QObject
{
    Q_OBJECT
public:
    WagoModule();
    ~WagoModule();

private:
    QTcpServer *server;
    QList<QTcpSocket*> clientsList;
    InternalMemory internalMemory;
    ModbusTcp* modbusTcp;
    const int MAX_RESP_LEN = 300;

private slots:
    void NewConnection();
    void ReadReady();
    void Disconnect();

public slots:
    void InputChanged(quint16 value);

signals:
    void ConnectionStatus(bool status);
    void OutputChanged(quint8 slotId, quint16 value);
};

#endif // WAGOMODULE_H
