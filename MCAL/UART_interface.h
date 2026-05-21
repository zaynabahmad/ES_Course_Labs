/**
 * @file    UART_interface.h
 * @brief   Public API of the USART driver.
 */
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../SERVICES/Types.h"

/**
 * @brief  Bring up the USART for 8-N-1 asynchronous operation at the
 *         configured baud rate, then enable both transmitter and receiver.
 */
void vUART_Init(void);

/**
 * @brief  Send one byte, blocking until the transmit register can accept it.
 */
void vUART_SendByte(byte_t u8Data);

/**
 * @brief  Send a NUL-terminated string byte by byte.
 * @param  pcText  pointer to the string; a NULL_PTR is treated as empty.
 */
void vUART_SendString(const char *pcText);

/**
 * @brief  Receive one byte, blocking until a frame arrives.
 * @return the received byte.
 * @note   A pending overrun error is cleared first, otherwise the receiver
 *         would be wedged and never deliver another byte.
 */
byte_t u8UART_RecvByte(void);

/**
 * @brief  Test whether a received byte is waiting, without blocking.
 * @return FLAG_RAISED if a byte can be read now, FLAG_CLEARED otherwise.
 */
flag_t bUART_DataReady(void);

#endif /* UART_INTERFACE_H */
