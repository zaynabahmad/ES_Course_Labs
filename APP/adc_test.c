#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:/ES-Project-Lab/MCAL/GPIO/gpio.h"
#include "D:/ES-Project-Lab/MCAL/ADC/adc_interface.h"
#include "D:\ES-Project-Lab\HAL\led_interface.h"
void app_adc_test(void)
{
    u16 adc_value = 0;

    /* RA0 as analog input */
    GPIO_setPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT);

    /* RD0 as LED output */
    LED_Init(GPIO_PORTD, GPIO_PIN0);

    ADC_Init();

    while(1)
    {
        adc_value = ADC_Read(ADC_CHANNEL_0);

        /* Simple threshold test */
        if(adc_value > 512)
        {
            LED_On(GPIO_PORTD, GPIO_PIN0);
        }
        else
        {
            LED_Off(GPIO_PORTD, GPIO_PIN0);
        }
    }
}