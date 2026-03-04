#include "LED.h"


#define LED_PIN_INDEX 0

void LED_Init(void)
{

    TRISC &= ~(1 << LED_PIN_INDEX);


    PORTC &= ~(1 << LED_PIN_INDEX);
}

void LED_Toggle(void)
{


    PORTC ^= (1 << LED_PIN_INDEX);
}


void LED_Set(Led_Status_t state)
{
    if (state == LED_STATE_ON)
    {

        PORTC |= (1 << LED_PIN_INDEX);
    }
    else
    {

        PORTC &= ~(1 << LED_PIN_INDEX);
    }
}