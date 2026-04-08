#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void UART_Init(void);

void UART_SendByte (unsigned char u8Data);
unsigned char UART_ReceiveByte(void);

// RAM string
void UART_SendString(char *str);

// ROM string (for literals)
void UART_SendString_ROM(const char code *str);

#endif