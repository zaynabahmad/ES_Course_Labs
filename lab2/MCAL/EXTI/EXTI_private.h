#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define INTCON      (*((volatile u8*)0x0B))
#define OPTION_REG  (*((volatile u8*)0x81))

#define GIE_BIT   7
#define INTE_BIT  4
#define INTF_BIT  1

#define INTEDG_BIT 6

#endif