#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/PWM/PWM_interface.h"

void ADC_Test()
{
    ADC_Init();
    PWM_Init();

    while (1)
    {
        unsigned int value = ADC_Read(0); // channel 0

        PWM_SetDutyCycle(value / 4); // scale 1023 → 255
    }
}