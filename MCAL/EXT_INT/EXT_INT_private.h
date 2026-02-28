#ifndef EXT_INT_PRIVATE_H
#define EXT_INT_PRIVATE_H


#define TRISB   (*((volatile u8*)0x86))
#define PORTB   (*((volatile u8*)0x06))
#define INTCON  (*((volatile u8*)0x18B))
#define OPTION_REG (*((volatile u8*)0x181))
#endif