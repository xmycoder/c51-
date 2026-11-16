#include <STC89C5xRC.H>

void main()
{

    while (1)
    {
        P17 = 0;
        if (P13 == 0)
        {
            P20 = ~P20;
        }
        if (P12 == 0)
        {
            P21 = ~P21;
        }
    }
}