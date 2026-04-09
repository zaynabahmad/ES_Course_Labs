#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "adc_test.h"

void adc_test_run(void)
{
    u16 raw;

    ADC_Init();

    /* Read channel 0 (AN0 / RA0) */
    raw = ADC_Read(ADC_CH0);

    /* Drive PORTD pin2 high if reading exceeds mid-scale (512 of 1023) */
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN2, GPIO_OUTPUT);
    if (raw > 512)
        GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN2, GPIO_HIGH);
    else
        GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN2, GPIO_LOW);

    /* Read channel 1 (AN1 / RA1) — result ignored, exercises the API */
    ADC_Read(ADC_CH1);
}
