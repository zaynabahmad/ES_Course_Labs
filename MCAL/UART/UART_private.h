#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define UDR   (*(volatile unsigned char*)0x2C)
#define UCSRA (*(volatile unsigned char*)0x2B)
#define UCSRB (*(volatile unsigned char*)0x2A)
#define UCSRC (*(volatile unsigned char*)0x40)
#define UBRRL (*(volatile unsigned char*)0x29)
#define UBRRH (*(volatile unsigned char*)0x40)

#endif