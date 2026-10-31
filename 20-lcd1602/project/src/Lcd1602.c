#include "Lcd1602.h"
#include <Com_util.h>
#include <STC89C5xRC.H>

sbit LCD_RS = P2 ^ 6;
sbit LCD_RW = P2 ^ 5;
sbit LCD_EN = P2 ^ 7;

#define LCD_DataPort P0

// 写指令
void LCD_WriteCommand(unsigned char command)
{
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_DataPort = command;
    LCD_EN = 1;
    // 避免指令过快
    Delayms(1);
    LCD_EN = 0;
    Delayms(1);
}

// 写数据
void LCD_WriteData(unsigned char Data)
{
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_DataPort = Data;
    LCD_EN = 1;
    // 避免指令过快
    Delayms(1);
    LCD_EN = 0;
    Delayms(1);
}
void LCD_Init()
{
    LCD_WriteCommand(0x38);
    LCD_WriteCommand(0x0c);
    LCD_WriteCommand(0x06);
    LCD_WriteCommand(0x01);
}
// 设置光标位置
void LCD_SetCursor(unsigned char Line, unsigned char Column)
{
    if (Line == 1)
    {
        LCD_WriteCommand(0x80 | (Column - 1));
    }
    else
    {
        LCD_WriteCommand(0x80 | (Column - 1) + 0x40);
    }
}
void LCD_Showchar(unsigned char Line, unsigned char Column, unsigned char Char)
{
    // 把行和列变成实际的地址
    LCD_SetCursor(Line, Column);
    // 发送数据
    LCD_WriteData(Char);
}
void LCD_ShowString(unsigned char Line, unsigned char Column, unsigned char String[])
{
    unsigned char i;
    // 设置光标位置
    // 把行和列变成实际的地址
    LCD_SetCursor(Line, Column);

    // 写入数组
    for (i = 0; String[i] != 0; i++)
    {
        LCD_WriteData(String[i]);
    }
}
int LCD_Pow(int X, int Y)
{
    unsigned char i;
    int Restult = 1;
    for (i = 0; i < Y; i++)
    {
        Restult *= X;
    }
    return Restult;
}
// 显示数字
void LCD_ShowNum(unsigned char Line, unsigned char Column, unsigned char Number, int Length)
{
    unsigned char i;
    LCD_SetCursor(Line, Column);

    for (i = Length; i > 0; i--)
    {
        // 将数字转化成asccii的内容
        LCD_WriteData(0x30 + Number / LCD_Pow(10, i - 1) % 10);
    }
}

// 显示有符号的数字
void LCD_ShowSignedNum(unsigned char Line, unsigned char Column, int Number, unsigned char Length)
{
    unsigned char i;
    // 避免范围越界，有一个不能存
    unsigned int Number1;
    LCD_SetCursor(Line, Column);
    if (Number > 0)
    {
        LCD_WriteData('+');
        Number1 = Number;
    }
    else
    {
        LCD_WriteData('-');
        Number1 = -Number;
    }

    for (i = Length; i > 0; i--)
    {
        // 将数字转化成asccii的内容
        LCD_WriteData(0x30 + Number1 / LCD_Pow(10, i - 1) % 10);
    }
}

// 显示16进制数据
void LCD_ShowHexNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length)
{
    // 16进制a-f修改偏移
    unsigned char i, SingnedNumber;
    LCD_SetCursor(Line, Column);

    for (i = Length; i > 0; i--)
    {
        // 将数字转化成asccii的内容
        SingnedNumber = Number / LCD_Pow(16, i - 1) % 16;
        if (SingnedNumber < 10)
        {
            LCD_WriteData('0' + SingnedNumber);
        }
        else
        {
            LCD_WriteData('A' + SingnedNumber - 10);
        }
        // LCD_WriteData(0x30 + Number / LCD_Pow(10, i - 1) % 16);
    }
}

// 显示二进制数字
void LCD_ShowBinNumber(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length)
{
    unsigned char i;
    LCD_SetCursor(Line, Column);

    for (i = Length; i > 0; i--)
    {
        // 将数字转化成asccii的内容
        LCD_WriteData(0x30 + Number / LCD_Pow(2, i - 1) % 2);
    }
}