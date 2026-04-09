#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void HAL_LED_voidTurnOn(uint8 Copy_Port, uint8 Copy_Pin);
void HAL_LED_voidTurnOff(uint8 Copy_Port, uint8 Copy_Pin);

#endif