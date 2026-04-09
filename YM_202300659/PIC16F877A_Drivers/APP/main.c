/*
 * main.c
 * APP Layer - Main Entry Point
 * PIC16F877A Driver Test Suite
 *
 * ============================================================
 * USAGE INSTRUCTIONS:
 * Uncomment ONE test at a time by setting the corresponding
 * #define below to 1. All others must be 0.
 * ============================================================
 *
 * PROJECT STRUCTURE:
 * ------------------
 * MCAL/
 *   GPIO/   gpio_private.h  gpio.h  gpio.c
 *   EXTI/   exti_private.h  exti.h  exti.c
 *   TIMER0/ timer0_private.h timer0.h timer0.c
 *   PWM/    pwm_private.h   pwm.h   pwm.c
 *   ADC/    adc_private.h   adc.h   adc.c
 *   UART/   uart_private.h  uart.h  uart.c
 *   SPI/    spi_private.h   spi.h   spi.c
 *   I2C/    i2c_private.h   i2c.h   i2c.c
 *
 * HAL/
 *   lcd.h  lcd.c
 *
 * SERVICES/
 *   services.h  services.c
 *
 * APP/
 *   gpio_test.h   gpio_test.c
 *   exti_test.h   exti_test.c
 *   timer_test.h  timer_test.c
 *   pwm_test.h    pwm_test.c
 *   adc_test.h    adc_test.c
 *   uart_test.h   uart_test.c
 *   spi_test.h    spi_test.c
 *   i2c_test.h    i2c_test.c
 *   main.c
 */

/* ============================================================
 * SELECT ONE TEST (set 1 to enable, 0 to disable)
 * ============================================================ */
#define TEST_GPIO       0
#define TEST_EXTI       0
#define TEST_TIMER      0
#define TEST_PWM        0
#define TEST_ADC        0
#define TEST_UART       1    /* <-- Active test */
#define TEST_SPI        0
#define TEST_I2C        0

/* ============================================================
 * Include selected test headers
 * ============================================================ */
#if TEST_GPIO
    #include "gpio_test.h"
#endif

#if TEST_EXTI
    #include "exti_test.h"
    #include "../MCAL/EXTI/exti.h"
#endif

#if TEST_TIMER
    #include "timer_test.h"
    #include "../MCAL/TIMER0/timer0.h"
#endif

#if TEST_PWM
    #include "pwm_test.h"
#endif

#if TEST_ADC
    #include "adc_test.h"
#endif

#if TEST_UART
    #include "uart_test.h"
#endif

#if TEST_SPI
    #include "spi_test.h"
#endif

#if TEST_I2C
    #include "i2c_test.h"
#endif

/* ============================================================
 * Interrupt Service Routine
 * MikroC uses the 'interrupt' keyword for ISR
 * All interrupt sources are dispatched here
 * ============================================================ */
void interrupt(void)
{
#if TEST_EXTI
    /* External INT0 on RB0 */
    if(EXTI_GetFlag(EXTI_INT0))
    {
        EXTI_Test_ISR_Handler();
        EXTI_ClearFlag(EXTI_INT0);
    }
    /* PORTB change interrupt */
    if(EXTI_GetFlag(EXTI_RB_CHG))
    {
        EXTI_ClearFlag(EXTI_RB_CHG);
    }
#endif

#if TEST_TIMER
    /* Timer0 overflow */
    if(TIMER0_GetFlag())
    {
        TIMER_Test_ISR_Handler();
        /* Flag cleared inside handler */
    }
#endif
}

/* ============================================================
 * Main Function
 * ============================================================ */
void main(void)
{
    /*
     * Note: Each test function calls its own _Init() internally.
     * Do NOT access any registers directly here.
     */

#if TEST_GPIO
    GPIO_Test_Run();
#endif

#if TEST_EXTI
    EXTI_Test_Run();
#endif

#if TEST_TIMER
    TIMER_Test_Run();
#endif

#if TEST_PWM
    PWM_Test_Run();
#endif

#if TEST_ADC
    ADC_Test_Run();
#endif

#if TEST_UART
    UART_Test_Run();
#endif

#if TEST_SPI
    SPI_Test_Run();
#endif

#if TEST_I2C
    I2C_Test_Run();
#endif

    /* Safety: should never reach here */
    while(1);
}
