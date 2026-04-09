#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT0/EXT_INT0_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/USART/USART_interface.h"
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "PWM_test.h"

volatile u8 duty_state = 0;
volatile u8 flag_update_pwm = 1;

void PWM_ButtonPress_Handler(void)
{
    duty_state++;
    if (duty_state > 3)
    {
        duty_state = 0;
    }
    /* Set the flag to tell the while(1) loop to update the hardware */
    flag_update_pwm = 1;
}

void PWM_Test(void)
{

    ADC_voidSetAllDigital();

    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN2, GPIO_OUTPUT);

    PWM_voidInit();


    EXT_INT_Init(falling_edge);           // edge passed as parameter
    EXT_INT_SetCallback(PWM_ButtonPress_Handler);
    EXT_INT_Enable();                     // handles INTCON internally in MCAL
    Timer0_EnableGlobalInterrupts();      // MCAL owns INTCON, not APP

    duty_state = 0;
    PWM_voidSetDutyCycle(25);
    flag_update_pwm = 0;

    while (1)
    {
        if (flag_update_pwm)
        {
            u8 duty = (duty_state + 1) * 25;
            flag_update_pwm = 0;
            PWM_voidSetDutyCycle(duty);
        }
    }
}