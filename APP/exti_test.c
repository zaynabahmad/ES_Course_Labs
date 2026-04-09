#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"

void LED_Toggle()
{
    static char state = 0;

    if (state == 0)
    {
        GPIO_WritePin('A', 0, HIGH);
        state = 1;
    }
    else
    {
        GPIO_WritePin('A', 0, LOW);
        state = 0;
    }
}

void EXTI_Test()
{
    GPIO_SetPinDirection('A', 0, OUTPUT); // LED
    GPIO_SetPinDirection('D', 2, INPUT);  // INT0 pin

    EXTI_SetCallback(LED_Toggle);
    EXTI_Init(RISING_EDGE);
    EXTI_Enable();
}