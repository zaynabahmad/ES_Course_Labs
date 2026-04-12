#include "GPIO_interface.h"

void test_GPIO(void)
{
    unsigned char btn_state;

    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_OUTPUT);

    GPIO_WritePin(GPIO_PORTB, GPIO_PIN0, GPIO_HIGH);
    /* rb0 should be high */

    btn_state = GPIO_ReadPin(GPIO_PORTA, GPIO_PIN0);
    /* btn_state reflects ra0 logic level */

    GPIO_TogglePin(GPIO_PORTB, GPIO_PIN0);
    /* rb0 should now be low */
}
