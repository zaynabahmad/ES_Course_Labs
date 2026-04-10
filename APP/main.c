// ES_Drivers/APP/main.c
#include "app_config.h"
#include "LED_test.h"
#include "extint_test.h"
#include "timer_test.h"
#include "PWM_test.h"
#include "ADC_test.h"
#include "UART_test.h"

void main()
{
#if defined(RUN_LED_TEST)
    LED_Test();
#elif defined(RUN_EXTINT_TEST)
    EXTINT_Test();
#elif defined(RUN_TIMER_TEST)
    TIMER_Test();
#elif defined(RUN_PWM_TEST)
    PWM_Test();
#elif defined(RUN_ADC_TEST)
    ADC_Test();
#elif defined(RUN_UART_TEST)
    UART_Test();
#endif
    while(1) {}
}