#include "adc.h"
#include "pwm.h"

void ADC_Test(void)
{
    uint16 adcValue  = 0;
    uint8  dutyValue = 0;

    ADC_Init();
    PWM_Init();

    while(1)
    {
        adcValue  = ADC_Read(ADC_CHANNEL_0);
        dutyValue = (uint8)((adcValue * 100UL) / 1023UL);
        PWM_SetDuty(dutyValue);
        Delay_ms(50);
    }
}