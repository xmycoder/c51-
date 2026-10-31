#include "Int_8LED.h"
#include "Int_Key.h"
#include <STC89C5xRC.H>

// 计数器和比较值
unsigned char Counter, Compare;

void Timer0_Init(void) // 100微秒@11.0592MHz
{
    AUXR &= 0x7F; // 定时器时钟12T模式
    TMOD &= 0xF0; // 设置定时器模式
    TMOD |= 0x01;
    TL0 = 0xA4; // 设置定时初始值
    TH0 = 0xFF; // 设置定时初始值
    TF0 = 0;    // 清除TF0标志
    TR0 = 1;    // 定时器0开始计时

    // 开启定时器
    ET0 = 1;
    EA = 1;
    PT0 = 0;
}

void main()
{
    unsigned char speed;

    Timer0_Init();
    while (1)
    {
        bit keyNumber = Int_Key_IsK1Pressed();
        if (keyNumber == 1)
        {
            speed++;
            speed %= 4;
            if (speed == 0)
            {
                Compare = 0;
            }
            if (speed == 1)
            {
                Compare = 10;
            }
            if (speed == 2)
            {
                Compare = 75;
            }
            if (speed == 3)
            {
                Compare = 100;
            }
        }
        DigitalTube_DisplaySingle(0, speed);
    }
}

// 计数器
void Timer0_Routine() interrupt 1
{
    TL0 = 0xA4; // 设置定时初始值
    TH0 = 0xFF; // 设置定时初始值
    Counter++;
    Counter %= 100;
    if (Counter < Compare)
    {
        P10 = 1;
    }
    else
    {
        P10 = 0;
    }
}