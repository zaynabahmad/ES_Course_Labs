#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define INTCON  (*((volatile u8*)0x8B))
// 1 -> INTF , 2 -> T0IF , 4 -> INTE , 5 -> TOIE , 6 -> PEIE , 7 -> GIE

#define OPTION_REG  (*((volatile u8*)0x81))
// 2-0 -> PS2:0 , 3 -> PSA , 4 -> T0SE , 5 -> T0SC , 6 -> INTEDG ( 1 -> RISING , 0 -> FALLING ) , 7 -> RBPU ( PORTB PULL UP ENABLE BIT)

// TOSC = 0 -> internal clock
// PSA = 0 -> assign prescaler to TMR0


#define RISING_EDGE  1
#define FALLING_EDGE 0

#endif