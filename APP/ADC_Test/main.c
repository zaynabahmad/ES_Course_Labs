#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void main(void)
{
    u16 adc_value;

    GPIO_Init(PORTB , PIN0 , OUTPUT);

    ADC_Init();

    while(1)
    {
        adc_value = ADC_Read(ADC_CHANNEL_0);

        if(adc_value > 512)
        {
            GPIO_WritePin(PORTB , PIN0 , HIGH);
        }
        else
        {
            GPIO_WritePin(PORTB , PIN0 , LOW);
        }
    }
}