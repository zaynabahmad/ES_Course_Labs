#ifndef TIMER1_PRIVATE_H
#define TIMER1_PRIVATE_H

#define T1CON_REG   (*((volatile u8*)0x10))
#define TMR1L_REG   (*((volatile u8*)0x0E))
#define TMR1H_REG   (*((volatile u8*)0x0F))
#define PIE1_REG    (*((volatile u8*)0x8C))
#define PIR1_REG    (*((volatile u8*)0x0C))
#define INTCON_REG  (*((volatile u8*)0x0B))

#endif
