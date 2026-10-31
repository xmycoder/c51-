#include <STC89C5xRC.H>

// 定义一个比较快的延时函数
void Delay(unsigned int t)
{
    while (t--)
        ;
}

void main()
{
    int Time, i;
    while (1)
    {
        // 占空比的周期不变
        for (Time = 0; Time < 100; Time++)
        {
            // 让每个占空比停留更久
            for (i = 0; i < 20; i++)
            {
                P20 = 0;
                Delay(Time);
                P20 = 1;
                Delay(100 - Time);
            }
        }
        for (Time = 100; Time > 0; Time--)
        {
            for (i = 0; i < 20; i++)
            {
                P20 = 0;
                Delay(Time);
                P20 = 1;
                Delay(100 - Time);
            }
        }
    }
}