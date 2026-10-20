#include "Dir_UART.h"
#include <STC89C5xRC.H>

// 发送标志位
static bit s_is_sending = 0; // 0未在发送，1正在发送
static char s_bufffer = 0;

// 给s_buffer提供方法

void Dir_UART_Init()
{
    // 配置串口工作模式
    SM0 = 0;
    SM1 = 1;

    // 设置波特率
    // smod
    PCON &= 0x7f;
    // 定时器工作模式
    TMOD &= 0x0f;
    TMOD |= 0x20;
    // 初始值
    TL1 = 253;
    TH1 = 253;
    // 启动定时器
    TR1 = 1;

    // 接收数据相关配置
    REN = 1;
    SM2 = 0;

    // 串口中断相关配置
    EA = 1;
    ES = 1;
    RI = 0;
    TI = 0;
}

// 发送数据,直接buff等于要发送的数据就可以了

void Dir_UART_SendChar(char c)
{
    while (s_is_sending == 1)
        ;
    s_is_sending = 1;
    // 中断就发完了
    SBUF = c;
}

void Dir_UART_SendStr(char *s)
{
    // 取出字符的最后一位
    while (*s != '\0')
    {
        // 这样发送字符之间没有间隔
        Dir_UART_SendChar(*s);
        s++;
    }
}

bit DIR_UART_RecevieChar(char *c)
{
    if (s_bufffer)
    {
        *c = s_bufffer;
        s_bufffer = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

// 接收数据
void Dir_UART_Handler() interrupt 4
{
    // 接收数据
    // if (RI == 1)
    // {
    //     // 从sbuf拿出来数据
    //     if (SBUF == 'A')
    //     {
    //         P2 = 0x00;
    //         Dir_UART_SendStr("ok:LED is ok");
    //     }
    //     else if (SBUF == 'B')
    //     {
    //         Dir_UART_SendStr("0k:LED is off");
    //         P2 = 0xff;
    //     }
    //     else
    //     {
    //         Dir_UART_SendStr("Error:unknown command");
    //     }
    //     RI = 0;
    // }

    // 这里值处理接收数据然后处理
    if (RI == 1)
    {
        s_bufffer = SBUF;
        RI = 0;
    }
    // 发送数据
    if (TI == 1)
    {
        s_is_sending = 0;
        TI = 0;
    }
}