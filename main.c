#include "../MCAL/ei.h"
#include "../HAL/LED/led.h"
#include "../HAL/SWITCH/switch.h"

void APP_Togg(void)
{
    led_Toggle();
}
void main()
{
    led_Init();
    switch_Init(0);
    EI_Init();
    EI_SetEdge(RISING_EDGE);
    EI_SetCallback(APP_Togg);
    EI_Enable();
    while(1)
    {
    }
}