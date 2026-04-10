#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/UART/UART_interface.h"

void main(void)
{
    u16 temperature;

    ADC_Init();
    UART_Init();

    while (1)
    {
        /* Read LM35 on AN0 */
        temperature = ADC_ReadTemperatureC(0);  

        UART_SendString("Temp = ");
        /* Use SendNumber instead of SendTemperature to avoid the double "C C" printout */
        UART_SendNumber(temperature); 
        UART_SendString(" C\r\n");

        Delay_ms(1000);
    }
}