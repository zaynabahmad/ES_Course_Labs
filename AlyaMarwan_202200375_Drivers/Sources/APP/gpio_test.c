#include "led.h"
#include "switch.h"

void GPIO_Test(void)
{
    LED_Init();
    SWITCH_Init();

    while(1)
    {
        if(SWITCH_Read() == SWITCH_PRESSED)
            LED_On();
        else
            LED_Off();
    }
}