#include "GPIO_interface.h"
#include "LED_interface.h"
#include "switch.h"
#include "ext_int0.h"
void App_ToggleLED(void)
{
    LED_Toggle(GPIO_PORTB, GPIO_PIN1);
}

void main()
{
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    SWITCH_Init(GPIO_PIN0);
    EXT_INT0_Init();
    EXT_INT0_SetCallback(App_ToggleLED);
    EXT_INT0_Enable();
    while (1)
    {}
}