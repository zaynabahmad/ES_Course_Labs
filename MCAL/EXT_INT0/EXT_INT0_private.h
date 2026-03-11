#ifndef EXT_INT0_PRIVATE_H
#define EXT_INT0_PRIVATE_H

#define INTCON (*((volatile u8 *)0x0B))
#define OPTION_REG (*((volatile u8 *)0x81))

#define PORTC (*((volatile u8 *)0x07))
#endif
