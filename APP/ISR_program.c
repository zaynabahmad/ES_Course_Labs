#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"

void interrupt(void)
{
    TIMER0_HandleInterrupt();
    EXT_INT0_HandleInterrupt();
}