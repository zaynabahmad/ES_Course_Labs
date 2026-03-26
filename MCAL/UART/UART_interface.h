#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void UART_Init9600(void);
void UART_WriteChar(u8 tx_byte);
void UART_WriteText(char *str);
void UART_WriteNewLine(void);
void UART_WriteU16(u16 number);
void UART_WriteTempCenti(u16 temp_x100);

#endif