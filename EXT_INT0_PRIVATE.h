#ifndef EXT_INT0_PRIVATE_H
#define EXT_INT0_PRIVATE_H

#define INTCON      (*((volatile u8*)0x0B))
#define OPTION_REG  (*((volatile u8*)0x81))
#define TRISB       (*((volatile u8*)0x86))

#endif