#include "app_tests.h"

#define TEST_GPIO    1
#define TEST_EXT_INT 1
#define TEST_TIMER0  1
#define TEST_PWM     1
#define TEST_ADC     1
#define TEST_UART    1
#define TEST_SPI     1
#define TEST_I2C     1

void main()
{
#if TEST_GPIO
    APP_GPIO_Test();
#endif

#if TEST_EXT_INT
    APP_EXT_INT_Test();
#endif

#if TEST_TIMER0
    APP_TIMER0_Test();
#endif

#if TEST_PWM
    APP_PWM_Test();
#endif

#if TEST_ADC
    APP_ADC_Test();
#endif

#if TEST_UART
    APP_UART_Test();
#endif

#if TEST_SPI
    APP_SPI_Test();
#endif

#if TEST_I2C
    APP_I2C_Test();
#endif

    while(1)
    {
#if TEST_EXT_INT
        APP_EXT_INT_Task();
#endif

#if TEST_TIMER0
        APP_TIMER0_Task();
#endif
    }
}
