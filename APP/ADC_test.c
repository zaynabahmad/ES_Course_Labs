#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT0/EXT_INT0_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/USART/USART_interface.h"
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "ADC_test.h"

void Send_String(char* str)
{
    u8 i = 0;
    while(str[i] != '\0')
    {
        UART_Write(str[i]);
        i++;
    }
}

void Send_Temperature(float temp)
{
    u32 int_part = (u32)temp;
    u32 frac_part = (u32)((temp - int_part) * 100);

    char buffer[10];
    s8 i = 0;

    if (int_part == 0)
        UART_Write('0');
    else
    {
        while(int_part > 0)
        {
            buffer[i++] = (int_part % 10) + '0';
            int_part /= 10;
        }
        while(i > 0)
            UART_Write(buffer[--i]);
    }

    UART_Write('.');
    UART_Write((frac_part / 10) + '0');
    UART_Write((frac_part % 10) + '0');
}

void ADC_Test(void)
{
    // CLR_BIT(INTCON, GIE);
    // CLR_BIT(INTCON, PEIE);

    u16 adc_value;
    float temperature;
    u32 i;

    /* Pins */
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT); // AN0
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN6, GPIO_OUTPUT); // TX

    /* Init */
    ADC_voidInit();
    UART_TX_Init();

    for(i = 0; i < 10000; i++); // small delay

    while (1)
    {
        if (ADC_u8ReadChannel(ADC_CHANNEL_0, &adc_value) == ADC_OK)
        {
            temperature = adc_value * 0.48828;

            Send_String("Temp = ");
            Send_Temperature(temperature);
            Send_String(" C\r\n");
        }

        for(i = 0; i < 25000; i++);
    }
}