#include "Com_util.h"
#include "DS1302.h"
#include "LCD1602.h"
#include <STC89C5xRC.H>
unsigned char Secoend;

void main()
{
    // 需要改跳线帽
    // 初始化lcd

    LCD_Init();
    LCD_ShowString(1, 1, "RTC");

    // 初始化ds1302
    DS1302_Init();

    // 写入数据
    DS1302_WriteByter(0x80, 0x30);

    while (1)
    {
        /* code */
        Secoend = DS1302_ReadByte(0x81);
        LCD_ShowNum(2, 1, Secoend, 3);
        `
    }
}