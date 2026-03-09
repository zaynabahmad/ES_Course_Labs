#ifndef TMR_INT_PRIVATE_H
#define TMR_INT_PRIVATE_H

#define INTCON (*((volatile u8*)0x18B))
#define OPTION_REG (*((volatile u8*)0x181))
#define TMR0 (*((volatile u8*)0x190))

#endif