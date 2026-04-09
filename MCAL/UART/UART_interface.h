#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void UART_Init(void);
void UART_SendChar(u8 byte);
u8   UART_ReceiveChar(void);
void UART_SendString(u8* str);

#endif