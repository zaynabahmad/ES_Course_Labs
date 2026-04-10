#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../SERVICES/std_types.h"

void UART_voidInit(void);
void UART_voidSendData(u8 copy_u8Data);
u8   UART_u8ReceiveData(void);
void UART_voidSendString(u8 *copy_u8String);

#endif