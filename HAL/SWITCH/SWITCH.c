#include "SWITCH_interface.h"
#include "SWITCH_private.h"
#include "../../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../../MCAL/EXT_INT/EXT_INT_Private.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

static void (*SWITCH_Callback)(void) = 0;

void SWITCH_Init(void)
{
    CLR_BIT(OPTION_REG, 7); // Enable PORTB pull-ups
    EXT_INT_Init();
    EXT_INT_Enable();
}

u8 SWITCH_GetState(void)
{
    return GPIO_GetPinValue(EXT_INT_PORT, EXT_INT_PIN);
}

void SWITCH_SetCallback(void (*Callback)(void))
{
    if(Callback != 0) {
        SWITCH_Callback = Callback;
        EXT_INT_SetCallback(Callback);
    }
}
