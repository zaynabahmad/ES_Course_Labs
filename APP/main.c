#include "app_tests.h"

int main(void)
{
    APP_Test_GPIO();
    APP_Test_EXT_INT();
    APP_Test_TIMER0();
    APP_Test_PWM();
    APP_Test_ADC();
    APP_Test_UART();
    APP_Test_SPI();
    APP_Test_I2C();

    while (1)
    {
    }

    return 0;
}
