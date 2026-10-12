#include<STC89C5xRC.H>

#define K1 P31
#define K2 P30
#define K3 P32
#define K4 P33

#define LED1 P20
#define LED2 P21
#define LED3 P22
#define LED4 P23

void main(){

    while(1){

        // 理论上按键的电平正常切换，但是按键会有抖动
        if(K1==0){
            // 等待是否抬起
            while (K1==0);
            LED1 = ~LED1;
            
        }
        if(K2==0){
            // 等待是否抬起
            while (K2==0);
            LED2 = ~LED2;
            
        }
        if(K3==0){
            // 等待是否抬起
            while (K3==0);
            LED3 = ~LED3;
            
        }
        if(K4==0){
            // 等待是否抬起
            while (K4==0);
            LED4 = ~LED4;
            
        }
    }
}