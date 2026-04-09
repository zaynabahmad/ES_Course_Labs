#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/* Define your CPU's oscillator frequency in Hz */
#define FOSC 4000000

/* Define your desired Baud Rate */
#define UART_BAUDRATE 9600

/* Select Baud Rate Speed: 1 for High Speed, 0 for Low Speed */
#define UART_HIGH_SPEED 1

/* Automatically calculate the SPBRG value based on the settings above */
#if UART_HIGH_SPEED == 1
    #define SPBRG_VALUE ((FOSC / (16UL * UART_BAUDRATE)) - 1)
#else
    #define SPBRG_VALUE ((FOSC / (64UL * UART_BAUDRATE)) - 1)
#endif

#endif