#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_Init();
void UART_SendChar(char data);
char UART_ReceiveChar();

#endif