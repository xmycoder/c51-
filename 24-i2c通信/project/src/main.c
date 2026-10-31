// at24c02数据存储

#include "Com_util.h"
#include "Int_AT24c02.h"
#include "Int_Key.h"
#include "LCD1602.h"
#include <STC89C5xRC.H>
unsigned char Data;
void main()
{
    LCD_Init();
    // LCD_ShowString(1, 1, "hello");
    // AT24C02_WriteByte(0, 0);
    AT24C02_WriteByte(1, 66);
    Delayms(5);
    Data = AT24C02_ReadByte(1);
    LCD_ShowNum(1, 1, Data, 3);
    while (1)
    {
    }
}