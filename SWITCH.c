#include "D:\embeddedsystems\Labs\LABTASK2\Project\MCAL\GPIO.h"
#include "SWITCH.h"

void SWITCH_Init()
{
     GPIO_SetPinDirection(&TRISA, 0, INPUT);
     GPIO_SetPinDirection(&TRISA, 1, INPUT);
}

unsigned short SWITCH_Read(unsigned short pin)
{
     return GPIO_ReadPin(&PORTA, pin);
}