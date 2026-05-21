#include "gpio_test.h"
#include "ext_int_test.h"
#include "timer0_test.h"
#include "pwm_test.h"
#include "adc_test.h"
#include "uart_test.h"
#include "spi_test.h"
#include "i2c_test.h"

int main(void)
{
    GPIO_Test();
    UART_Test();
    EXT_INT_Test();
    TIMER0_Test();
    ADC_Test();
    PWM_Test();
    SPI_Test();
    I2C_Test();

    while(1)
    {
        /* keep running so interrupts can fire */
    }

    return 0;
}
