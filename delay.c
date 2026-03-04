#include "delay.h"

void delay_ms_custom(unsigned int time)
{
     while(time--)
     {
         Delay_ms(1);
     }
}