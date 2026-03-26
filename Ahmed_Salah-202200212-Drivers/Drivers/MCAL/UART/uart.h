#ifndef UART_H
#define UART_H

#include "../../SERVICES/Std_Types.h"

void UART_voidInit(void);
void UART_voidSendData(u8 copy_u8Data);
/* Matching the 'const char' change in .c file */
void UART_voidSendString(char *copy_pu8String);
u8   UART_u8ReceiveData(void);

#endif