#ifndef EXT_INT0_PRIVATE_H
#define EXT_INT0_PRIVATE_H

#include "../../SERVICES/STD_TYPES1.h"

/* Register Definitions for External Interrupt (PIC16F877A) */
#define INTCON (*((volatile uint8 *)0x0B))
#define OPTION_REG (*((volatile uint8 *)0x81))
#define TRISB_REG (*((volatile uint8 *)0x86)) /* Included to set pin direction */

/* INTCON Register Bits */
#define INTCON_INTF 1 /* External Interrupt Flag bit */
#define INTCON_INTE 4 /* External Interrupt Enable bit */
#define INTCON_GIE 7  /* Global Interrupt Enable bit */

/* OPTION_REG Register Bits */
#define OPTION_REG_INTEDG 6 /* Interrupt Edge Select bit */

#endif /* EXT_INT0_PRIVATE_H */