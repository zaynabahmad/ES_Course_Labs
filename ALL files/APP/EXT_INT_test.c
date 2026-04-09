#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

/* Callback function */
void EXT_INT_Action(void)
{
    GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
}

/* Test function */
void EXT_INT_Test(void)
{
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);

    EXT_INT_Init();

    EXT_INT_SetCallback(EXT_INT_Action);

    EXT_INT_Enable();

    while(1)
    {
        EXT_INT_ISR();   // simulate interrupt
    }
}