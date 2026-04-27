#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_Init(void);
void UART_SendChar(char d);
char UART_ReceiveChar(void);
void UART_SendString(char* str);

#endif