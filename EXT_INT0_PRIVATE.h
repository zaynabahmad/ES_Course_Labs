#ifndef EXT_INT0_PRIVATE_H
#define EXT_INT0_PRIVATE_H

#define INTCON      (*((volatile u8*)0x0B))
#define OPTION_REG  (*((volatile u8*)0x81))
#define TRISB       (*((volatile u8*)0x86))

/* INTCON bit positions */
#define GIE    7   /* Global Interrupt Enable   */
#define INTE   4   /* INT External Interrupt Enable */
#define INTF   1   /* INT External Interrupt Flag   */

/* OPTION_REG bit positions */
#define INTEDG  6  /* Interrupt Edge Select */

#endif
