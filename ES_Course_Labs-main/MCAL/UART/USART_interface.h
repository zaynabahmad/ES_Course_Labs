#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"




// Initialize UART Transmitter
void UART_TX_init(void);

// Initialize UART Receiver (with interrupt)
void UART_RX_init(void);

// Send one byte
void UART_Write(u8 bits);

// Receive one byte (polling)
u8 UART_Read(void);

// Set callback function for UART interrupt
void UART_SetCallback(void (*callback)(u8));

// UART Interrupt Service Routine
void UART_ISR(void);


#endif
