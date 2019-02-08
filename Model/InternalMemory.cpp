#include "InternalMemory.h"
#include "HelperClass.h"
#include <string.h>

InternalMemory::InternalMemory()
{
    // input modules
    memset(RegisterReadArea, 0x00, sizeof(quint16) * REGISTER_SIZE);

    // output modules
    memset(RegisterWriteArea, 0x00, sizeof(quint16) * REGISTER_SIZE);

    // Vesrion
    RegisterWriteArea[0x2010] = 0xCFD1;

    RegisterWriteArea[0x1024] = 0x0004;
    RegisterWriteArea[0x1025] = 0x0004;
}

bool InternalMemory::GetReadData(quint16 address, quint8* value, quint8 len)
{
    for(int i = 0; i < len; i++)
    {
        value[i * 2] = static_cast<quint8>(RegisterReadArea[address + i] >> 8);
        value[(i * 2) + 1] = static_cast<quint8>(RegisterReadArea[address + i]);
    }
    return true;
}

bool InternalMemory::SetReadData(quint16 address, quint16 *value, quint8 len)
{
    for(quint16 i = 0; i < len; i++)
    {
        RegisterReadArea[address + i] = value[i];
    }
    return true;
}

bool InternalMemory::GetWriteData(quint16 address, quint16 *value, quint8 len)
{
    for(quint16 i = 0; i < address + len; i++)
    {
        value[i] = RegisterWriteArea[i + address];
    }
    return true;
}

bool InternalMemory::SetWriteData(quint16 address, quint8 *value, quint8 len)
{
    quint16 leValue;
    for(quint16 i = 0; i < len; i++)
    {
        leValue = HelperClass::BeToUint16(value + (i*2));
        RegisterWriteArea[i + address] = leValue;
        emit OutputChanged(address + i, leValue);
    }
    return true;
}

