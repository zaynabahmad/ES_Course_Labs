#include "led.h"
#include "ext_int.h"

unsigned char flagPressed = 0;

void EXT_INT_Test(void)
{
    LED_Init();
    EXT_INT_Init();

    while(1)
    {
        if(flagPressed == 1)
        {
            LED_Toggle();
            flagPressed = 0;
        }
    }
}