#include "gpio_test.h"
#include "ext_int_test.h"
#include "timer0_test.h"
#include "uart_test.h"
#include "adc_test.h"
#include "pwm_test.h"
#include "spi_test.h"
#include "i2c_test.h"

int main(void)
{
    gpio_test_run();
    ext_int_test_run();
    timer0_test_run();
    uart_test_run();
    adc_test_run();
    pwm_test_run();
    spi_test_run();
    i2c_test_run();

    while (1) {}

    return 0;
}
