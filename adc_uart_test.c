#include "../SERVICES/types.h"
#include "adc_uart_test.h"
#include "../MCAL/ADC/adc_interface.h"
#include "../MCAL/UART/uart_interface.h"

static void ConvertU16ToString(u16 num, u8* buffer)
{
    u8 temp[5];
    u8 idx = 0, j;
    if(num == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }
    while(num)
    {
        temp[idx++] = (num % 10) + '0';
        num /= 10;
    }
    for(j = 0; j < idx; j++)
        buffer[j] = temp[idx - 1 - j];
    buffer[idx] = '\0';
}

static void SoftDelay(u32 count)
{
    volatile u32 i;
    for(i = 0; i < count; i++);
}

void ADC_UART_Test_Runner(void)
{
    u16 adc_reading;
    u16 temp_x100;
    u8 msg[20];
    u8 *ptr;

    ADC_Configure();
    UART_Configure();

    while(1)
    {
        adc_reading = ADC_GetConversion(0);
        /* Convert to temperature in 0.01°C units */
        temp_x100 = (adc_reading * 500UL) / 1024;

        ptr = msg;
        *ptr++ = 'T'; *ptr++ = 'e'; *ptr++ = 'm'; *ptr++ = 'p'; *ptr++ = ':'; *ptr++ = ' ';
        ConvertU16ToString(temp_x100 / 100, ptr);
        while(*ptr) ptr++;
        *ptr++ = '.';
        ConvertU16ToString(temp_x100 % 100, ptr);
        while(*ptr) ptr++;
        if((temp_x100 % 100) < 10) *ptr++ = '0';
        *ptr++ = ' '; *ptr++ = 'C'; *ptr++ = '\r'; *ptr++ = '\n'; *ptr = '\0';

        UART_TransmitString(msg);
        SoftDelay(400000);
    }
}