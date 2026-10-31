#include "Dir_I2C.h"
#include <STC89C5xRC.H>

#define AT24C02_ADDRESS 0xA0

// 发送一个字节的数据
void AT24C02_WriteByte(unsigned char WordAddress, Data)
{
    unsigned char Ack;
    I2C_Start();

    // 写入地址
    I2C_SendByte(AT24C02_ADDRESS);
    // 接收应答,等于0就是接收应答
    I2C_ReceiveAck();
    // 写入字地址
    I2C_SendByte(WordAddress);
    I2C_ReceiveAck();
    // 写入数据
    I2C_SendByte(Data);
    I2C_ReceiveAck();
    I2C_Stop();
}

// 读取一个字节的数据
unsigned char AT24C02_ReadByte(unsigned char WordAddress)
{
    unsigned char Data;

    I2C_Start();
    I2C_SendByte(AT24C02_ADDRESS);
    I2C_ReceiveAck();
    I2C_SendByte(WordAddress);
    I2C_ReceiveAck();
    I2C_Start();
    // 从写变成读
    I2C_SendByte(AT24C02_ADDRESS | 0x01);
    I2C_ReceiveAck();
    Data = I2C_Receive_Byte();
    I2C_SendAck(1);
    I2C_Stop();
    return Data;
}