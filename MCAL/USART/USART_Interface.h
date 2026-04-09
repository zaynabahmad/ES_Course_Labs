#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "USART_Private.h"
#include "USART_Config.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

void UART_RX_Init(void);
void UART_TX_Init(void);
void UART_Write(u8 Data);
void UART_WriteString(const u8 *Str);
u8   UART_Read(void);
u8   UART_TX_Empty(void);
void UART_SetCallback(void (*Callback)(u8));
void UART_ISR(void);

#endif
