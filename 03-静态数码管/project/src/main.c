
#include<STC89C5xRC.H>
//共阴极数码管编码
// 共阴极数码管编码（高电平点亮）
unsigned char code CC_Table[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};
void fun(unsigned char w,unsigned char d){

}

void main(){
    // 位选
    P22 = 0;
    P23 = 1;
    P24 = 1;
    while(1){
        P0 = CC_Table[1];
    }
}