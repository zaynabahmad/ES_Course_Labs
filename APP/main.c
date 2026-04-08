/*#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/UART/UART_interface.h"

char txt[20];
u16 adc_value;
float temperature;


void main()
{
    ADC_Init();
    UART_Init();

    Delay_ms(100);

    while(1)
    {
        adc_value = ADC_Read(0);   // AN0

        temperature = adc_value * 0.488;

        FloatToStr(temperature, txt);

        UART_SendString_ROM("Temp = ");
        UART_SendString(txt);
        UART_SendString_ROM(" C");

        UART_SendByte(13);
        UART_SendByte(10);

        Delay_ms(1000);
    }
}*/
// SPI_Test
#include "../MCAL/SPI/SPI_interface.h"

void main()
{
    SPI_Init();

    while(1)
    {
        SPI_Transfer(0x55);  // send test byte
        Delay_ms(1000);
    }
}
// I2C_Test
/*#include "../MCAL/I2C/I2C_interface.h"

void main()
{
    I2C_Init();

    while(1)
    {
        I2C_Start();

        I2C_Write(0xA0);   // slave address + write
        I2C_Write(0x55);   // data

        I2C_Stop();

        Delay_ms(1000);
    }
}*/

