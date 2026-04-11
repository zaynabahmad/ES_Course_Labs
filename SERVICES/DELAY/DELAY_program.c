#include "DELAY_interface.h"

void Delay_ms(u16 time)
{
    volatile u16 i, j;
    for(i = 0; i < time; i++)
    {
        for(j = 0; j < 1275; j++)
        {
        }
    }
}

void Delay_us(u16 time)
{
    volatile u16 i;
    while(time--)
    {
        for(i = 0; i < 1; i++)
        {
        }
    }
}