#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../SERVICES/types.h"

void UART_Configure(void);
void UART_TransmitString(unsigned char* str);
u8 UART_ReceiveByte(void);
void UART_TransmitString(u8* str);

#endif