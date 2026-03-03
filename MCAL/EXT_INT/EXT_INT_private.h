#ifndef EXT_INT_PRIVATE_H
#define EXT_INT_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define INTCON             (*((volatile u8*)0x0B))
#define INTCON_GIE         7   
#define INTCON_INTE        4   
#define INTCON_INTF        1   

/* OPTION_REG register — 0x81 */
#define OPTION_REG         (*((volatile u8*)0x81))
#define OPTION_INTEDG      6   /* 1 = rising edge, 0 = falling edge */

#endif
