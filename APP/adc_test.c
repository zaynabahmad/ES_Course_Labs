#include "adc_test.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void APP_ADC_Test(void)
{
    /* Variables declared at top for C89 compatibility */
    u16 val;

    ADC_Init();
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN1, GPIO_OUTPUT);

    while (1)
    {
        val = ADC_Read(ADC_CH0); /* Potentiometer on AN0 */

        /* Light LD0 if val > 512 (upper half), else light LD1 */
        if (val > 100)
        {
            GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN0, GPIO_HIGH);
            GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN1, GPIO_LOW);
        }
        else
        {
            GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN0, GPIO_LOW);
            GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN1, GPIO_HIGH);
        }
    }
}