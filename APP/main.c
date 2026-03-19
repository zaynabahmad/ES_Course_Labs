#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SW_interface.h"
/* Task1
void main(void)
{
    GPIO_Init();
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    SW_Init(GPIO_PORTA,GPIO_PIN0);
    SW_Init(GPIO_PORTA,GPIO_PIN1);

    while(1)
    {
        if (SW_GetState(GPIO_PORTA,GPIO_PIN0) == SW_PRESSED)
        {
            // Short Sequence: 0.2s (200ms)
            LED_On(GPIO_PORTB, GPIO_PIN0);
            LED_On(GPIO_PORTB, GPIO_PIN1);
            Delay_ms(200);

            LED_Off(GPIO_PORTB, GPIO_PIN0);
            LED_Off(GPIO_PORTB, GPIO_PIN1);
            Delay_ms(200);
        }
        else if (SW_GetState(GPIO_PORTA,GPIO_PIN1) == SW_PRESSED)
        {
            // Long Sequence: 0.5s (500ms)
            LED_On(GPIO_PORTB, GPIO_PIN0);
            LED_On(GPIO_PORTB, GPIO_PIN1);
            delay_ms(500);

            LED_Off(GPIO_PORTB, GPIO_PIN0);
            LED_Off(GPIO_PORTB, GPIO_PIN1);
            delay_ms(500);
        }
        else
        {
            // No switch pressed: Turn off LEDs
            LED_Off(GPIO_PORTB, GPIO_PIN0);
            LED_Off(GPIO_PORTB, GPIO_PIN1);
        }
    }
} */

void App_ToggleLED(void)
{
    LED_Toggle(GPIO_PORTC, GPIO_PIN0);
}
void main(void)
{
    LED_Init(GPIO_PORTC, GPIO_PIN0);
    SW_Init(GPIO_PORTB, GPIO_PIN0);
    EXT_INT0_Init();
    EXT_INT0_SetEdge(RISING_EDGE);
    EXT_INT0_SetCallback(App_ToggleLED);
    EXT_INT0_Enable();
    while (1)
    {

    }

}