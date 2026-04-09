#include "ADC_Interface.h"
#include "USART_Interface.h"

void adc_test_run(void) {
    u16 adc_val;
    ADC_Init();
    

    adc_val = ADC_ReadChannel(0);
    UART_Write((u8)(adc_val >> 2)); 
}