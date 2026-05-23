#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\STD_TYPES.h"

/* Return codes */
#define UART_OK              0u
#define UART_ERR_OVERRUN     1u    /* Hardware overrun error detected  */
#define UART_ERR_FRAMING     2u    /* Framing error detected           */
#define UART_ERR_TIMEOUT     3u    /* No data received within timeout  */

/* ---- Public function prototypes ---- */

void UART_voidInit(void);

void UART_voidSendChar(unsigned char data);

void UART_voidSendString(const unsigned char *str);

void UART_voidSendNumber(unsigned int number);

unsigned char UART_u8ReceiveChar(unsigned char *received);

unsigned char UART_u8ReceiveCharTimeout(unsigned char *received);

void UART_voidClearErrors(void);

#endif /* UART_INTERFACE_H */