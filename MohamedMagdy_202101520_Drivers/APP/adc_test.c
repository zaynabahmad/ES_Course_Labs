#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "adc_test.h"

#define ADC_LED_PORT    GPIO_PORTA
#define ADC_LED_PIN     GPIO_PIN1

#define ADC_THRESHOLD   512U

static void delay(void)
{
    unsigned int i;
    for(i = 0; i < 20000U; i++) { ; }
}

void ADC_Test(void)
{
    u16 adc_result;
    u8  reading_count;

    GPIO_SetPinDirection(ADC_LED_PORT, ADC_LED_PIN, GPIO_OUTPUT);
    GPIO_SetPinValue(ADC_LED_PORT, ADC_LED_PIN, GPIO_LOW);

    ADC_Init();

    for(reading_count = 0; reading_count < 10U; reading_count++)
    {
        adc_result = ADC_Read(ADC_CHANNEL_0);

        if(adc_result >= ADC_THRESHOLD)
        {
            GPIO_SetPinValue(ADC_LED_PORT, ADC_LED_PIN, GPIO_HIGH);
        }
        else
        {
            GPIO_SetPinValue(ADC_LED_PORT, ADC_LED_PIN, GPIO_LOW);
        }

        delay();
    }

    adc_result = ADC_Read(ADC_CHANNEL_1);

    ADC_Disable();
}
