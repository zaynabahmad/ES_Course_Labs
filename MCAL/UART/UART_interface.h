#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_voidInit(void);
void UART_voidSendChar(unsigned char data);
unsigned char UART_u8ReceiveChar(void);

#endif