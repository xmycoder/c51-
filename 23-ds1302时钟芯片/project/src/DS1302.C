#include "DS1302.h"
#include <STC89C5xRC.H>

sbit DS1302_SCLK = P3 ^ 6;
sbit DS1302_IO   = P3 ^ 4;
sbit DS1302_CE   = P3 ^ 5; // 使能

// 初始化
void DS1302_Init(void)
{
    DS1302_CE   = 0;
    DS1302_SCLK = 0;
    DS1302_WriteByter(0x8E, 0x00);
}

// 单字节写入
// command传入的命令
void DS1302_WriteByter(unsigned char Command, Data)
{
    unsigned char i;
    DS1302_CE = 1;

    // 写入指令
    for (i = 0; i < 8; i++) {
        DS1302_IO = Command & (0x01 << i);
        // 上升沿有效
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    // 写入数据
    for (i = 0; i < 8; i++) {
        DS1302_IO = Data & (0x01 << i);
        // 上升沿有效
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    DS1302_CE = 0;
}

// 单字节读出
unsigned char DS1302_ReadByte(unsigned char Command)
{
    unsigned char i, Data = 0x00;
    DS1302_CE = 1;

    // 读指令
    for (i = 0; i < 8; i++) {
        DS1302_IO = Command & (0x01 << i);
        // 上升沿有效
        DS1302_SCLK = 0;
        DS1302_SCLK = 1;
    }

    // 读数据下降沿有效
    for (i = 0; i < 8; i++) {
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
        // 从io口读取数据
        if (DS1302_IO) {
            Data = Data | (0x01 << i);
        }
    }

    // 关闭使能
    DS1302_CE = 0;

    return Data;
}