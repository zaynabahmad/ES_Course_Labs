#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void ADC_Test(void)
{
    u16 value;
    unsigned long i;

    /* Example: use PORTA PIN0 (AN0) */

    ADC_Init();

    while(1)
    {
        value = ADC_Read(0);   // Read AN0

        /* Simple condition */
        if(value > 512)
        {
            GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
        }
        else
        {
            GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
        }

        for(i = 0; i < 50000; i++);
    }
}