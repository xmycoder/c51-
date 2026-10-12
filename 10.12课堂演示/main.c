#include <STC89C5xRC.H>
#include <intrins.h>
void Delay5000ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 36;
	j = 5;
	k = 211;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}




void main(){
	while(1){
			P21 = 0;
	Delay5000ms();
	P21 = 1;
	Delay5000ms();
		
		
	}


}