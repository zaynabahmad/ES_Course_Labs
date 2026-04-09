/*
 * adc_test.c
 * APP Layer - ADC Driver Test
 *
 * Test Description:
 *   - Read AN0 (RA0) potentiometer - display on LED bar (PORTB)
 *   - Read AN1 (RA1) LM35 temperature sensor
 *   - Results sent over UART for monitoring
 */

#include "adc_test.h"
#include "../MCAL/ADC/adc.h"
#include "../MCAL/UART/uart.h"
#include "../MCAL/TIMER0/timer0.h"
#include "../MCAL/GPIO/gpio.h"
#include "../SERVICES/services.h"

void ADC_Test_Init(void)
{
    /* 
     * Right-justified, Fosc/8 clock
     * PCFG=0x05: AN0, AN1 analog; rest digital
     */
    ADC_Init(ADC_CLK_FOSC_8, ADC_RIGHT_JUSTIFIED, ADC_2_ANALOG);

    /* PORTB as LED bar output */
    GPIO_SetPortDirection(GPIO_PORTB, 0x00);   /* All outputs */
    GPIO_WritePort(GPIO_PORTB, 0x00);

    /* UART for debug output at 9600 baud */
    UART_Init(UART_BAUD_9600);
}

void ADC_Test_DisplayOnLEDs(u16 adcValue)
{
    /*
     * Map 0-1023 to 0-8 LED segments
     * Each segment = 1023/8 = ~128 counts
     */
    u8 level = (u8)(adcValue / 128);
    u8 ledMask = 0x00;
    u8 i;

    for(i = 0; i < level && i < 8; i++)
    {
        ledMask |= (1 << i);
    }
    GPIO_WritePort(GPIO_PORTB, ledMask);
}

void ADC_Test_ReadPotentiometer(void)
{
    u16 raw;
    u8  buf[8];

    raw = ADC_Read(ADC_CHANNEL_0);
    ADC_Test_DisplayOnLEDs(raw);

    /* Send via UART: "POT: XXXX\r\n" */
    UART_SendString((u8*)"POT: ");
    Utils_UintToStr(raw, buf);
    UART_SendString(buf);
    UART_SendString((u8*)"\r\n");
}

void ADC_Test_ReadTemperature(void)
{
    u16 raw;
    u16 tempC;
    u8  buf[8];

    /*
     * LM35: 10mV per degree C
     * Vref = 5V, 10-bit ADC -> 1 LSB = 5000/1024 = 4.88 mV
     * Temp(C) = raw * 4.88 / 10 = raw * 0.488
     * Integer approx: Temp = (raw * 488) / 1000
     */
    raw   = ADC_Read(ADC_CHANNEL_1);
    tempC = (u16)((u32)raw * 488 / 1000);

    UART_SendString((u8*)"TEMP: ");
    Utils_UintToStr(tempC, buf);
    UART_SendString(buf);
    UART_SendString((u8*)" C\r\n");
}

void ADC_Test_Run(void)
{
    ADC_Test_Init();
    UART_SendString((u8*)"=== ADC Test Start ===\r\n");

    while(1)
    {
        ADC_Test_ReadPotentiometer();
        ADC_Test_ReadTemperature();
        TIMER0_DelayMs(500);
    }
}
