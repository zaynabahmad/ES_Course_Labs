#include "../INT0/EXT_INT0_private.h"
#include "../TIMER0/TIMER0_private.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

// extern callbacks
extern void (*EXT_INT0_Callback)(void);
extern void (*TIMER0_Callback)(void);

void interrupt()
{
    // ================= INT0 =================
    if(GET_BIT(INTCON_REG, 1)) // INTF
    {
        if(EXT_INT0_Callback != 0)
            EXT_INT0_Callback();

        CLR_BIT(INTCON_REG, 1);
    }

    // ================= TIMER0 =================
    if(GET_BIT(INTCON_REG, 2)) // T0IF
    {
        if(TIMER0_Callback != 0)
            TIMER0_Callback();

        CLR_BIT(INTCON_REG, 2);
    }
}