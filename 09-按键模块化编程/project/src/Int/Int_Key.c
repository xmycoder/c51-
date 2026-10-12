#include "Int_Key.h"
#include <STC89C5xRC.H>
#include "Com_util.h"

#define K1 P31
#define K2 P30
#define K3 P32
#define K4 P33




bit Int_Key_IsK1Pressed()
{
    if (K1 == 0)
        {
            Delayms(10); // 消除前沿抖动
            if (K1 == 0)
            {
                while (K1 == 0)
                    ;        // 按键是否还在按下，等待按键释放
                Delayms(10); // 消除后延抖动
                return 1;
            }
        }
    return 0;
    
}

bit Int_Key_IsK2Pressed()
{
        if (K2 == 0)
        {
            Delayms(10); // 消除前沿抖动
            if (K2 == 0)
            {
                while (K2 == 0)
                    ;        // 按键是否还在按下，等待按键释放
                Delayms(10); // 消除后延抖动
                return 1;
            }
        }
    return 0;
}

bit Int_Key_IsK3Pressed()
{
        if (K3 == 0)
        {
            Delayms(10); // 消除前沿抖动
            if (K3 == 0)
            {
                while (K3 == 0)
                    ;        // 按键是否还在按下，等待按键释放
                Delayms(10); // 消除后延抖动
                return 1;
            }
        }
    return 0;
    
}

bit Int_Key_IsK4Pressed()
{
        if (K4 == 0)
        {
            Delayms(10); // 消除前沿抖动
            if (K4 == 0)
            {
                while (K4 == 0)
                    ;        // 按键是否还在按下，等待按键释放
                Delayms(10); // 消除后延抖动
                return 1;
            }
        }
    return 0;
}
