#include "GPIO_interface.h"
#include "ADC_interface.h"

void ADC_Test(void)
{
    unsigned int value;

    GPIO_voidSetPinDirection('B',0,0); // LED

    ADC_voidInit();

    while(1)
    {
        value = ADC_u16Read(0); // Read AN0

        if(value > 512)
            GPIO_voidSetPinValue('B',0,1);
        else
            GPIO_voidSetPinValue('B',0,0);
    }
}