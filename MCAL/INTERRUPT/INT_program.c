#include "INT_interface.h"
#include "INT_private.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

static void (*EXT0_Callback)(void) = NULL_PTR;
extern void (*TIMER0_Callback)(void);
void EXT_INT_Init(u8 Edge)
{
    if(Edge == RISING_EDGE)
        SET_BIT(OPTION_REG , 6);   // INTEDG
    else
        CLR_BIT(OPTION_REG , 6);
}

void EXT_INT_Enable(void)
{
    SET_BIT(INTCON , 4);   // INTE
}

void EXT_INT_Disable(void)
{
    CLR_BIT(INTCON , 4);
}

void EXT_INT_SetCallback(void (*Callback)(void))
{
    EXT0_Callback = Callback;
}

void interrupt()
{
    /* External INT0 */

    if(INTF_bit && EXT0_Callback != NULL_PTR)
    {
        INTF_bit = 0;
        EXT0_Callback();
    }

    /* Timer0 Interrupt */

    if(T0IF_bit)
    {
        T0IF_bit = 0;

        if(TIMER0_Callback != NULL_PTR)
        {
            TIMER0_Callback();
        }
    }
}