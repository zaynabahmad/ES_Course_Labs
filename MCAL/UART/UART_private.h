#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define TXREG (*(volatile unsigned char*)0x19)
#define RCREG (*(volatile unsigned char*)0x1A)

#define TXSTA (*(volatile unsigned char*)0x98)
#define RCSTA (*(volatile unsigned char*)0x18)
#define SPBRG (*(volatile unsigned char*)0x99)

#define PIR1  (*(volatile unsigned char*)0x0C)

#endif