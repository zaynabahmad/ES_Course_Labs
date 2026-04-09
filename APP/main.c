/*
 * main.c — Driver Test Application Entry Point
 * Target: PIC16F877A, Fosc = 4 MHz
 */

#include "gpio_test.h"
#include "ext_int_test.h"
#include "timer0_test.h"
#include "pwm_test.h"
#include "adc_test.h"
#include "uart_test.h"
#include "spi_test.h"
#include "i2c_test.h"

void main(void)
{
    /* =========================================================
     * CHOOSE YOUR TEST — Uncomment ONE line at a time
     * ========================================================= */

    // APP_GPIO_Test();
    // APP_EXT_INT_Test();
    // APP_TIMER0_Test();
    // APP_PWM_Test();
    APP_ADC_Test();
    // APP_UART_Test();
    // APP_SPI_Test();
    // APP_I2C_Test();

    while (1)
    {
        /* Fallback trap if a test accidentally returns */
    }
}