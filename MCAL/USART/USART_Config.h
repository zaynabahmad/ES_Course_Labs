#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/* CPU Frequency (Hz) — crystal / HS-PLL external clock */
#define FOSC           8000000UL

/* Baud Rate */
#define UART_BAUDRATE  9600UL

/* Speed Mode: 1 = High Speed (BRGH=1), 0 = Low Speed (BRGH=0) */
#define UART_HIGH_SPEED  1

/* SPBRG value for BRGH=1: SPBRG = (Fosc / (16 * Baud)) - 1 */
#define UART_SPBRG_VALUE  ((unsigned char)((FOSC / (16UL * UART_BAUDRATE)) - 1))

#endif