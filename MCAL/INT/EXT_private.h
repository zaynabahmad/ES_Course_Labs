#ifndef EXT_PRIVATE_H
#define EXT_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define TRISB       (*((volatile uint8*)0x86))
#define INTCON      (*((volatile uint8*)0x0B))
#define OPTION_REG  (*((volatile uint8*)0x81))


#define GIE_BIT       7
#define PEIE_BIT      6
#define TMR0IE_BIT    5
#define INTE_BIT      4
#define RBIE_BIT      3
#define TMR0IF_BIT    2
#define INTF_BIT      1
#define RBIF_BIT      0

/* Option Register Bits */
#define INTEDG_BIT    6

/* TRISB Bits */
#define TRISB0_BIT    0

#endif