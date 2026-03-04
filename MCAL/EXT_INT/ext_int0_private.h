#ifndef EXT_INT0_PRIVATE_H
#define EXT_INT0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h" 
// I assume INTCON and OPTION_REG are needed for configuring external interrupts

#define INTCON      (*((volatile u8*)0x0B))
#define OPTION_REG  (*((volatile u8*)0x81))

#define GIE     7
#define INTE    4
#define INTF    1
#define INTEDG  6


#endif
