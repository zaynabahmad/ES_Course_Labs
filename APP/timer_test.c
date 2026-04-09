#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

volatile u8 timer_ticks = 0;

void Timer_Callback(void)
{
    timer_ticks++;
    
    if(timer_ticks >= 100)
    {
        LED_Toggle(GPIO_PORTB, GPIO_PIN0);
        timer_ticks = 0;
    }
}

void TIMER_Test(void)
{
    GPIO_Init();
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    
    TIMER0_Init(TIMER0_PRESCALER_256);
    
    TIMER0_SetCallback(Timer_Callback);
    
    TIMER0_EnableInterrupt();
    
    TIMER0_Start();
    
    while(1)
    {
    }
}
