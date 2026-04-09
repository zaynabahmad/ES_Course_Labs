#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "TIMER0_Private.h"
#include "TIMER0_Config.h"

/* Clock Source Options */
#define TIMER0_INTERNAL_CLK   0
#define TIMER0_EXTERNAL_CLK   1

/* Prescaler Options */
#define TIMER0_PRESCALER_OFF  8   /* Assign prescaler to WDT -> 1:1 for TMR0 */
#define TIMER0_PRESCALER_2    0
#define TIMER0_PRESCALER_4    1
#define TIMER0_PRESCALER_8    2
#define TIMER0_PRESCALER_16   3
#define TIMER0_PRESCALER_32   4
#define TIMER0_PRESCALER_64   5
#define TIMER0_PRESCALER_128  6
#define TIMER0_PRESCALER_256  7

void TIMER0_Init(void);
void TIMER0_SetPreload(u8 Value);
u8   TIMER0_GetCount(void);
void TIMER0_EnableInterrupt(void);
void TIMER0_DisableInterrupt(void);
void TIMER0_SetCallback(void (*Callback)(void));
void TIMER0_ISR(void);

#endif
