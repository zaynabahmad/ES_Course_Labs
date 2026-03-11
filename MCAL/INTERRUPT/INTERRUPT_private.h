#ifndef INTERRUPT_PRIVATE_H
#define INTERRUPT_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* INTCON register */

#define INTCON   (*((volatile u8*)0x0B))

/* INTCON bits */

#define GIE   7
#define INTF  1
#define T0IF  2

#endif