#include "D:\ES-Project-Lab\MCAL\GPIO\gpio.h"
#include "led_interface.h"

void LED_Init(u8 port, u8 pin)
{
    GPIO_setPinDirection(port, pin, GPIO_OUTPUT);
}

void LED_On(u8 port, u8 pin)
{
    GPIO_setPinValue(port, pin, GPIO_HIGH);
}

void LED_Off(u8 port, u8 pin)
{
    GPIO_setPinValue(port, pin, GPIO_LOW);
}

void LED_Toggle(u8 port, u8 pin)
{
    static u8 state = 0;
    state ^= 1;
    GPIO_setPinValue(port, pin, state);
}