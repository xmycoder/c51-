#ifndef __LCD1602_H__
#define __LCD1602_H__

void LCD_Init();
void LCD_Showchar(unsigned char Line, unsigned char Column, unsigned char Char);
void LCD_ShowString(unsigned char Line, unsigned char Column, unsigned char String[]);
void LCD_ShowNum(unsigned char Line, unsigned char Column, unsigned char Length, int Number);
void LCD_ShowSignedNum(unsigned char Line, unsigned char Column, int Number, unsigned char LEngth);
void LCD_ShowHexNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);
void LCD_ShowBinNumber(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);
#endif // !1