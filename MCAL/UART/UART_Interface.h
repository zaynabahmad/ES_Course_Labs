#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void UART_Init(void);
void UART_Write(u8 Data);
u8 UART_Read(void);
void UART_WriteString(const u8* String);
u8 UART_TX_Empty(void);

#endif
