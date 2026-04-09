#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
// Include your instructor's UART driver here!
#include "../MCAL/USART/USART_interface.h"
#include "adc_test.h"

// We use the built-in mikroC function for float to string conversion
extern void FloatToStr(float fnum, char *str);

// A simple delay so  the UART terminal is not spammedtoo fast
static void APP_Delay(void)
{
    unsigned long i;
    for(i = 0; i < 200000; i++); 
}

void APP_TestADC(void)
{
    u16 raw_adc_value;
    float temperature;
    char temp_string[20];
    u8 i;

    // Initialization
    GPIO_Init();
    ADC_Init();
    void UART_TX_Init(void);
    
    // RA0 must be an INPUT to read the analog voltage
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT);

   
    while(1)
    {
        // Read the raw 10-bit value from channel 0 (AN0)
        raw_adc_value = ADC_ReadChannel(ADC_CHANNEL_AN0);

        // Calculate Temperature 
        // Math: (5.0V / 1024) * 100 degrees per volt = 0.488
        temperature = raw_adc_value * 0.488;

        // Convert the float value to a string array
        FloatToStr(temperature, temp_string);

        // Send the data over UART
        UART_Write('T'); UART_Write('e'); UART_Write('m'); UART_Write('p'); 
        UART_Write(' '); UART_Write('='); UART_Write(' ');
        
        for(i = 0; temp_string[i] != '\0'; i++)
        {
            UART_Write(temp_string[i]);
        }
        
        UART_Write(' '); UART_Write('C');
        UART_Write(13); // Carriage Return (Enter key)
        UART_Write(10); // Line Feed (New Line)

        //Wait a second before reading again
        APP_Delay();
    }
}