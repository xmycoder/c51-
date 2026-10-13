#include "Int_Buzzer.h"
#include "Com_util.h"
#include <STC89C5xRC.H>
#define BUZZER P25

void Int_Buzzer_buzz()
{
    u8 count = 100;

    while (count--)
    {
        BUZZER = ~BUZZER;
        Delayms(1);
    }
}
