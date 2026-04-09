#include "led_interface.h"
#include "../../MCAL/GPIO/gpio_interface.h"

/*void LED_Setup(u8 port, u8 pin)
{
    GPIO_ConfigPin(port, pin, DIR_OUT);
}

void LED_TurnOn(u8 port, u8 pin)
{
    GPIO_WritePin(port, pin, LEVEL_HIGH);
}

void LED_TurnOff(u8 port, u8 pin)
{
    GPIO_WritePin(port, pin, LEVEL_LOW);
}

void LED_SwitchState(u8 port, u8 pin)
{
    u8 current = GPIO_ReadPin(port, pin);
    GPIO_WritePin(port, pin, (current == LEVEL_HIGH) ? LEVEL_LOW : LEVEL_HIGH);
}     */