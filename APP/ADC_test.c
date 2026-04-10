#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/USART/USART_interface.h"
#

static void App_SendString(u8* str)
{
    u8 i = 0;
    while(str[i] != '\0')
    {
        UART_Write(str[i]);
        i++;
    }
}
void APP_voidADCTest(void)
{
    u16 Local_u16ADCValue;
    f32 Local_f32Temp;
    u8  Local_u8TempInt;

    ADC_Init();
    UART_TX_Init();

    while(1)
    {   volatile u32 i =0;
        Local_u16ADCValue = ADC_u16GetChannelReading(0);
        Local_f32Temp = Local_u16ADCValue * 0.488;
        Local_u8TempInt = (u8)Local_f32Temp;

        App_SendString("Temp = ");
        UART_Write((Local_u8TempInt / 10) + '0');
        UART_Write((Local_u8TempInt % 10) + '0');
        App_SendString(" C\r\n");

        for(i = 0; i < 100000; i++);
    }
}