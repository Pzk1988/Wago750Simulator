#ifndef WAGODIGITALOUT_H
#define WAGODIGITALOUT_H

#include "WagoSlot.h"
#include "InOut.h"

class WagoDigitalOut : public WagoSlot
{
    Q_OBJECT
public:
    explicit WagoDigitalOut(QWidget *parent = nullptr);
    bool GetState(int id);
    void SetState(int id, bool state);
    void SetState(quint16 value);

protected:

private:
    static int globalId;

signals:
public slots:
};

#endif // WAGODIGITALOUT_H
