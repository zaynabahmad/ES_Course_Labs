#ifndef EXT_INT_INTERFACE_H
#define EXT_INT_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_Interface.h"
#include "EXT_INT_Config.h"
#include "EXT_INT_Private.h"

/* INTCON Bit Positions */
#define GIE_BIT     7
#define PEIE_BIT    6
#define INTE_BIT    4
#define INTF_BIT    1

/* OPTION_REG Bit for edge select */
#define INTEDG_BIT  6

/* Edge Types */
#define RISING_EDGE   1
#define FALLING_EDGE  0

void EXT_INT_Init(void);
void EXT_INT_Enable(void);
void EXT_INT_Disable(void);
void EXT_INT_SetEdge(u8 EdgeType);
void EXT_INT_SetCallback(void (*Callback)(void));
void EXT_INT_ISR(void);

#endif
