#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Initialization */
void UART_RX_Init(void);
void UART_TX_Init(void);

/* Data Operations */
void UART_Write(u8 Data);
u8   UART_Read(void);

/* Pro Improvements: Multiple Bytes */
void UART_SendString(char* str);
void UART_SendNumber(s32 num);

/* Status & Interrupts */
u8   UART_TX_Empty(void);
void UART_SetCallback(void (*Callback)(u8));
void UART_ISR(void);

#endif