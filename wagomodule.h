#ifndef WAGOMODULE_H
#define WAGOMODULE_H

#include "wagomodule.h"

// Qt includes
#include <QThread>
#include <QTcpServer>
#include <QObject>

// Local includes
#include "modbus.h"
#include "ISlot.h"

class WagoModule: public QObject
{
    Q_OBJECT
public:
    WagoModule();

private:
    QTcpServer *server;
    QList<QTcpSocket*> clientsList;
    QVector<ISlot*> slotVector;

private slots:
    void NewConnection();
    void ReadReady();
    void Disconnect();


public slots:
    void DataChanged();

};

#endif // WAGOMODULE_H
