#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../SERVICES/std_types.h"

void UART_voidInit(u32 Copy_u32BaudRate);
void UART_voidSendData(u8 Copy_u8Data);
u8   UART_u8ReceiveData(void);
void UART_voidSendString(char* Copy_pchString);

#endif