#include "led.h"
#include "timer0.h"

unsigned char overflowCount = 0;
unsigned char timerFlag     = 0;

void TIMER0_Test(void)
{
    LED_Init();
    TIMER0_Init();

    while(1)
    {
        if(timerFlag == 1)
        {
            timerFlag = 0;
            LED_Toggle();
        }
    }
}