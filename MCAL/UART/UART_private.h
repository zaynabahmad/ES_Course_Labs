#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

#define TXREG_REG  (*((volatile u8*)0x19))
#define RCREG_REG  (*((volatile u8*)0x1A))
#define TXSTA_REG  (*((volatile u8*)0x98))
#define RCSTA_REG  (*((volatile u8*)0x18))
#define SPBRG_REG  (*((volatile u8*)0x99))

#define TXEN_BIT 5
#define SPEN_BIT 7
#define CREN_BIT 4
#define TRMT_BIT 1

#endif