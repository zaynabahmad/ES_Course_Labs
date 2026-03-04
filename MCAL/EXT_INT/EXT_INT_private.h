#ifndef EXT_INT_PRIVATE_H
#define EXT_INT_PRIVATE_H

/* PIC16F877A Interrupt Registers */
#define INTCON      (*((volatile u8*)0x0B))
#define OPTION_REG  (*((volatile u8*)0x81))

#define GIE     7
#define INTE    4
#define INTF    1
#define INTEDG  6

#endif