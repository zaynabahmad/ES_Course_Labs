#ifndef EXT_INT_PRIVATE_H
#define EXT_INT_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* PIC16F877A - correct addresses */
#define INTCON      (*((volatile u8*)0x0B))
#define OPTION_REG  (*((volatile u8*)0x81))

#endif
