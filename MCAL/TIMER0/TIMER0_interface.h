#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Timer0 Modes */
#define TIMER0_MODE_NORMAL      0
#define TIMER0_MODE_CTC         1  // Clear Timer on Compare (if needed, PIC16F877A can only do normal mode, prescaler, etc.)

/* Timer0 Prescaler Options */
#define TIMER0_PRESCALER_2      0
#define TIMER0_PRESCALER_4      1
#define TIMER0_PRESCALER_8      2
#define TIMER0_PRESCALER_16     3
#define TIMER0_PRESCALER_32     4
#define TIMER0_PRESCALER_64     5
#define TIMER0_PRESCALER_128    6
#define TIMER0_PRESCALER_256    7

/* Timer0 Interrupt */
#define TIMER0_INTERRUPT_ENABLE()   (SET_BIT(INTCON, 5))   // T0IE
#define TIMER0_INTERRUPT_DISABLE()  (CLR_BIT(INTCON, 5))
#define TIMER0_INTERRUPT_FLAG       (T0IF)

/* Function Prototypes */
void TIMER0_Init(u8 Mode, u8 PrescalerEnable, u8 PrescalerValue);
void TIMER0_Start(void);
void TIMER0_Stop(void);
void TIMER0_SetValue(u8 Value);
u8   TIMER0_GetValue(void);
void TIMER0_SetCallback(void (*Callback)(void));

#endif