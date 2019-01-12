#ifndef ISLOT_H
#define ISLOT_H

#include <qobject.h>

class ISlot
{
public:
    virtual quint16 GetData(quint8 slotId) = 0;
    virtual void SetData(quint16 data, quint8 slotId) = 0;
};
#endif // ISLOT_H
