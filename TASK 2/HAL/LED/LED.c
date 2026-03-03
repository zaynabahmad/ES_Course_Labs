#include "../../MCAL/GPIO/GPIO_interface.h"
#include "LED_interface.h"

void LED_Init(char port, char pin)
{
    GPIO_SetPinDirection(port, pin, OUTPUT);
}

void LED_On(char port, char pin)
{
    GPIO_WritePin(port, pin, HIGH);
}

void LED_Off(char port, char pin)
{
    GPIO_WritePin(port, pin, LOW);
}