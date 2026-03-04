#ifndef _INTERRUPT_PRIVATE_H
#define _INTERRUPT_PRIVATE_H

#include "../../SERVICES/std_types.h"

#define INTCON      *((volatile u8 *)0x0B)
#define OPTION_REG  *((volatile u8 *)0x81)

// INTCON Bits
#define INTF_BIT    1
#define INTE_BIT    4
#define GIE_BIT     7

// OPTION_REG Bits
#define INTEDG_BIT  6

#endif