#include "InternalMemory.h"

InternalMemory::InternalMemory()
{
    // 4 input modules
    RegisterReadArea[0] = 0xAAAA;
    RegisterReadArea[1] = 0xAA88;
    RegisterReadArea[2] = 0x4CCC;
    RegisterReadArea[3] = 0xF0FF;

    // 4 output modules
    RegisterWriteArea[0x2000] = 0x0000;
    RegisterWriteArea[0x2001] = 0xFFFF;
    RegisterWriteArea[0x2002] = 0x1234;
    RegisterWriteArea[0x2003] = 0xAAAA;
    RegisterWriteArea[0x2004] = 0x5555;
    RegisterWriteArea[0x2005] = 0x7FFF;
    RegisterWriteArea[0x2006] = 0x8000;
    RegisterWriteArea[0x2007] = 0x3FFF;
    RegisterWriteArea[0x2008] = 0x4000;

    // Vesrion
    RegisterWriteArea[0x2010] = 0xCFD1;

    RegisterWriteArea[0x1024] = 0x0004;
    RegisterWriteArea[0x1025] = 0x0004;
}

bool InternalMemory::GetData(quint16 address, quint16 *value, quint8 len)
{
    for(quint16 i = 0; i < address + len; i++)
    {
        value[i] = RegisterReadArea[i + address];
    }
    return true;
}

bool InternalMemory::SetData(quint16 address, quint16 *value, quint8 len)
{
    for(quint16 i = 0; i < address + len; i++)
    {
        RegisterWriteArea[i + address] = value[i];
    }
    return true;
}
