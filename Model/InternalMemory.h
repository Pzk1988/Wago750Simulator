#ifndef INTERNALMEMORY_H
#define INTERNALMEMORY_H

#include <QObject>

class InternalMemory : public QObject
{
    Q_OBJECT
public:
    InternalMemory();
    bool SetReadData(quint16 address, quint16 *value, quint8 len);
    bool GetReadData(quint16 address, quint8 *value, quint8 len);
    bool SetWriteData(quint16 address, quint8 *value, quint8 len);
    bool GetWriteData(quint16 address, quint16 *value, quint8 len);

private:
    static const int REGISTER_SIZE = 0xFFFF;
    quint16 RegisterReadArea[REGISTER_SIZE];
    quint16 RegisterWriteArea[REGISTER_SIZE];

signals:
    void OutputChanged(quint8 slotId, quint16 value);
};

#endif // INTERNALMEMORY_H
