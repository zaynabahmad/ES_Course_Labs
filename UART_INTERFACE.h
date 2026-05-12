#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../SERVICES/STD_TYPES.h"

void UART_Init(void);
void UART_SendByte(u8 data);
u8   UART_ReceiveByte(void);
void UART_SendString(u8 *str);
u8   UART_IsDataAvailable(void);

#endif
