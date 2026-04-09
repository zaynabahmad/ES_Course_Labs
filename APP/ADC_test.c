#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

#define VREF 5000 // in mV
#define ADC_RES 1023

void ADC_LM35_Test(void)
{
    u16 adc_value;
    u16 temp_c; // temperature in Celsius *10
    u8 hundreds, tens, ones, dec;

    ADC_Init();
    UART_Init();

    while(1)
    {
        adc_value = ADC_Read(0); // AN0

        // Convert ADC to temperature (°C * 10)
        // temperature (°C *10) = (ADC * VREF in mV * 10) / (1023 * 10mV per °C)
        temp_c = (adc_value * VREF) / 1023 / 10;

        hundreds = temp_c / 100;
        tens     = (temp_c % 100) / 10;
        ones     = temp_c % 10;

        UART_SendChar(hundreds + '0');
        UART_SendChar(tens + '0');
        UART_SendChar(ones + '0');
        UART_SendChar('\n');
        UART_SendChar('\r');

        Delay_ms(500);
    }
}