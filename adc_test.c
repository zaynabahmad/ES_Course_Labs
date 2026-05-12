#include "adc_test.h"
#include "../MCAL/ADC_INTERFACE.h"
#include "../MCAL/PWM_INTERFACE.h"

void ADC_Test_Init(void)
{
    ADC_Init();
    /* PWM output so we can visualise ADC-controlled duty cycle */
    PWM_Init();
}

void ADC_Test_Run(void)
{
    u16 raw;
    u8  duty;

    /* Read potentiometer on AN0 */
    raw = ADC_Read(ADC_CH0);

    /* Map 10-bit ADC result (0..1023) to duty cycle (0..100) */
    duty = (u8)((raw * 100u) / 1023u);

    PWM_SetDutyCycle(duty);
}
