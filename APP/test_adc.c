#include "ADC/ADC_interface.h"
#include "UART/UART_interface.h"

void test_ADC(void)
{
    unsigned int adc_val;
    char high_byte, low_byte;

    ADC_Init();
    UART_Init();

    while (1)
    {
        adc_val  = ADC_Read(0);
        high_byte = (char)(adc_val >> 8);
        low_byte  = (char)(adc_val & 0xFF);

        UART_SendByte(high_byte);
        UART_SendByte(low_byte);
    }
}