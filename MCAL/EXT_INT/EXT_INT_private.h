#ifndef EXT_INT_PRIVATE_H
#define EXT_INT_PRIVATE_H

/* PIC16F877A INTCON (bank 0: 0x0B, shared across all banks) */
#ifndef INTCON
#define INTCON      (*((volatile u8*)0x0B))
#endif

/* PIC16F877A OPTION_REG (bank 1: 0x81) */
#ifndef OPTION_REG
#define OPTION_REG  (*((volatile u8*)0x81))
#endif

#endif