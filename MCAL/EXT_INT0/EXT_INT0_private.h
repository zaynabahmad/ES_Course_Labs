#ifndef EXT_INT0_PRIVATE_H
#define EXT_INT0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#define INTCON   (*((volatile u8*)0x0B))
#define GIE      7
#define INTE     4
#define INTF     1

#define OPTION_REG   (*((volatile u8*)0x81))
#define INTEDG   6

#define FALLING_EDGE  0
#define RISING_EDGE   1

extern void (*EXT_INT0_Callback)(void);

#endif
