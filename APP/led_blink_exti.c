#include <xc.h>
#define _XTAL_FREQ 8000000

#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/GPIO/EXTI0/EXTI_Interface.h"

/* LED Definition */
#define LED_PORT   GPIO_PORTB
#define LED_PIN    GPIO_PIN1

void Toggle_LED(void)
{
    LED_Toggle(LED_PORT, LED_PIN);
}

void main(void)
{
    LED_Init(LED_PORT, LED_PIN);

    EXTI_Init();
    EXTI_SetCallBack(Toggle_LED);
    EXTI_Enable();

    while(1)
    {
        /* Main loop empty */
    }

}

