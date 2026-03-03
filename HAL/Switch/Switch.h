#ifndef HAL_SWITCH_SWITCH_H_
#define HAL_SWITCH_SWITCH_H_

#include "../../SERVICES/STD_TYPES.h"


#define SW1_PORT         PORTD
#define SW1_PIN          1
#define SW2_PORT         PORTB
#define SW2_PIN          2

void SWITCH_Init(u8 Port, u8 Pin);
u8 SWITCH_Read(u8 Port, u8 Pin);

#endif