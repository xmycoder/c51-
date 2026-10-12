#include<STC89C5xRC.H>
typedef unsigned char u8;
typedef unsigned long u32;
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

// 显存数组
u8 buffer[8];


/* 
    u8 position 片选，选择数字

    u8 num_code 位选，选择想要的编码
*/

void DigitalTube_DisplaySingle(u8 position,u8 num_code){
    // 位选P22-P24,可以使用switch，case
    //position 无符号8位，范围是0-7，只有二进制3位
    //p2 00 00 00 000 0
    //对position左移操作，将p2的对应位置至于0：与上f1
    P0 = 0x00;
    position<<=2;
    P2 &= 0xe3;
    P2 |= position;

    //段选P0
    P0 = num_code;

}

// 设置显存数组
void DigitalTube_DisplayNum(u32 num){
    //每次展示数据进行清空
    u8 i;

    for(i=0;i<8;i++){
        buffer[i] = 0x00;
    }
    if (num==0){
        buffer[7] = s_digit_codes[0];
        return;
    }
    i=7;
    while (num>0)
    {
        buffer[i] = s_digit_codes[num%10];
        num /= 10;
        i--;
    }
    

}

// 动态扫描
void DigitalTube_refresh(){
    u8 i;
    for(i=0;i<8;i++){
        // DigitalTube_DisplaySingle(i,buffer[i]);
        DigitalTube_DisplaySingle(7-i,buffer[i]);
    }
}

void main(){
    // 设置数组
    DigitalTube_DisplayNum(1234);
    while(1){
        // 不断的循环遍历
        DigitalTube_refresh();
    }


}