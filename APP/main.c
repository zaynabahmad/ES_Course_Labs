#include "../HAL/LED/LED_interface.h"
#include "../HAL/Switch/switch_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/Interrupt/interrupt_Interface.h"

void App_Toggle_LED(void)
{
    LED_Toggle(GPIO_PORTB, GPIO_PIN0);
}

void main(void)
{
    GPIO_Init();

    LED_Init(GPIO_PORTB, GPIO_PIN0);

    SWITCH_Init(GPIO_PORTB, GPIO_PIN0);

    EXT_INT0_Init();
    EXT_INT0_SetEdge(RISE);

    EXT_INT0_SetCallback(App_Toggle_LED);

    EXT_INT0_Enable();

    while (1)
    {
    }
}