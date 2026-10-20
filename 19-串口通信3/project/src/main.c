#include <STC89C5xRC.H>

void Uart1_Init(void) // 4800bps@11.0592MHz
{
    PCON &= 0x7F; // 波特率不倍速
    SCON = 0x50;  // 8位数据,可变波特率
    AUXR &= 0xBF; // 定时器时钟12T模式
    AUXR &= 0xFE; // 串口1选择定时器1为波特率发生器
    TMOD &= 0x0F; // 设置定时器模式
    TMOD |= 0x20; // 设置定时器模式
    TL1 = 0xFA;   // 设置定时初始值
    TH1 = 0xFA;   // 设置定时重载值
    ET1 = 0;      // 禁止定时器中断
    TR1 = 1;      // 定时器1开始计时

    // 打开中断
    EA = 1;
    ES = 1;
}

void UART_SentByte(unsigned char Byte)
{
    SBUF = Byte;
    while (TI == 0)
        ;   // 监视是否完成
    TI = 1; // 关闭发送
}

void main()
{
    Uart1_Init();
    // UART_SentByte(0x55);
    while (1)
    {
    }
}

// 接收数据需要中断系统
// 不知道什么时候发
void UART_Rountine() interrupt 4
{
    if (RI == 1)
    {
        // 读取Sbuf的值
        P2 = ~SBUF;
        // 需要软件复位
        UART_SentByte(SBUF); // 不可同时出现在主函数和中断函数当中
        RI = 0;
    }
}