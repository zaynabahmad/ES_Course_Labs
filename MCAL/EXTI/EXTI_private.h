#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


#define INTCON  *((volatile u8*)0x0b)
#define OPTION_REG  *((volatile u8*)0x81)

/* INTCON Bits */
#define INTE    4    // External Interrupt Enable
#define INTF    1    // External Interrupt Flag
#define GIE     7

/* OPTION_REG Bits */
#define INTEDG  6    // Interrupt Edge Select (1=Rising, 0=Falling)

#endif