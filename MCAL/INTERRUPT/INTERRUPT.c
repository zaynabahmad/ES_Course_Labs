#include "../TIMER0/TIMER0_interface.h"
#include "../EXTI/EXTI_interface.h"
#ifdef __GNUC__
void ISR(void)
#else
void __interrupt() ISR(void)
#endif
{
    TIMER0_HandleInterrupt();
    EXT_INT0_HandleInterrupt();
}