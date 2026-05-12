#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/* Baud rate register value.
   Formula (BRGH=1 high-speed): SPBRG = (Fosc / (16 * BaudRate)) - 1
   8 MHz Fosc, 9600 baud -> SPBRG = (8000000/(16*9600)) - 1 = 51 (0.16% error) */
#define UART_SPBRG_VALUE   51

/* High-speed baud rate mode: 1=BRGH set, 0=BRGH clear */
#define UART_HIGH_SPEED    1

#endif
