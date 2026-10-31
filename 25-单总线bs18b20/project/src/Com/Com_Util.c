#include "Com_Util.h"
#include <INTRINS.H>

void Delay480us(void) //@11.0592MHz
{
    unsigned char data i;

    _nop_();
    i = 218;
    while (--i)
        ;
}

void Delay60us(void)	//@11.0592MHz
{
	unsigned char data i;

	i = 25;
	while (--i);
}

void Delay420us(void)	//@11.0592MHz
{
	unsigned char data i;

	i = 191;
	while (--i);
}
void Delay10us(void)	//@11.0592MHz
{
	unsigned char data i;

	i = 2;
	while (--i);
}

void Delay50us(void)	//@11.0592MHz
{
	unsigned char data i;

	_nop_();
	i = 20;
	while (--i);
}

void Delay500ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
