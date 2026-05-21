/**
 * @file    main.c
 * @brief   Application entry point and interrupt dispatcher.
 *
 * @details main.c does only two application-level jobs:
 *            1. choose which exercise to run (APP_ACTIVE_TEST below);
 *            2. host the chip's single interrupt vector and fan it out to the
 *               per-driver handlers.
 *          It contains no register access -- the interrupt() routine only
 *          *calls* MCAL handlers, each of which owns its own flag logic. That
 *          keeps the "zero register access in the APP layer" rule intact even
 *          for the interrupt path.
 *
 * @note    Hardware configuration bits are not set in source for mikroC PRO;
 *          set them in Project > Edit Project to:
 *            - Oscillator: HS (20 MHz crystal)
 *            - Watchdog Timer: OFF
 *            - Low Voltage Programming: OFF
 *            - Brown-out Reset: ON (recommended)
 */
#include "../SERVICES/Types.h"

/* MCAL interfaces -- included only for the two interrupt handler prototypes. */
#include "../MCAL/EXTI_interface.h"
#include "../MCAL/TMR0_interface.h"

/* Application exercises -- one entry function each. */
#include "test_gpio.h"
#include "test_exti.h"
#include "test_tmr0.h"
#include "test_pwm.h"
#include "app_adc.h"
#include "app_uart.h"
#include "app_spi.h"
#include "app_i2c.h"

/* --- Test selector -----------------------------------------------------
 * The eight exercises each end in an infinite loop, so exactly one is built
 * into the running image. Change this value to flash a different exercise. */
#define TEST_GPIO   0
#define TEST_EXTI   1
#define TEST_TMR0   2
#define TEST_PWM    3
#define APP_ADC     4
#define APP_UART    5
#define APP_SPI     6
#define APP_I2C     7

#define APP_ACTIVE_TEST     TEST_GPIO

/**
 * @brief  Global interrupt service routine.
 *
 * @details The PIC16F877A has one interrupt vector for every source, so this
 *          single routine is the only ISR in the build. It delegates to each
 *          driver's handler; a handler whose flag is not pending returns
 *          immediately, so calling all of them unconditionally is both correct
 *          and cheap. New interrupt-driven drivers are added by inserting one
 *          more handler call here.
 */
void interrupt(void)
{
    vEXTI_IsrHandler();
    vTMR0_IsrHandler();
}

/**
 * @brief  Program entry: hand control to the selected exercise.
 *
 * @details The switch-case dispatches once and never returns -- every
 *          exercise owns its own super-loop. The trailing while(1) exists
 *          only so the compiler sees a defined end state.
 */
void main(void)
{
    switch (APP_ACTIVE_TEST)
    {
        case TEST_GPIO: vTest_Gpio(); break;
        case TEST_EXTI: vTest_Exti(); break;
        case TEST_TMR0: vTest_Tmr0(); break;
        case TEST_PWM:  vTest_Pwm();  break;
        case APP_ADC:   vApp_Adc();   break;
        case APP_UART:  vApp_Uart();  break;
        case APP_SPI:   vApp_Spi();   break;
        case APP_I2C:   vApp_I2c();   break;
        default:        /* no exercise selected */ break;
    }

    while (1)
    {
        /* unreachable -- each exercise loops forever on its own. */
    }
}
