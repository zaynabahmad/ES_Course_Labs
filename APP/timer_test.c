#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"

void TIMER0_Test()
{
    GPIO_SetPinDirection('A', 0, OUTPUT);

    TIMER0_Init();

    while (1)
    {
        GPIO_WritePin('A', 0, HIGH);
        TIMER0_DelayMs(500);

        GPIO_WritePin('A', 0, LOW);
        TIMER0_DelayMs(500);
    }
}