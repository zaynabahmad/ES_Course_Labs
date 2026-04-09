#ifndef EXT_INT_INTERFACE_H
#define EXT_INT_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Interrupt Control Bits (As defined by the instructor) */
#define GIE_BIT     7
#define INTE_BIT    4
#define INTF_BIT    1

/* Edge Control Bits */
#define INTEDGE_BIT 6
#define rising_edge  1
#define falling_edge 0

/* Function Prototypes */
void EXT_INT_Init(void);
void EXT_INT_Enable(void);
void EXT_INT_Disable(void);
void EXT_INT_SetEdge(u8 Edgetype);
void EXT_INT_SetCallback(void (*ptr)(void));

/* ISR Handler called by the central Interrupt_Manager.c */
void EXT_INT_ISR(void);

#endif