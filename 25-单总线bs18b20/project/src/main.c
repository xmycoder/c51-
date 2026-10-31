#include "Int_DS18B20.h"
#include "LCD1602.h"
#include <Com_Util.h>
#include <STC89C5xRC.H>

void main()
{
    LCD_Init();

    while (1)
    {
        /* code */
        LCD_ShowNum(1, 1, Int_DS18B20_GetTemperature(), 2);
        Delay500ms();
    }
}