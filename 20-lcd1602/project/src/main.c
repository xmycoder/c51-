#include "Lcd1602.h"
#include <STC89C5xRC.H>
void main()
{
    LCD_Init();
    LCD_ShowString(2, 3, "xmy");
    LCD_ShowNum(1, 1, 66, 2);
    LCD_ShowSignedNum(1, 4, -33, 2);
    LCD_ShowHexNum(1, 10, 0xa5, 2);
    LCD_ShowBinNumber(2, 6, 0xa5, 8);
    LCD_Showchar(2, 14, 0xdf);
    while (1)
    {
    }
}