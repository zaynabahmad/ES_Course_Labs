#include "LED.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/GPIO/GPIO_private.h"

void LED_Init(uint8 pin) {
    TRISB &= ~(1 << pin); 
}
void LED_On(uint8 pin)
{
    PORTB |= (1 << pin);
}

void LED_Off(uint8 pin)
{
    PORTB &= ~(1 << pin);
}

void LED_Toggle(uint8 pin) {
    PORTB ^= (1 << pin); 
}