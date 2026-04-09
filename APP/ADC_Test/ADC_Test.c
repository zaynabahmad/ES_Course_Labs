#include "ADC_Test.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/USART/USART_Interface.h"

/* Helper function to convert integer to string and send via UART */
static void UART_SendString(char *str)
{
    while (*str)
    {
        UART_Write(*str);
        str++;
    }
}

static void UART_SendInt(u16 num)
{
    char buffer[10];
    u8 i = 0;
    
    if (num == 0)
    {
        UART_Write('0');
        return;
    }
    
    while (num > 0)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }
    
    /* Print in reverse order */
    while (i > 0)
    {
        i--;
        UART_Write(buffer[i]);
    }
}

void ADC_Test_Init(void)
{
    /* Initialize ADC module */
    ADC_Init();
    
    /* Initialize UART Transmission module */
    UART_TX_Init();
}

void ADC_Test_App(void)
{
    u16 digital_value = 0;
    u16 analog_voltage = 0; /* in millivolts */
    u16 temperature = 0;
    
    /* Read digital value from LM35 connected to AN0 */
    digital_value = ADC_ReadChannel(ADC_CHANNEL_0);
    
    /* Convert digital value to analog voltage in millivolts 
       Assuming 5V VDD reference and 10-bit ADC resolution
       V = (digital_value * 5000) / 1024 
    */
    analog_voltage = (u16)(((u32)digital_value * 5000UL) / 1024UL);
    
    /* LM35 gives 10mV per degree Celsius */
    temperature = analog_voltage / 10;
    
    /* Send Temperature over UART */
    UART_SendString("Temp: ");
    UART_SendInt(temperature);
    UART_SendString(" C\r\n");
    
    /* Simple software delay to avoid flooding UART terminal constantly */
    for(volatile u32 delay = 0; delay < 50000; delay++);
}
