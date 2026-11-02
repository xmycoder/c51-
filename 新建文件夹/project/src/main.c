#include "Com_util.h"
#include "LCD1602.h"
#include "XPT204.h"
#include <STC89C5xRC.H>

unsigned int ADValue;
void main()
{
    LCD_Init();
    LCD_ShowString(1, 1, "ADJ NTC RG");

    while (1)
    {
        ADValue = XPT2046_ReadAD(XPT2046_XP_8);
        LCD_ShowNum(2, 1, ADValue, 3);
        Delayms(10);

        ADValue = XPT2046_ReadAD(XPT2046_YP_8);
        LCD_ShowNum(2, 5, ADValue, 3);
        Delayms(10);

        ADValue = XPT2046_ReadAD(XPT2046_VBAT_8);
        LCD_ShowNum(2, 9, ADValue, 3);
        Delayms(10);
    }
}