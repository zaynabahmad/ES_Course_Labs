#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../HAL/LED/LED_interface.h"

/* Callback: toggle LED on RA0 when INT fires */
void INT_Callback(void)
{
    static u8 state = 0;
    state ^= 1;
    GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, state);
}

/* Test: external interrupt on RB0 toggles LED on RA0 */
void EXT_INT_Test(void)
{
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);

    EXT_INT_Init();
    EXT_INT_SetEdge(FALLING_EDGE);
    EXT_INT_SetCallback(INT_Callback);
    EXT_INT_Enable();

    while(1)
    {
        /* Waiting for interrupt */
    }
}
