#include "Dir_Timer0.h"
#include <STC89C5xRC.H>

void Dir_Timer0_Init()
{
    // 启用定时器中断
    EA = 1;
    ET0 = 1;

    // 设置工作模式：Gate = 0 ,c/t =0,m1 = 0,m0 =1

    TMOD &= 0XF0;
    TMOD |= 0X01;

    // 设置初始值
    TL0 = 64614;
    TH0 = 64614 >> 8;

    // 启动定时器
    TR0 = 1;
}

void Dir_Timer0_Handler() interrupt 1
{
    static unsigned int count = 0;

    // 设置初始值
    TL0 = 64614;
    TH0 = 64614 >> 8;

    // 设置led
    count++;
    if (count >= 5000)
    {
        P20 = ~P20;
        count = 0;
    }
}
