#include "../SERVICES/types.h"
#include "../SERVICES/bit_ops.h"
#include "../MCAL/EXT_INT/ext_int_private.h"
#include "../MCAL/TIMER0/timer0_private.h"

/* Test runner prototypes */
#include "gpio_test.h"
#include "timer0_test.h"
#include "pwm_test.h"
#include "adc_uart_test.h"
#include "spi_test.h"
#include "i2c_test.h"
#include "ext_int_test.h"

/* MCAL ISR handler prototypes */
void EXTINT_ISR_Handler(void);
void Timer0_ISR_Handler(void);

void interrupt(void)
{
    if(BIT_READ(INTCON, INTF))
    {
        EXTINT_ISR_Handler();
        BIT_CLEAR(INTCON, INTF);
    }
    if(BIT_READ(INTCON, T0IF))
    {
        Timer0_ISR_Handler();
        BIT_CLEAR(INTCON, T0IF);
    }
}

void main(void)
{
    // Uncomment one test:
    //GPIO_Test_Runner();
    //Timer0_Test_Runner();
    // PWM_Test_Runner();
    //ADC_UART_Test_Runner();
    // SPI_Test_Runner();
    // I2C_Test_Runner();
    // ExtInt_Test_Runner();

    while(1);
}
