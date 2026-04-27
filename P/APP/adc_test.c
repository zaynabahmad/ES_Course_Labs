#include "adc_test.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void ADC_Test(void)
{
    unsigned int value;

    GPIO_SetPinDirection(PORTB, PIN0, OUTPUT);

    ADC_Init();

    while(1)
    {
        value = ADC_Read(0);

        if(value > 512)
            GPIO_WritePin(PORTB, PIN0, HIGH);
        else
            GPIO_WritePin(PORTB, PIN0, LOW);
    }
}