#ifndef MODBUSTCP_H
#define MODBUSTCP_H

#include <QObject>
#include "internalmemory.h"

class ModbusTcp
{
    static const int MAX_MSG_LENGTH = 260;
    static const int MODBUS_TCP_HEADER_LEN = 8;

    ///Function Code
    enum{
        READ_COILS       = 0x01,
        READ_INPUT_BITS  = 0x02,
        READ_REGS        = 0x03,
        READ_INPUT_REGS  = 0x04,
        WRITE_COIL       = 0x05,
        WRITE_REG        = 0x06,
        WRITE_COILS      = 0x0F,
        WRITE_REGS       = 0x10,
    };

    ///Exception Codes
    enum {
        EX_ILLEGAL_FUNCTION = 0x01, // Function Code not Supported
        EX_ILLEGAL_ADDRESS  = 0x02, // Output Address not exists
        EX_ILLEGAL_VALUE    = 0x03, // Output Value not in Range
        EX_SERVER_FAILURE   = 0x04, // Slave Deive Fails to process request
        EX_ACKNOWLEDGE      = 0x05, // Service Need Long Time to Execute
        EX_SERVER_BUSY      = 0x06, // Server Was Unable to Accept MB Request PDU
        EX_GATEWAY_PROBLEMP = 0x0A, // Gateway Path not Available
        EX_GATEWYA_PROBLEMF = 0x0B, // Target Device Failed to Response
    };

public:
    ModbusTcp(InternalMemory &internalMemory);
    ~ModbusTcp();
    quint64 HandleRequest(QByteArray &request, quint8* response);

private:
    InternalMemory &internalMemory;
    //    void modbus_read_coils(int address, int amount, bool* buffer);
    //    void modbus_read_input_bits(int address, int amount, bool* buffer);
    //    void modbus_read_holding_registers(int address, int amount, uint16_t *buffer);
    quint64 ReadInputRegisters(QByteArray &request, quint8 *pData);

    //    void modbus_write_coil(int address, bool to_write);
    //    void modbus_write_register(int address, uint16_t value);
    //    void modbus_write_coils(int address, int amount, bool* value );
    quint64 WriteMultipleRegisters(QByteArray &request);
};

#endif // MODBUSTCP_H
