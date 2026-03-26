#include "../TIMER0/TIMER0_interface.h"
#include "../EXTI/EXTI_interface.h"

void __interrupt() ISR(void)
{
    TIMER0_HandleInterrupt();
    EXT_INT0_HandleInterrupt();
}