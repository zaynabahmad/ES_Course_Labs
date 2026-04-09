#include "GPIO_interface.h"
#include "EXTI_interface.h"

void interrupt()
{
    GPIO_voidSetPinValue('B',0,1); // LED ON when interrupt happens
}

void EXTI_Test(void)
{
    GPIO_voidSetPinDirection('B',0,0);

    EXTI_voidEnable();

    while(1);
}