/*
 * APPLICATION LAYER
 * Task 1: LED Sequences Controlled by Switches
 * + External Interrupt (INT0) - LED Toggle on Button Press
 * PIC16F877A @ 8MHz
 *
 * RB0 (pin 33) = Push Button INT0   (INPUT)
 * RB1 (pin 34) = LED                (OUTPUT)
 * RB2 (pin 35) = SW1 fast blink     (INPUT)
 * RB3 (pin 36) = SW2 slow blink     (INPUT)
 * RB4 (pin 37) = LED1 for sequences (OUTPUT)
 * RB5 (pin 38) = LED2 for sequences (OUTPUT)
 */

#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/EXTI/EXTI_private.h"
#include "../HAL/BUTTON/BUTTON_interface.h"
#include "../SERVICES/BIT_MATH.h"

/* -------------------------------------------------- */
/* ISR - fires automatically when button on RB0 pressed */

void interrupt(void)
{
    if(GET_BIT(INTCON, 1))
    {
        /* Toggle RB1 directly - no function call */
        TOG_BIT(PORTB, 1);

        EXTI_ClearFlag();
    }
}

/* -------------------------------------------------- */
/* MAIN                                               */
/* -------------------------------------------------- */
void main()
{
    u8 sw1, sw2;

    /* --- INT0 Task --- */
    /* LED on RB1 */
    LED_Init(GPIO_PORTB, GPIO_PIN1);

    /* Button on RB0 (INT0 fixed pin) */
    BUTTON_Init(GPIO_PORTB, GPIO_PIN0);

    /* Enable external interrupt */
    EXTI_Init();

    /* --- Sequence Task --- */
    /* LEDs on RB4 and RB5 */
    LED_Init(GPIO_PORTB, GPIO_PIN4);
    LED_Init(GPIO_PORTB, GPIO_PIN5);

    /* Switches on RB2 and RB3 */
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN2, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN3, GPIO_INPUT);

    while(1)
    {
        sw1 = GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN2);
        sw2 = GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN3);

        if(sw1 == GPIO_HIGH)
        {
            /* SW1 pressed - fast blink 200ms */
            LED_On(GPIO_PORTB,  GPIO_PIN4);
            LED_On(GPIO_PORTB,  GPIO_PIN5);
            Delay_ms(200);
            LED_Off(GPIO_PORTB, GPIO_PIN4);
            LED_Off(GPIO_PORTB, GPIO_PIN5);
            Delay_ms(200);
        }
        else if(sw2 == GPIO_HIGH)
        {
            /* SW2 pressed - slow blink 500ms */
            LED_On(GPIO_PORTB,  GPIO_PIN4);
            LED_On(GPIO_PORTB,  GPIO_PIN5);
            Delay_ms(500);
            LED_Off(GPIO_PORTB, GPIO_PIN4);
            LED_Off(GPIO_PORTB, GPIO_PIN5);
            Delay_ms(500);
        }
        else
        {
            /* Nothing pressed - LEDs off */
            LED_Off(GPIO_PORTB, GPIO_PIN4);
            LED_Off(GPIO_PORTB, GPIO_PIN5);
        }
    }
}