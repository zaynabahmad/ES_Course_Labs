#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Registers (PIC16F877A) */

#define TXSTA   (*((volatile u8*)0x98))
#define RCSTA   (*((volatile u8*)0x18))
#define SPBRG   (*((volatile u8*)0x99))

#define TXREG   (*((volatile u8*)0x19))
#define RCREG   (*((volatile u8*)0x1A))

/* Bits */
#define TXEN    5
#define TRMT    1

#define SPEN    7
#define CREN    4

#endif