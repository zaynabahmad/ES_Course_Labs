#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Bits */
#define GIE_BIT   7
#define T0IE_BIT  5
#define T0IF_BIT  2

/* OPTION_REG bits */
#define PSA_BIT   3
#define T0CS_BIT  5

/* APIs */
void TIMER0_Init(void);
void TIMER0_Start(void);
void TIMER0_Stop(void);
void TIMER0_SetPreload(u8 value);
void TIMER0_SetCallback(void (*ptr)(void));

#endif