#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/* 9600 baud @ 8MHz -> SPBRG = 51 */
#define FOSC            8000000UL
#define UART_BAUDRATE   9600UL
#define UART_SPBRG_VALUE    ((unsigned char)((FOSC / (16UL * UART_BAUDRATE)) - 1))

#endif
