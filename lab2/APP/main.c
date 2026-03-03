#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void ToggleLed_Callback(void)
{
    LED_Toggle(GPIO_PORTB, GPIO_PIN1);  }

void main()
{
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    SWITCH_Init(GPIO_PORTB, GPIO_PIN0);

    EXT_INT0_SetCallback(ToggleLed_Callback);
    EXT_INT0_Init();

    while(1)
    {

    }
}