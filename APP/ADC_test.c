
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/USART/USART_Interface.h"

void APP_Test_ADC(void)
{
    u16 ADCReading = 0;
    ADC_voidInit();
    ADCReading = ADC_u16GetChannelReading(ADC_CHANNEL_0);
    if (ADCReading > 512)
    {
        UART_Write('H');
    }
    else
    {
        UART_Write('L');
    }
}