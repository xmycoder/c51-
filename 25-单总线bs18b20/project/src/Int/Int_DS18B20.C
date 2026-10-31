#include "Int_DS18B20.h"
#include "Dir_1Wire.h"
char Int_DS18B20_GetTemperature()
{
    u8 ls_byte;
    u8 ms_byte;
    // 初始化
    Dir_1Wire_Init();
    // 发送rom命令
    Dir_1Wire_WriteByte(0xcc);
    // 发送测温命令
    Dir_1Wire_WriteByte(0x44);

    // 低功耗每次都要唤醒
    // 初始化
    Dir_1Wire_Init();
    // 发送rom命令
    Dir_1Wire_WriteByte(0xcc);
    // 读取暂存器
    Dir_1Wire_WriteByte(0xbe);
    ls_byte = Dire_1Wire_ReadByte();
    ms_byte = Dire_1Wire_ReadByte();
    // 只获取整数部分

    return (ls_byte >> 4) | (ms_byte << 4);
}