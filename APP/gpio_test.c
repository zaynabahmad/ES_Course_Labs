#include "GPIO_interface.h"

void GPIO_Test(void)
{
    GPIO_voidSetPinDirection('B',0,0);

    while(1)
    {
        GPIO_voidSetPinValue('B',0,1);
    }
}