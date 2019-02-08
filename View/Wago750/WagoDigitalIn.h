#ifndef WAGODIGITALIN_H
#define WAGODIGITALIN_H

#include "WagoSlot.h"
#include "InOut.h"

class WagoDigitalIn : public WagoSlot
{
    Q_OBJECT
public:
    explicit WagoDigitalIn(QWidget *parent = nullptr);

protected:

private:
    static int globalId;

signals:
    void InputChanged(quint16);

public slots:
    void InputStateChange(bool state, int id);
};

#endif // WAGODIGITALIN_H
