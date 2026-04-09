#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define SPBRG    (*(volatile uint8*)0x99)
#define TXSTA    (*(volatile uint8*)0x98)
#define RCSTA    (*(volatile uint8*)0x18)
#define TXREG    (*(volatile uint8*)0x19)
#define RCREG    (*(volatile uint8*)0x1A)

#endif