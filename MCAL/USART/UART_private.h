#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* UART Peripheral Registers */
#define TXREG    (*((volatile uint8*)0x19))  /* Transmit Data Register */
#define RCREG    (*((volatile uint8*)0x1A))  /* Receive Data Register */
#define SPBRG    (*((volatile uint8*)0x99))  /* Baud Rate Generator Register */
#define TXSTA    (*((volatile uint8*)0x98))  /* Transmit Status & Control */
#define RCSTA    (*((volatile uint8*)0x18))  /* Receive Status & Control */

/* Status Bits */
#define TRMT_BIT    1   /* Transmit Shift Register Status bit (1 = empty) */
#define SPEN_BIT    7   /* Serial Port Enable bit */
#define TXEN_BIT    5   /* Transmit Enable bit */
#define CREN_BIT    4   /* Continuous Receive Enable bit */

#endif