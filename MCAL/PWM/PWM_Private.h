#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#define INTCON (*((volatile u8 *)0x18B))
#define PR2 (*((volatile u8 *)0x092))
#define CCPR1L (*((volatile u8 *)0x015))
#define CCPR1H (*((volatile u8 *)0x016))
#define CCPR1CON (*((volatile u8 *)0x017))

#define T2CON (*((volatile u8 *)0x012))
#define TMR2 (*((volatile u8 *)0x011))
#endif
