#include "Dir_Timer0.h"
#include <STC89C5xRC.H>

void main()
{
    Dir_Timer0_Init();
    while (1)
    {
        // Dir_Timer0_Handler();
        // 自动调用，不用手动写
    }
}