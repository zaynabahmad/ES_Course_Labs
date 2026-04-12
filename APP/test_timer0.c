#include "TIMER0_interface.h"
#include "GPIO_interface.h"

volatile unsigned char tick = 0;

/* isr defined in main project — set tick = 1 on overflow */

void test_TIMER0(void)
{
    TIMER0_Init();
    TIMER0_Start();

    while (!tick);            /* wait for one overflow */

    TIMER0_Stop();
    tick = 0;

    GPIO_TogglePin(GPIO_PORTB, GPIO_PIN1);   /* visual feedback */
}