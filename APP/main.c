
void APP_GPIO_Test(void);
void APP_EXTI_Test(void);
void APP_TIMER0_Test(void);
void APP_PWM_Test(void);
void APP_ADC_Test(void);
void APP_UART_Test(void);
void APP_SPI_Test(void);
void APP_I2C_Test(void);

#define APP_TEST_GPIO     1
#define APP_TEST_EXTI     2
#define APP_TEST_TIMER0   3
#define APP_TEST_PWM      4
#define APP_TEST_ADC      5
#define APP_TEST_UART     6
#define APP_TEST_SPI      7
#define APP_TEST_I2C      8

#define APP_SELECTED_TEST  APP_TEST_GPIO
int main(void)
{
#if APP_SELECTED_TEST == APP_TEST_GPIO
    APP_GPIO_Test();
#elif APP_SELECTED_TEST == APP_TEST_EXTI
    APP_EXTI_Test();
#elif APP_SELECTED_TEST == APP_TEST_TIMER0
    APP_TIMER0_Test();
#elif APP_SELECTED_TEST == APP_TEST_PWM
    APP_PWM_Test();
#elif APP_SELECTED_TEST == APP_TEST_ADC
    APP_ADC_Test();
#elif APP_SELECTED_TEST == APP_TEST_UART
    APP_UART_Test();
#elif APP_SELECTED_TEST == APP_TEST_SPI
    APP_SPI_Test();
#elif APP_SELECTED_TEST == APP_TEST_I2C
    APP_I2C_Test();
#else
    while(1)
    {
    }
#endif

    return 0;
}