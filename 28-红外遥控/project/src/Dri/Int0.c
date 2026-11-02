#include <STC89C5xRC.H>

void Int0_Init(void)
{
    // 配置外部中断
    // 触发方式
    IT0 = 1; // 1下降沿，0低电平
    IE0 = 0;
    EX0 = 1;
    EA = 1;
    // 中断优先级，最高
    PX0 = 1;
}

