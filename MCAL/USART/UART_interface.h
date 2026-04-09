#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void UART_Init(void);
void UART_WriteChar(uint8 data);
void UART_WriteText(char *ptr_text); 

#endif