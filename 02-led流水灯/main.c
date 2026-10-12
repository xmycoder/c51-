#include <STC89C5xRC.H>
#include <intrins.h>
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



void main(){
	
	P2 = 0XFE;
	Delay500ms();
	while(1){
	if(P2 == 0X00){
		P2 = 0XFF;
		Delay500ms();
		P2 = 0XFE;
		Delay500ms();
	}
	P2 = (P2<<1);
	Delay500ms();
	}

}