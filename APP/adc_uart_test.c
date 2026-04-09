#include "../SERVICES/STD_TYPES.h"
#include "adc_uart_test.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/UART/UART_interface.h"

static void int_to_str(u16 num, u8* str)
{
    u8 digits[5];
    u8 i = 0;
    u8 j;
    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    while (num > 0) {
        digits[i++] = (num % 10) + '0';
        num /= 10;
    }
    for (j = 0; j < i; j++)
        str[j] = digits[i - 1 - j];
    str[i] = '\0';
}

void ADC_UART_TEST_Run(void)
{
    u16 adc_value;
    u16 temp_int;
    u8 buffer[20];
    u8 *p;
    volatile u32 d;

    ADC_Init();
    UART_Init();

    while (1)
    {
        adc_value = ADC_Read(0);
        temp_int = (adc_value * 500UL) / 1024;

        p = buffer;
        *p++ = 'T'; *p++ = 'e'; *p++ = 'm'; *p++ = 'p'; *p++ = ':'; *p++ = ' ';
        int_to_str(temp_int / 100, p);
        while (*p) p++;
        *p++ = '.';
        if ((temp_int % 100) < 10) *p++ = '0';
        int_to_str(temp_int % 100, p);
        while (*p) p++;
        *p++ = ' '; *p++ = 'C'; *p++ = '\r'; *p++ = '\n'; *p = '\0';

        UART_SendString(buffer);
        for (d = 0; d < 500000; d++);
    }
}