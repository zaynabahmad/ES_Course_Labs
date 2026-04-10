#include "APP_Tests.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/ADC/ADC_Interface.h"

#define ADC_LED_PORT GPIO_PORTD
#define ADC_LED_PIN  GPIO_PIN1

void APP_Test_ADC(void)
{
    u16 analog_value = 0;

    // Initialize Hardware
    LED_Init(ADC_LED_PORT, ADC_LED_PIN);
    ADC_Init();

    // Infinite loop for the ADC test
    while(1)
    {
        // Read channel 0 (PIN_A0)
        analog_value = ADC_Read(ADC_CHANNEL_0);

        // 10-bit ADC goes from 0 to 1023. 512 is halfway (~2.5V)
        if(analog_value > 512)
        {
            LED_On(ADC_LED_PORT, ADC_LED_PIN);
        }
        else
        {
            LED_Off(ADC_LED_PORT, ADC_LED_PIN);
        }
    }
}
