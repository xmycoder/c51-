#include <STC89C5xRC.H>

sbit XPT2046_CS = P3 ^ 5;
sbit XPT2046_DCLK = P3 ^ 6;
sbit XPT2046_DIN = P3 ^ 4;
sbit XPT2046_DOUT = P3 ^ 7;

unsigned int XPT2046_ReadAD(unsigned char Command)
{
    unsigned char i;
    // 要有初始值
    unsigned int ADVAlue=0;
    XPT2046_DCLK = 0;
    XPT2046_CS = 0;
    for (i = 0; i < 8; i++)
    {
        /* code */
        XPT2046_DIN = Command & (0x80 >> i);
        XPT2046_DCLK = 1;
        XPT2046_DCLK = 0;
    }

    for (i = 0; i < 16; i++)
    {
        /* code */
        XPT2046_DCLK = 1;
        XPT2046_DCLK = 0;
        if (XPT2046_DOUT == 1)
        {
            ADVAlue |= (0x8000 >> i);
        }
    }
    XPT2046_CS = 1;
    if (Command & 0x08)
    {
        return ADVAlue >> 8;
    }
    else
    {
        return ADVAlue >> 4;
    }
}