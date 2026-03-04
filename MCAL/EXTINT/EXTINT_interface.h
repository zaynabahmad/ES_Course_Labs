#ifndef EXTINT_INTERFACE_H
#define EXTINT_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

#define RISING_EDGE 1
#define FALLING_EDGE 0
#define GIE 7
#define INTE 4
#define INTF 1
#define INTEDG 6

void EXT_INT_Init(void);
void EXT_INT_Enable(void);
void EXT_INT_Disable(void);
void EXT_INT_SetEdge(u8 edge_type);
void EXT_INT_SetCallback(void (*ptr)(void));
void EXT_INT_ISR_Handler(void);

#endif