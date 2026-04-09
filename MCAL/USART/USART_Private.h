#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define TXSTA       (*(volatile u8*)0x98)
#define RCSTA       (*(volatile u8*)0x18)
#define SPBRG       (*(volatile u8*)0x99)
#define TXREG       (*(volatile u8*)0x19)
#define RCREG       (*(volatile u8*)0x1A)
#define PIR1        (*(volatile u8*)0x0C)
#define PIE1        (*(volatile u8*)0x8C)
#define INTCON      (*(volatile u8*)0x0B)

#define TXEN   5
#define BRGH   2
#define SYNC   4
#define TRMT   1

#define SPEN   7
#define CREN   4

#define RCIF   5

#define RCIE   5

#define PEIE   6
#define GIE    7

#endif
