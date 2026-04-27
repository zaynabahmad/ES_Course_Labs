#include "gpio_test.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void GPIO_Test(void)
{
    GPIO_SetPinDirection(PORTB, PIN0, OUTPUT);

    while(1)
    {
        GPIO_WritePin(PORTB, PIN0, HIGH);
        Delay_ms(500);

        GPIO_WritePin(PORTB, PIN0, LOW);
        Delay_ms(500);
    }
}