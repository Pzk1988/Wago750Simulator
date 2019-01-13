#ifndef WAGOMODULE_H
#define WAGOMODULE_H

#include "WagoModule.h"

// Qt includes
#include <QTcpServer>
#include <QObject>

// Local includes
#include "ISlot.h"
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
    QVector<ISlot*> slotVector;
    ModbusTcp* modbusTcp;

private slots:
    void NewConnection();
    void ReadReady();
    void Disconnect();
};

#endif // WAGOMODULE_H
