#ifndef TMR_INT_INTERFACE_H
#define TMR_INT_INTERFACE_H

#include "TMR_INT_private.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"


#define TMR0IF_BIT 2
#define TMR0IE_BIT 5
#define GIE_BIT 7
#define PS0_BIT 0
#define PS1_BIT 1
#define PS2_BIT 2
#define PSA_BIT 3
#define TOCS_BIT 5
#define TOSE_BIT 4

void TMR_INT_SetPreload(u8 preload_value);
void TMR_INT_SetPrescaler(u8 prescaler_value);
void set_tmr0(u8 value);
void TMR_INT_Enable(void);
void TMR_INT_Disable(void);
#endif 