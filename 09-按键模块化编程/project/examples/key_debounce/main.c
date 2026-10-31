/* 独立 Keil C51 示例：加入本目录 main.c、key.c，不与原工程的 main.c 同时编译。 */
#include <STC89C5xRC.H>
#include "key.h"

sbit KEY1_PIN = P3 ^ 1;  /* 按键另一端接 GND，P3.1 需上拉，按下读到 0。 */
sbit LED_PIN = P2 ^ 0;   /* 示例假设 LED 低电平点亮，接线需串联限流电阻。 */

static Key key1;
/* 由中断修改、主循环读取，volatile 防止编译器把读取优化成旧值。 */
static volatile unsigned long system_ms = 0;

/* C51 的 sbit 无法取普通指针，通过读取函数把实际引脚接入通用库。 */
unsigned char ReadKey1(void)
{
    return KEY1_PIN;
}

/* 示例占用 Timer0；已有毫秒时基时可直接复用，不要重复配置同一定时器。 */
void Timer0_Init(void)
{
    TR0 = 0;
    TMOD = (TMOD & 0xF0) | 0x01;  /* 保留 Timer1 配置，Timer0 选择 16 位模式1。 */
    /* 11.0592 MHz、12T：每毫秒约 922 次计数，初值 65536-922=0xFC66。 */
    TH0 = 0xFC;
    TL0 = 0x66;
    TF0 = 0;
    ET0 = 1;
    TR0 = 1;
    EA = 1;
}

/* interrupt 1 是 Keil C51 的 Timer0 中断声明，不能直接用普通 GCC 编译。 */
void Timer0_ISR(void) interrupt 1
{
    /* 模式1需软件重装初值，中断响应和重装耗时会使实际周期略长于 1ms。 */
    TH0 = 0xFC;
    TL0 = 0x66;
    system_ms++;
}

unsigned long GetMillis(void)
{
    unsigned long now_ms;
    bit previous_ea;

    /* 8051 不能原子读取 32 位计数，快照期间屏蔽中断，避免读到拼接的新旧值。 */
    previous_ea = EA;
    EA = 0;
    now_ms = system_ms;
    EA = previous_ea;  /* 恢复原中断状态，而不是无条件开中断。 */
    return now_ms;
}

void main(void)
{
    KEY1_PIN = 1;  /* STC89 准双向口先写 1，允许外部按键把引脚拉低。 */
    LED_PIN = 1;
    /* &key1 是状态对象地址；ReadKey1 不加括号，传入函数而非当前电平。 */
    Key_Init(&key1, ReadKey1, 0, 20);  /* 低电平有效，按下和松开都需稳定 20ms。 */
    Timer0_Init();

    while (1)
    {
        /* 持续采样即可，不用 Delayms 或等待松手；循环内不要加入长时间阻塞。 */
        Key_Update(&key1, GetMillis());
        if (Key_TakePressed(&key1))
        {
            LED_PIN = !LED_PIN;  /* 每次确认按下翻转一次，保持按住不会连续翻转。 */
        }
    }
}
