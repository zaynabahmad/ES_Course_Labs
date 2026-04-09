#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_voidInit(uint32 Copy_BaudRate);
void UART_voidTransmit(uint8 Copy_Data);
uint8 UART_u8Receive(void);

#endif