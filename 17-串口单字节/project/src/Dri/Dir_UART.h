#ifndef __DIR_UART_H__
#define __DIR_UART_H__
void Dir_UART_Init();

void Dir_UART_SendChar(char c);
void Dir_UART_SendStr(char *s);

bit DIR_UART_RecevieChar(char *c);

#endif // !1