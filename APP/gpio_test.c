#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../HAL/LED/LED_interface.h"

/* Test: Blink LED on RA0, read button on RB0 and mirror to RA1 */
void GPIO_Test(void)
{
    u8 i;

    /* Setup */
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);

    /* Blink RA0 a few times */
    for(i = 0; i < 10; i++)
    {
        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
        /* Simple delay */
        { volatile u16 d; for(d=0; d<60000; d++); }

        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
        { volatile u16 d; for(d=0; d<60000; d++); }
    }

    /* Read RB0 and mirror to RA1 */
    while(1)
    {
        u8 val = GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN0);
        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN1, val);
    }
}
