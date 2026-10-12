#include "Com_util.h"
#include "Int_KeyMatrix.h"
#include <STC89C5xRC.H>
void main()
{
    u8 key;

    while (1)
    {
        key = Int_KeyMatrix_CheckSW();
        if (key)
        {
            P20 = ~P20;
        }
    }
}