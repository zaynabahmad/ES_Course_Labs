#ifndef EXT_INT0_PRIVATE_H
#define EXT_INT0_PRIVATE_H

#include "../../SERVICES/Std_Types.h"

#define INTCON_REG         (*((volatile u8*)0x0B))
#define OPTION_REG_CUSTOM  (*((volatile u8*)0x81))
#define INTF_BIT    1
#define INTE_BIT    4
#define INTEDG_BIT  6
#define GIE_BIT     7

#endif