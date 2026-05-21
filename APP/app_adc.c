/**
 * @file    app_adc.c
 * @brief   ADC streaming application -- combines two MCAL drivers.
 *
 * @details This file shows the value of a clean MCAL boundary: it wires the
 *          ADC and UART drivers together without either driver knowing the
 *          other exists. The application is the only place that decides "read
 *          AN0, then print it".
 */
#include "app_adc.h"
#include "../MCAL/ADC_interface.h"
#include "../MCAL/UART_interface.h"

/** Analogue channel under test. */
#define APP_ADC_CHANNEL         ADC_CH_AN0

/** Gap between successive samples, in milliseconds. */
#define APP_ADC_PERIOD_MS       250u

void vApp_Adc(void)
{
    word_t u16Sample;
    char   acText[7];                   /* up to "65535" + sign + NUL. */

    vADC_Init();
    vUART_Init();

    while (1)
    {
        u16Sample = u16ADC_Capture(APP_ADC_CHANNEL);

        /* IntToStr is a mikroC library helper -- left-padded, so the result
         * is forwarded as-is for a fixed-width, easily-parsed line. */
        IntToStr((int)u16Sample, acText);

        vUART_SendString("ADC=");
        vUART_SendString(acText);
        vUART_SendString("\r\n");

        Delay_ms(APP_ADC_PERIOD_MS);
    }
}
