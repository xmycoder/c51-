#include <STC89C5xRC.H>
#include "Int_Key.h"

#define LED1 P20
#define LED2 P21
#define LED3 P22
#define LED4 P23



void main()
{
    while (1)
    {
        if(Int_Key_IsK1Pressed()){
            LED1 = ~LED1;
        }
             if(Int_Key_IsK2Pressed()){
            LED2 = ~LED2;
        }
                if(Int_Key_IsK3Pressed()){
            LED3 = ~LED3;
        }
                if(Int_Key_IsK4Pressed()){
            LED4 = ~LED4;
        }
       
    }
}
        