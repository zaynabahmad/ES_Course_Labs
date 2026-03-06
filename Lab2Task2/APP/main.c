#include "../MCAL/GPIO/gpio_interface.h"
#include "../MCAL/EXT_INT/ext_int_interface.h"

#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/switch_interface.h"

#define LED_PORT _PORTA
#define LED_PIN 0

#define SW_PORT _PORTB
#define SW_PIN 0

void LED_Toggle(void);

void main()
{

    GPIO_Init();

    LED_Init(LED_PORT, LED_PIN, LED_PORT, LED_PIN);

    SWITCH_Init(SW_PORT, SW_PIN);

    EXT_INT0_SetEdge(FALLING_EDGE);

    EXT_INT0_SetCallback(LED_Toggle);

    EXT_INT0_Init();

    EXT_INT0_Enable();

    while (1)
    {
        /* empty loop */
    }
}

/* toggle function */

void LED_Toggle(void)
{
    static unsigned char state = 0;

    if (state == 0)
    {
        LED_On(LED_PORT, LED_PIN);
        state = 1;
    }
    else
    {
        LED_Off(LED_PORT, LED_PIN);
        state = 0;
    }
}