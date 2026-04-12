#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/USART/USART_Interface.h"

void ADC_Test(void)
{
    u16 AdcResult;
    u8  HighByte;
    u8  LowByte;

    /* Initialize ADC */
    ADC_Init();

    /* Initialize UART to send results */
    UART_TX_Init();

    /* Read channel 0 (RA0) continuously */
    while(1)
    {
        UART_ServiceRx();

        AdcResult = ADC_Read(ADC_CHANNEL_0);

        /* Send high byte then low byte over UART */
        HighByte = (u8)(AdcResult >> 8);
        LowByte  = (u8)(AdcResult & 0x00FF);

        UART_Write(HighByte);
        UART_Write(LowByte);
        UART_Write('\n');
    }
}
