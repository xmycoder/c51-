#include "Dir_1Wire.h"
#include "Com_Util.h"
#include <STC89C5xRC.H>

#define DQ P37
bit Dir_1Wire_Init()
{
    bit result;
    DQ = 0;
    Delay480us();
    // 释放dq
    DQ = 1;
    // 延时60us
    Delay60us();
    // 等于0存在，等于1不做在
    result = ~DQ;
    Delay420us();

    return result;
}

void Dir_1Wire_WriteByte(u8 byte)
{
    u8 i;

    // 写字节从低位开始
    for (i = 0; i < 8; i++)
    {
        // 拉低dq
        DQ = 0;
        DQ = byte & 0x01;
        byte >>= 1;
        Delay60us();
        DQ = 1;
    }
}

u8 Dire_1Wire_ReadByte()
{
    u8 byte = 0x00;
    u8 i;
    for (i = 0; i < 8; i++)
    {
        DQ = 0;
        // 释放dq
        DQ = 1;
        Delay10us();
        byte >>= 1;
        if (DQ == 1)
        {
            byte |= 0x80;
        }

        Delay50us();
    }
    return byte;
}
