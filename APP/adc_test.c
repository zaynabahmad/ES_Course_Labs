#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\GPIO\GPIO_interface.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\ADC\ADC_interface.h"

void ADC_Test(void)
{
    unsigned int adc_raw;
    float        voltage_mv;

    /* Configure output LEDs */
    GPIO_voidSetPinDirection('B', 0, 0);   /* RB0 = output */
    GPIO_voidSetPinDirection('B', 1, 0);   /* RB1 = output (new) */

    /* Initialise ADC */
    ADC_voidInit();

    while (1)
    {
        /* Read channel 0 (AN0) */
        adc_raw = ADC_u16Read(0);

        /* Guard against invalid return (should not happen for ch 0) */
        if (adc_raw == ADC_INVALID_CHANNEL)
        {
            /* Turn both LEDs off and skip this iteration */
            GPIO_voidSetPinValue('B', 0, 0);
            GPIO_voidSetPinValue('B', 1, 0);
            continue;
        }

        /* Convert raw reading to millivolts for reference */
        voltage_mv = ADC_f32ToVoltage(adc_raw);
        (void)voltage_mv;   /* suppress unused-variable warning */

        /* Three-level threshold decision */
        if (adc_raw > 512u)
        {
            /* High range: > ~2.5 V */
            GPIO_voidSetPinValue('B', 0, 1);
            GPIO_voidSetPinValue('B', 1, 0);
        }
        else if (adc_raw > 256u)
        {
            /* Mid range: ~1.25 V – 2.5 V */
            GPIO_voidSetPinValue('B', 0, 0);
            GPIO_voidSetPinValue('B', 1, 1);
        }
        else
        {
            /* Low range: < ~1.25 V */
            GPIO_voidSetPinValue('B', 0, 0);
            GPIO_voidSetPinValue('B', 1, 0);
        }
    }
}