#include "EXTI_interface.h"
#include "EXTI_private.h"

void EXTI_Init(unsigned char edge)
{
    if(edge == RISING_EDGE)
        OPTION_REG |= (1 << INTEDG);
    else
        OPTION_REG &= ~(1 << INTEDG);
}

void EXTI_Enable(void)
{
    INTCON_REG |= (1 << INTE); // enable INT0
    INTCON_REG |= (1 << GIE);  // global interrupt
}

void EXTI_Disable(void)
{
    INTCON_REG &= ~(1 << INTE);
}