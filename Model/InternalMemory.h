#ifndef INTERNALMEMORY_H
#define INTERNALMEMORY_H

#include <QObject>

class InternalMemory
{
public:
    InternalMemory();
    bool SetData(quint16 address, quint16 *value, quint8 len);
    bool GetData(quint16 address, quint16 *value, quint8 len);

private:
    quint16 RegisterReadArea[0xFFFF];
    quint16 RegisterWriteArea[0xFFFF];
};

#endif // INTERNALMEMORY_H
