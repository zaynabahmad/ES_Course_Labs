#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* INTCON register - address 0x0B */
#define INTCON      (*((volatile u8*)0x0B))

/* INTCON bits */
#define GIE         7    /* Global Interrupt Enable */
#define INTE        4    /* INT0 External Interrupt Enable */
#define INTF        1    /* INT0 External Interrupt Flag */

/* OPTION_REG register - address 0x81 */
#define OPTION_REG  (*((volatile u8*)0x81))

/* OPTION_REG bits */
#define INTEDG      6    /* 1=Rising edge  0=Falling edge */

#endif