#ifndef EXT_INT_PRIVATE_H
#define EXT_INT_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define INTCON       (*((volatile u8*)0x0B))   /* was 0x18B */
#define OPTION_REG   (*((volatile u8*)0x81))   /* was 0x181 */

#define GIE_BIT      7
#define INTE_BIT     4
#define INTF_BIT     1
#define INTEDG_BIT   6   /* 1=Rising, 0=Falling */

#endif