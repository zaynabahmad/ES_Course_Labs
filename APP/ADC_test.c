#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/UART/UART_interface.h"

void APP_ADC_Test(void) 
{
    uint16 adc_res = 0;
    float temp = 0.0;
    char txt[20]; /* Buffer for FloatToStr [cite: 347] */

    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN6, GPIO_OUTPUT);
    
    ADC_Init();
    UART_Init();

    while(1) 
    {
        adc_res = ADC_ReadChannel(ADC_CHANNEL_0);
        temp = adc_res * 0.488; /* [cite: 364-366] */

        UART_WriteText("Temp = ");
        FloatToStr(temp, txt); /* Use built-in lab function [cite: 237, 367] */
        UART_WriteText(txt);
        UART_WriteText(" C\r\n");

        Delay_ms(1000); 
    }
}
#ifndef Delay_ms
  #define Delay_ms(x)  // Dummy macro for GCC syntax check
#endif
#ifndef Delay_us
  #define Delay_us(x)  // Dummy macro for GCC syntax check
#endif