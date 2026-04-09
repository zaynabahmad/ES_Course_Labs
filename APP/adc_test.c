#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/GPIO/GPIO_Interface.h"

/* Test: read AN0 (pot) and light LEDs on PORTD based on value */
void ADC_Test(void)
{
    u16 adcVal;

    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT);  /* AN0 */
    GPIO_SetPortDirection(GPIO_PORTD, 0x00);  /* PORTD all output */

    ADC_Init();

    while(1)
    {
        adcVal = ADC_Read(ADC_CH0);

        /* Map 10-bit (0-1023) to 8 LEDs */
        if(adcVal > 896)      GPIO_SetPortValue(GPIO_PORTD, 0xFF);
        else if(adcVal > 768) GPIO_SetPortValue(GPIO_PORTD, 0x7F);
        else if(adcVal > 640) GPIO_SetPortValue(GPIO_PORTD, 0x3F);
        else if(adcVal > 512) GPIO_SetPortValue(GPIO_PORTD, 0x1F);
        else if(adcVal > 384) GPIO_SetPortValue(GPIO_PORTD, 0x0F);
        else if(adcVal > 256) GPIO_SetPortValue(GPIO_PORTD, 0x07);
        else if(adcVal > 128) GPIO_SetPortValue(GPIO_PORTD, 0x03);
        else                  GPIO_SetPortValue(GPIO_PORTD, 0x00);

        { volatile u16 d; for(d=0; d<10000; d++); }
    }
}
