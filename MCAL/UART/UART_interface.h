#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void UART_voidInit(void);
void UART_voidTransmit(u8 Copy_u8Data);
u8 UART_u8Receive(void);

#endif