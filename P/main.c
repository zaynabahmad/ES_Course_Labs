/* ============================================================
 * main.c  -  Drivers Project Entry Point
 * Target : PIC16F877A  |  Compiler : mikroC Pro for PIC
 * ============================================================ */

#include "App/gpio_test.h"
#include "App/exti_test.h"
#include "App/timer_test.h"
#include "App/pwm_test.h"
#include "App/adc_test.h"
#include "App/uart_test.h"
#include "App/i2c_test.h"
#include "App/spi_test.h"
#include "MCAL/TIMER0/TIMER0_private.h"
#include "MCAL/GPIO/GPIO_private.h"
#include "SERVICES/bit_math.h"

/* ---- Globals ---- */
static unsigned int counter = 0;

/* ============================================================
 * Interrupt Service Routine
 * ============================================================ */
void interrupt(void)
{
    /* --- Timer0 overflow --- */
    if (GET_BIT(INTCON_REG, TMR0IF))
    {
        counter++;
        if (counter >= 61)
        {
            TOG_BIT(PORTB_REG, 0);   /* Toggle RB0 LED */
            counter = 0;
        }
        CLR_BIT(INTCON_REG, TMR0IF);
    }

    /* --- External interrupt (RB0/INT) --- */
    if (GET_BIT(INTCON_REG, INTF))
    {
        TOG_BIT(PORTB_REG, 1);       /* Toggle RB1 LED */
        CLR_BIT(INTCON_REG, INTF);
    }
}

/* ============================================================
 * main
 * Uncomment exactly ONE test at a time to run it.
 * ============================================================ */
void main(void)
{
    GPIO_Test();
    //EXTI_Test();
    //TIMER_Test();
    //PWM_Test();
    //ADC_Test();
    //UART_Test();
    //I2C_Test();
    //SPI_Test();
}
