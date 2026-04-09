#include "switch.h"

void SWITCH_Init(void)
{
    GPIO_SetPinDirection(SWITCH_PORT, SWITCH_PIN, GPIO_INPUT);
}

uint8 SWITCH_Read(void)
{
    return GPIO_ReadPin(SWITCH_PORT, SWITCH_PIN);
}