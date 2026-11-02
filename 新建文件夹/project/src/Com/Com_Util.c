#include "Com_Util.h"

void Delayms(int ms) 
{
    unsigned char data i, j;
    while (ms--)
    {
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j)
                ;
        } while (--i);
    }
}