#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void UART_Init(void);
/* Changed 'data' to 'tx_byte' because 'data' is a reserved keyword in mikroC */
void UART_SendByte(u8 tx_byte);
void UART_SendString(const char *str);
void UART_SendNumber(u16 number);
void UART_SendTemperature(u16 temperatureC);

#endif