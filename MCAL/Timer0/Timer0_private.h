#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#define TMR0_REG      (*((volatile unsigned char*)0x01))
#define OPTION_REG    (*((volatile unsigned char*)0x81))
#define INTCON_REG    (*((volatile unsigned char*)0x0B))

#endif