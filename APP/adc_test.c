#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../HAL/LED/LED_interface.h"

#define SENSOR_CHANNEL  ADC_CHANNEL_0
#define LED_PORT        GPIO_PORTA
#define LED_PIN         GPIO_PIN0
#define ADC_THRESHOLD   512

void ADC_Test(void)
{
    GPIO_Init();
    ADC_Init();
    LED_Init(LED_PORT, LED_PIN);
    LED_Off(LED_PORT, LED_PIN);

    u16 adc_value = ADC_Read(SENSOR_CHANNEL);

    if(adc_value > ADC_THRESHOLD) LED_On(LED_PORT, LED_PIN); // LED ON if above threshold
    else LED_Off(LED_PORT, LED_PIN);

    for(u16 i = 0; i < 100; i++);
}
