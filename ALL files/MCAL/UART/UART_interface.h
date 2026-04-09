#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/*
 * Function: UART_Init
 * -------------------
 * Initializes UART module:
 * - Sets baud rate
 * - Enables TX and RX
 */
void UART_Init(void);


/*
 * Function: UART_Write
 * --------------------
 * Sends one byte of data
 */
void UART_Write(u8 Data);


/*
 * Function: UART_Read
 * -------------------
 * Receives one byte (blocking)
 */
u8 UART_Read(void);


/*
 * Function: UART_WriteString
 * --------------------------
 * Sends a string until '\0'
 */
void UART_WriteString(const u8* String);


/*
 * Function: UART_TX_Empty
 * -----------------------
 * Checks if TX buffer is empty
 * Returns 1 if ready, 0 otherwise
 */
u8 UART_TX_Empty(void);

#endif