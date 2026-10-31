#ifndef __DS1302_H__
#define __DS1302_H__

void DS1302_Init(void);
void DS1302_WriteByter(unsigned char Command, Data);
unsigned char DS1302_ReadByte(unsigned char Command);

#endif // !__DS1302_H__