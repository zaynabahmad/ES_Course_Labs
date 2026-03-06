#include "ext_int_interface.h"
#include "ext_int_private.h"
#include "../GPIO/gpio_interface.h"


void (*EXT_INT0_Callback)(void) = 0;


/* initialize interrupt */

void EXT_INT0_Init(void)
{
    /* RB0 as input */
    setpindirection(_PORTB , 0 , INPUT);

    /* default edge */
    EXT_INT0_SetEdge(FALLING_EDGE);

    /* clear interrupt flag */
    INTCON &= ~(1 << INTF_BIT);
}


/* enable interrupt */

void EXT_INT0_Enable(void)
{
    INTCON |= (1 << INTE_BIT); // enable INT0

    INTCON |= (1 << GIE_BIT);  // enable global interrupt
}


/* disable interrupt */

void EXT_INT0_Disable(void)
{
    INTCON &= ~(1 << INTE_BIT);
}


/* edge configuration */

void EXT_INT0_SetEdge(unsigned char edge_type)
{
    if(edge_type == RISING_EDGE)
    {
        OPTION_REG |= (1 << INTEDGE_BIT);
    }
    else
    {
        OPTION_REG &= ~(1 << INTEDGE_BIT);
    }
}


/* callback registration */

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    if(ptr != 0)
    {
        EXT_INT0_Callback = ptr;
    }
}




void __interrupt() ISR(void)
{
    if(INTCON & (1 << INTF_BIT))
    {
        INTCON &= ~(1 << INTF_BIT);

        if(EXT_INT0_Callback != 0)
        {
            EXT_INT0_Callback();
        }
    }
}