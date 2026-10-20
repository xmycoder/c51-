#include "Com_util.h"
#include "Dir_UART.h"
#include <STC89C5xRC.H>
void main()
{
    char c;
    Dir_UART_Init();
    while (1)
    {
        // Dir_UART_SendStr("XMY");
        // Delayms(500);
        if (DIR_UART_RecevieChar(&c))
        {
            if (c == 'A')
            {
                P2 = 0x00;
                Dir_UART_SendStr("ok:LED is ok");
            }
            else if (c == 'B')
            {
                P2 = 0xff;
                Dir_UART_SendStr("ok:LED is ok");
            }
            else
            {
                Dir_UART_SendStr("Error:unknown command");
            }
        }
    }
}