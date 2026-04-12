#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"

void TIMER0_Test(void)
{
    u8 i;
    u32 j;

    // Multiple timer test cycles
    for (i = 0; i < 5; i++)
    {
        // Simulate timer counting
        for (j = 0; j < 50000; j++);
    }

    // Final wait
    for (j = 0; j < 100000; j++);
}
