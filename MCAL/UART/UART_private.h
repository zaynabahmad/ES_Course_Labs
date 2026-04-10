#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* PIC16F877A UART Register Definitions */
#define TXSTA_REG    (*((volatile u8*)0x98))
#define RCSTA_REG    (*((volatile u8*)0x18))
#define SPBRG_REG    (*((volatile u8*)0x99))
#define TXREG_REG    (*((volatile u8*)0x19))
#define TRISC_REG    (*((volatile u8*)0x87))
#define PORTC_REG    (*((volatile u8*)0x07))

/* TXSTA Bit Positions */
#define TRMT_BIT     1

#endif
