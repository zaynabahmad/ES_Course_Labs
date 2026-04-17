#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void ADC_Test(void)
{
    u16 adcValue = 0;

    ADC_Init();

    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN1, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN2, GPIO_OUTPUT);

    adcValue = ADC_Read(ADC_CHANNEL_0);

    /* Light LEDs based on ADC reading range */
    if (adcValue > 682)
    {
        GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN0, GPIO_HIGH);
        GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN1, GPIO_HIGH);
        GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN2, GPIO_HIGH);
    }
    else if (adcValue > 341)
    {
        GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN0, GPIO_HIGH);
        GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN1, GPIO_HIGH);
        GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN2, GPIO_LOW);
    }
    else
    {
        GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN0, GPIO_HIGH);
        GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN1, GPIO_LOW);
        GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN2, GPIO_LOW);
    }
}
