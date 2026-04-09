#ifndef UART_H
#define UART_H

void UART_Init(void);
void UART_SendChar(void);
int  UART_ReceiveChar(void);
int  UART_DataAvailable(void);

#endif