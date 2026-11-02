#include "Com_util.h"
#include "Int0.h"
#include "LCD1602.h"
#include <STC89C5xRC.H>

unsigned char Num;
void main()
{
    LCD_Init();
    LCD_ShowString(1, 1, "a");
    Int0_Init();
    while (1)
    {
        /* code */
        LCD_ShowNum(2, 1, Num, 3);
    }
}


// 使用外部中断0
void Int0_Rountine(void) interrupt 0
{
    // 给P32下降沿，按键k3
    Num++;
}