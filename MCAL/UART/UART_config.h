#ifndef UART_CONFIG_H
#define UART_CONFIG_H

#define F_CPU 8000000UL
#define BAUD_RATE 9600

// SPBRG = (Fosc / (64 * Baud)) - 1  (BRGH=0)
#define SPBRG_VALUE 12   // for 8MHz & 9600

#endif