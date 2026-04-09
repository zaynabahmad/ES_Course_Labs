#ifndef TIMER_0_INTERFACE_H
#define TIMER_0_INTERFACE_H

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../GPIO/GPIO_interface.h"
#include "TIMER_0_Config.h"
#include "TIMER_0_Private.h"

/* Timer0 Configuration */

#define GIE_BIT 7
#define T0IE_BIT 5
#define T0IF_BIT 2

/* Option Reg */
#define T0CS_BIT 5
#define T0SE_BIT 4
#define PSA_BIT 3
#define PS2_BIT 2
#define PS1_BIT 1
#define PS0_BIT 0

/* Edge types */
#define INTEDGE_BIT 6
#define rising_edge 1
#define falling_edge 0

void TIMER_0_Init(void);
void TIMER_0_Enable(void);
void TIMER_0_Disable(void);
void TIMER_0_SetEdge(u8 Edgetype);
void TIMER_0_SetPSR(u8 PrescalerRate);
void TIMER_0_SetCallback(void (*Callback)(void));
void TIMER_0_ISR(void);

#endif
