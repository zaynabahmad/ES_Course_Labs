#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Register definitions for PIC16F877A Interrupts */
#define INTCON_REG      (*((volatile u8*)0x0B))
#define OPTION_REG_REG  (*((volatile u8*)0x81))

/* INTCON Bits */
#define GIE     7   /* Global Interrupt Enable */
#define PEIE    6   /* Peripheral Interrupt Enable */
#define INTE    4   /* External Interrupt Enable (RB0) */
#define INTF    1   /* External Interrupt Flag */

/* OPTION_REG Bits */
#define INTEDG  6   /* Interrupt Edge Select (1=Rising) */

#endif