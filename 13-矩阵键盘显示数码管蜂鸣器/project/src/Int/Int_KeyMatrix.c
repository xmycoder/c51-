#include "Int_KeyMatrix.h"
#include <STC89C5xRC.H>

u8 Int_KeyMatrix_CheckSW()
{
    // 第一行
    P17 = 0;
    P16 = 1;
    P15 = 1;
    P14 = 1;
    if (P17 == 0)
    {
        if (P13 == 0)
        {
            Delayms(10);
            while (P13 == 0)
                ;
            Delayms(10);
            return 1;
        }
        if (P12 == 0)
        {
            Delayms(10);
            while (P12 == 0)
                ;
            Delayms(10);
            return 2;
        }
        if (P11 == 0)
        {
            Delayms(10);
            while (P11 == 0)
                ;
            Delayms(10);
            return 3;
        }
        if (P10 == 0)
        {
            Delayms(10);
            while (P10 == 0)
                ;
            Delayms(10);
            return 4;
        }
    }

    // 第二行
    P17 = 1;
    P16 = 0;
    P15 = 1;
    P14 = 1;
    if (P16 == 0)
    {
        if (P13 == 0)
        {
            Delayms(10);
            while (P13 == 0)
                ;
            Delayms(10);
            return 5;
        }
        if (P12 == 0)
        {
            Delayms(10);
            while (P12 == 0)
                ;
            Delayms(10);
            return 6;
        }
        if (P11 == 0)
        {
            Delayms(10);
            while (P11 == 0)
                ;
            Delayms(10);
            return 7;
        }
        if (P10 == 0)
        {
            Delayms(10);
            while (P10 == 0)
                ;
            Delayms(10);
            return 8;
        }
    }

    // 第三行
    P17 = 1;
    P16 = 1;
    P15 = 0;
    P14 = 1;
    if (P15 == 0)
    {
        if (P13 == 0)
        {
            Delayms(10);
            while (P13 == 0)
                ;
            Delayms(10);
            return 9;
        }
        if (P12 == 0)
        {
            Delayms(10);
            while (P12 == 0)
                ;
            Delayms(10);
            return 10;
        }
        if (P11 == 0)
        {
            Delayms(10);
            while (P11 == 0)
                ;
            Delayms(10);
            return 11;
        }
        if (P10 == 0)
        {
            Delayms(10);
            while (P10 == 0)
                ;
            Delayms(10);
            return 12;
        }
    }

    // 第四行
    P17 = 1;
    P16 = 1;
    P15 = 1;
    P14 = 0;
    if (P14 == 0)
    {
        if (P13 == 0)
        {
            Delayms(10);
            while (P13 == 0)
                ;
            Delayms(10);
            return 13;
        }
        if (P12 == 0)
        {
            Delayms(10);
            while (P12 == 0)
                ;
            Delayms(10);
            return 14;
        }
        if (P11 == 0)
        {
            Delayms(10);
            while (P11 == 0)
                ;
            Delayms(10);
            return 15;
        }
        // 第四行第4列：P14 是行输出，不能再用 P14 判断列，应该是别的列引脚
        // 假设第4列是 P10（请根据你的实际电路修改）
        if (P10 == 0)
        {
            Delayms(10);
            while (P10 == 0)
                ;
            Delayms(10);
            return 16;
        }
    }

    return 0;
}