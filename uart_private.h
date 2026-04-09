#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#include "../../SERVICES/types.h"

#define PIR1_REG        (*((volatile u8*)0x0C))
#define TXSTA_REG       (*((volatile u8*)0x98))
#define RCSTA_REG       (*((volatile u8*)0x18))
#define SPBRG_REG       (*((volatile u8*)0x99))
#define TXREG_REG       (*((volatile u8*)0x19))
#define RCREG_REG       (*((volatile u8*)0x1A))
#define TRISC_REG       (*((volatile u8*)0x87))

/* Bit definitions */
#define TXEN    5
#define SYNC    4
#define BRGH    2
#define SPEN    7
#define CREN    4
#define TRMT    1
#define RCIF    5

#endif