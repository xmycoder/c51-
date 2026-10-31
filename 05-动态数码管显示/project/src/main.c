// #include<STC89C5xRC.H>
// typedef unsigned char u8;
// typedef unsigned long u32;
// static u8 s_digit_codes[10]={
//     0x3f,//0
//     0x06,//1
//     0x5b,//2
//     0x4f,//3
//     0x66,//4
//     0x6d,//5
//     0x7d,//6
//     0x07,//7
//     0x7f,//8
//     0x6f,//9
// };

// // 显存数组
// u8 buffer[8];

// /*
//     u8 position 片选，选择数字

//     u8 num_code 位选，选择想要的编码
// */

// void DigitalTube_DisplaySingle(u8 position,u8 num_code){
//     // 位选P22-P24,可以使用switch，case
//     //position 无符号8位，范围是0-7，只有二进制3位
//     //p2 00 00 00 000 0
//     //对position左移操作，将p2的对应位置至于0：与上f1
//     P0 = 0x00;
//     position<<=2;
//     P2 &= 0xe3;
//     P2 |= position;

//     //段选P0
//     P0 = num_code;

// }

// // 设置显存数组
// void DigitalTube_DisplayNum(u32 num){
//     //每次展示数据进行清空
//     u8 i;

//     for(i=0;i<8;i++){
//         buffer[i] = 0x00;
//     }
//     if (num==0){
//         buffer[7] = s_digit_codes[0];
//         return;
//     }
//     i=7;
//     while (num>0)
//     {
//         buffer[i] = s_digit_codes[num%10];
//         num /= 10;
//         i--;
//     }

// }

// // 动态扫描
// void DigitalTube_refresh(){
//     u8 i;
//     for(i=0;i<8;i++){
//         // DigitalTube_DisplaySingle(i,buffer[i]);
//         DigitalTube_DisplaySingle(7-i,buffer[i]);
//     }
// }

// void main(){
//     // 设置数组
//     DigitalTube_DisplayNum(1234);
//     while(1){
//         // 不断的循环遍历
//         DigitalTube_refresh();
//     }

// }

// #include <REGX52.H>

// //数码管段码表
// unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

// //延时子函数
// void Delay(unsigned int xms)
// {
// 	unsigned char i, j;
// 	while(xms--)
// 	{
// 		i = 2;
// 		j = 239;
// 		do
// 		{
// 			while (--j);
// 		} while (--i);
// 	}
// }

// //数码管显示子函数
// void Nixie(unsigned char Location,Number)
// {
// 	switch(Location)		//位码输出
// 	{
// 		case 1:P2_4=1;P2_3=1;P2_2=1;break;
// 		case 2:P2_4=1;P2_3=1;P2_2=0;break;
// 		case 3:P2_4=1;P2_3=0;P2_2=1;break;
// 		case 4:P2_4=1;P2_3=0;P2_2=0;break;
// 		case 5:P2_4=0;P2_3=1;P2_2=1;break;
// 		case 6:P2_4=0;P2_3=1;P2_2=0;break;
// 		case 7:P2_4=0;P2_3=0;P2_2=1;break;
// 		case 8:P2_4=0;P2_3=0;P2_2=0;break;
// 	}
// 	P0=NixieTable[Number];	//段码输出
// 	Delay(1);				//显示一段时间
// 	P0=0x00;				//段码清0，消影
// }

// void main()
// {
// 	while(1)
// 	{
// // 		Nixie(1,1);		//在数码管的第1位置显示1
// // //		Delay(20);
// // 		Nixie(2,2);		//在数码管的第2位置显示2
// // //		Delay(20);
// // 		Nixie(3,3);		//在数码管的第3位置显示3
// // //		Delay(20);
// 	}
// }

#include <STC89C5xRC.H>

// //数码管段码表
unsigned char NixieTable[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void fun(int a, int b)
{
    if (a == 1)
    {
        P22 = 0;
        P23 = 0;
        P24 = 0;
        P0 = NixieTable[b];
    }
    if (a == 2)
    {
        P22 = 1;
        P23 = 0;
        P24 = 0;
        P0 = NixieTable[b];
    }
}

void main()
{
    fun(3, 7);
    while (1)
    {
    }
}