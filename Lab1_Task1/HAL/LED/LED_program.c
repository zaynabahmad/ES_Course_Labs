#include "LED_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void LED_Init(uint8 port, uint8 pin)
{
    GPIO_SetPinDirection(port, pin, GPIO_OUTPUT);
    GPIO_WritePin(port, pin, GPIO_LOW);   /* OFF initially */
}

void LED_On(uint8 port, uint8 pin)
{
    GPIO_WritePin(port, pin, GPIO_HIGH);
}

void LED_Off(uint8 port, uint8 pin)
{
    GPIO_WritePin(port, pin, GPIO_LOW);
}

void LED_Toggle(uint8 port, uint8 pin)
{
    uint8 current = GPIO_ReadPin(port, pin);
    GPIO_WritePin(port, pin, !current);
}
