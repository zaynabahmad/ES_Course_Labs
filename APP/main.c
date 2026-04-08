#include "../MCAL/ADC/ADC_interface.h"

char txt[20];
unsigned int adc_value;
float temperature;

void main()
{
    ADC_Init();
    UART1_Init(9600);   // UART init (9600 baud)

    Delay_ms(100);      // stabilize UART

    while(1)
    {
        // Read from AN0
        adc_value = ADC_Read(0);

        // Convert to temperature
        temperature = adc_value * 0.488;

        // Convert float to string
        FloatToStr(temperature, txt);

        // Send via UART
        UART1_Write_Text("Temp = ");
        UART1_Write_Text(txt);
        UART1_Write_Text(" C");

        UART1_Write(13); // CR
        UART1_Write(10); // LF

        Delay_ms(1000); // 1 sec
    }
}