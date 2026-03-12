/*
 * APPLICATION LAYER
 */

#define SET_BIT(REG,BIT)      ( (REG) |=  (1U << (BIT)) )
#define CLR_BIT(REG,BIT)      ( (REG) &= ~(1U << (BIT)) )
#define TOG_BIT(REG,BIT)      ( (REG) ^=  (1U << (BIT)) )
#define GET_BIT(REG,BIT)      ( ((REG) >> (BIT)) & 1U )

#include "../HAL/LED/LED_interface.h"
#include "../HAL/Switch/SWITCH_INTERFACE.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/Timer/TIMER_INTERFACE.h"

volatile unsigned char tickCounter = 0;
volatile unsigned char led2Counter = 0;

void Timer0_TaskHandler(void)
{
    if (tickCounter < 30)
    {
        T0_Reset();
        tickCounter++;
    }
    else if (tickCounter == 30)
    {
        T0_SetValue(125);
        tickCounter++;
    }
    else
    {
        tickCounter = 0;
        LED_Toggle(GPIO_PORTB, GPIO_PIN1);

        if (led2Counter < 2)
        {
            led2Counter++;
        }
        else
        {
            led2Counter = 0;
            LED_Toggle(GPIO_PORTB, GPIO_PIN2);
        }
    }
}

void main(void)
{
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);

    T0_Init();
    T0_Enable();
    T0_SetCallback(Timer0_TaskHandler);

    while (1)
    {
    }
}
