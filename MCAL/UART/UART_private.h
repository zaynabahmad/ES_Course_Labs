#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define TXSTA_REG    (*((volatile unsigned char*)0x98))
#define RCSTA_REG    (*((volatile unsigned char*)0x18))
#define SPBRG_REG    (*((volatile unsigned char*)0x99))
#define TXREG_REG    (*((volatile unsigned char*)0x19))
#define RCREG_REG    (*((volatile unsigned char*)0x1A))
#define PIR1_REG     (*((volatile unsigned char*)0x0C))

#endif