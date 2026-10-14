#include "Com_util.h"
#include <STC89C5xRC.H>

// 自定义外部中断
void INT0_Init()
{
    // 启用中断
    EA = 1; // 中断总开关
    // 中断源设置
    EX0 = 1;

    // 触发方式,下降沿
    IT0 = 1;
}

void main()
{
    // 初始化
    INT0_Init();
    while (1)
    {
    }
}

// 设置中断函数
void INT0_Handler() interrupt 0
{
    // 跳过前沿抖动
    Delayms(10);
    if (P32 == 0)
    {
        P20 = ~P20;
    }
}