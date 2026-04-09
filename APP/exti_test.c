#include "exti_test.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"

void EXTI_Test(void)
{
    GPIO_SetPinDirection(PORTB, PIN0, OUTPUT); // LED
    GPIO_SetPinDirection(PORTB, PIN0, INPUT);  // INT pin (RB0)

    EXTI_Init(RISING_EDGE);
    EXTI_Enable();

    while(1)
    {
        // nothing (interrupt handles everything)
    }
}