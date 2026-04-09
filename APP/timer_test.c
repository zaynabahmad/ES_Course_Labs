#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT0/EXT_INT0_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/USART/USART_interface.h"
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "timer_test.h"
#include "ISR_Actions.h"

volatile unsigned int tick_counter = 0;

void TIMER_Test(void)
{
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);
    Timer0_Init();
    Timer0_EnableInterrupt();
    Timer0_EnableGlobalInterrupts();


    while(1)
    {
        if (g_flag_timer)
        {
            g_flag_timer = 0;

            tick_counter++;
            if (tick_counter % 1000 == 0)
                LED_Toggle(GPIO_PORTB, GPIO_PIN2);
            if (tick_counter >= 2000)
            {
                LED_Toggle(GPIO_PORTB, GPIO_PIN1);
                tick_counter = 0;
            }
        }
    }
}