#include "ModbusTcp.h"
#include <QDebug>
#include "Utilities/HelperClass.h"

ModbusTcp::ModbusTcp(QVector<ISlot*> &slotList) : slotList(slotList)
{

}

ModbusTcp::~ModbusTcp()
{

}

QByteArray* ModbusTcp::HandleRequest(QByteArray &request)
{
    QByteArray* responseHeader = nullptr;
    QByteArray* responsePayload = nullptr;

    if( request.size() >= MODBUS_TCP_HEADER_LEN )
    {
        quint16 msgId = (request[0] << 8) | (request[1]);

        switch(request[7])
        {
            case READ_INPUT_REGS:
            {
                responsePayload = ReadInputRegisters(request);
                break;
            }
            case WRITE_REGS:
            {
                responsePayload = ReadInputRegisters(request);
                break;
            }
            default:
            {
                qDebug() << "Unknown message type";
            }
        }
    }
    return responseHeader;
}

QByteArray* ModbusTcp::ReadInputRegisters(QByteArray &request)
{
    qDebug() << "ReadInputRegisters";

    QByteArray* response = nullptr;
    quint16 len = HelperClass::BeToUint16(reinterpret_cast<quint8*>( &request.data()[4] ));

    if(len == 4 && request.size() == len + MODBUS_TCP_HEADER_LEN)
    {

    }
    return response;
}

QByteArray* ModbusTcp::WriteRegisters(QByteArray &request)
{
    qDebug() << "WriteRegisters";
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
