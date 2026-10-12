#include <INTRINS.H>
#include <STC89C5xRC.H>

#define K1 P31
#define K2 P30
#define K3 P32
#define K4 P33

#define LED1 P20
#define LED2 P21
#define LED3 P22
#define LED4 P23

void Delayms(int ms) //@11.0592MHz
{
    unsigned char data i, j;
    while (ms--)
    {
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j)
                ;
        } while (--i);
    }
}

void main()
{

    while (1)
    {

        if (K1 == 0)
        {
            Delayms(10); // 消除前沿抖动
            if (K1 == 0)
            {
                while (K1 == 0)
                    ;        // 按键是否还在按下，等待按键释放
                Delayms(10); // 消除后延抖动
                LED1 = ~LED1;
            }
        }
        if (K2 == 0)
        {
            Delayms(10); // 消除前沿抖动
            if (K2 == 0)
            {
                while (K2 == 0)
                    ;        // 按键是否还在按下，等待按键释放
                Delayms(10); // 消除后延抖动
                LED2 = ~LED2;
            }
        }
        if (K3 == 0)
        {
            Delayms(10); // 消除前沿抖动
            if (K3 == 0)
            {
            while (K3 == 0);        // 按键是否还在按下，等待按键释放
            Delayms(10); // 消除后延抖动
            LED3 = ~LED3;
        }
    }
        if (K4 == 0)
        {
            Delayms(10); // 消除前沿抖动
            if (K4 == 0)
            {
             while (K4 == 0);        // 按键是否还在按下，等待按键释放
                    Delayms(10); // 消除后延抖动
                    LED4 = ~LED4;
                    }
                }
            }
}
        