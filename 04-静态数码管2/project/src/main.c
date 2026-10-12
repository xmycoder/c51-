#include<STC89C5xRC.H>
typedef unsigned char u8;

static u8 s_digit_codes[10]={
    0x3f,//0
    0x06,//1
    0x5b,//2
    0x4f,//3
    0x66,//4
    0x6d,//5
    0x7d,//6
    0x07,//7
    0x7f,//8
    0x6f,//9
};
/* 
    u8 position 片选，选择数字

    u8 num_code 位选，选择想要的编码
*/

void DigitalTube_DisplaySingle(u8 position,u8 num_code){
    // 位选P22-P24,可以使用switch，case
    //position 无符号8位，范围是0-7，只有二进制3位
    //p2 00 00 00 000 0
    //对position左移操作，将p2的对应位置至于0：与上f1

    position<<=2;
    P2 &= 0xe3;
    P2 |= position;

    //段选P0
    P0 = s_digit_codes[num_code];
}


void main(){

    while(1){
        DigitalTube_DisplaySingle(3,5);
    }


}