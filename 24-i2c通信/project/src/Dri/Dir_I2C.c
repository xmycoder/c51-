
#include <STC89C5xRC.H>

sbit I2C_SCL = P2 ^ 1;
sbit I2C_SDA = P2 ^ 0;

// 初始化
void I2C_Start(void)
{
    I2C_SDA = 1;
    I2C_SCL = 1;
    I2C_SDA = 0;
    I2C_SCL = 0;
}

// 停止发送
void I2C_Stop(void)
{
    I2C_SDA = 0;
    I2C_SCL = 1;
    I2C_SDA = 1;
}

// 发送一个字节
void I2C_SendByte(unsigned char Byte)
{
    unsigned char i;

    for (i = 0; i < 8; i++)
    {
        I2C_SDA = Byte & (0x80 >> i); // 从高位开始发送
        I2C_SCL = 1;
        I2C_SCL = 0;
    }
}

// 接收一个字节
unsigned char I2C_Receive_Byte(void)
{
    unsigned char i, Byte = 0x00;
    I2C_SDA = 1;
    for (i = 0; i < 8; i++)
    {
        I2C_SCL = 1;
        if (I2C_SDA)
        {
            Byte |= (0x80 >> i);
        }
        I2C_SCL = 0;
    }

    return Byte;
}

// 发送应答
void I2C_SendAck(unsigned char AckBit)
{
    // 应答位
    I2C_SDA = AckBit;
    I2C_SCL = 1;
    I2C_SCL = 0;
}

// 接收应答
unsigned char I2C_ReceiveAck(void)
{
    unsigned char AckBit;
    // 释放sda
    I2C_SDA = 1;
    I2C_SCL = 1;

    AckBit = I2C_SDA;
    I2C_SCL = 0;
    return AckBit;
}