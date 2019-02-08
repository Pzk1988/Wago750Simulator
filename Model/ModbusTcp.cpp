#include "ModbusTcp.h"
#include <QDebug>
#include "Utilities/HelperClass.h"

ModbusTcp::ModbusTcp(InternalMemory &internalMemory) : internalMemory(internalMemory)
{

}

ModbusTcp::~ModbusTcp()
{

}

quint64 ModbusTcp::HandleRequest(QByteArray &request, quint8* response)
{
    quint64 respLen = 0;
    if( request.size() >= MODBUS_TCP_HEADER_LEN )
    {
        switch(request[7])
        {
            case READ_INPUT_REGS:
            {
                respLen = ReadInputRegisters(request, &response[9]);

                response[0] = request[0];
                response[1] = request[1];
                response[2] = request[2];
                response[3] = request[3];
                response[4] = 0;
                response[5] = 3 + 2*respLen;
                response[6] = request[6];
                response[7] = request[7];
                response[8] = 2*respLen;
                return 9 + 2*respLen;
            }
            case WRITE_REGS:
            {
                respLen = WriteMultipleRegisters(request);

                response[0] = request[0];
                response[1] = request[1];
                response[2] = request[2];
                response[3] = request[3];
                response[4] = 0;
                response[5] = 6;
                response[6] = request[6];
                response[7] = request[7];
                response[8] = request[8];
                response[9] = request[9];
                response[10] = request[10];
                response[11] = request[11];
                return 12;
            }
            default:
            {
                qDebug() << "Unknown message type";
            }
        }
    }
    return 0;
}

quint64 ModbusTcp::ReadInputRegisters(QByteArray &request, quint8* pData)
{
    quint16 len = HelperClass::BeToUint16(reinterpret_cast<quint8*>( &request.data()[4] ));

    if(len == 4 && request.size() == len + MODBUS_TCP_HEADER_LEN)
    {
        quint16 registerAddress = HelperClass::BeToUint16( reinterpret_cast<quint8*>( &request.data()[8] ));
        quint16 registerNumber = HelperClass::BeToUint16( reinterpret_cast<quint8*>( &request.data()[10] ));
        qDebug().nospace() << "ReadInputRegisters: 0x" << hex << registerAddress << ", number: " << registerNumber;

        if( (quint32)registerAddress + registerNumber <= 0xFFFF )
        {
            internalMemory.GetReadData(registerAddress, pData, registerNumber);
            return registerNumber;
        }

    }
    return 0;
}

quint64 ModbusTcp::WriteMultipleRegisters(QByteArray &request)
{
    quint16 len = HelperClass::BeToUint16(reinterpret_cast<quint8*>( &request.data()[4] ));

    if(request.size() == len + 6)
    {
        quint16 registerAddress = HelperClass::BeToUint16( reinterpret_cast<quint8*>( &request.data()[8] ));
        quint16 registerNumber = HelperClass::BeToUint16( reinterpret_cast<quint8*>( &request.data()[10] ));
        qDebug().nospace() << "WriteMultipleRegisters: 0x" << hex << registerAddress << ", number: " << registerNumber;

        if( (quint32)registerAddress + registerNumber <= 0xFFFF )
        {
            internalMemory.SetWriteData(registerAddress, reinterpret_cast<quint8*>(&request.data()[13]), registerNumber);
            return registerNumber;
        }

    }
    return 0;
}
/*Transaction identifier 	0,1       For synchronization between messages of server and client
Protocol identifier       2,3       0 for Modbus/TCP
Length field              4,5       Number of remaining bytes in this frame
Unit identifier           6        Slave address (255 if not used)
Function code         	7       Function codes as in other variants
Data bytes                8    	Data as response or commands*/

/*Function code 4 (read input registers) and function code 3 (read holding registers)
Request:

    Address of first register to read (16-bit)
    Number of registers to read (16-bit)
Normal response:

    Number of bytes of register values to follow (8-bit)
    Register values (16 bits per register)*/
