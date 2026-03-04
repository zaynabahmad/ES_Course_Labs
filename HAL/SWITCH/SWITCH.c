#include "../MCAL/GPIO/GPIO_interface.h"
#include "SWITCH_config.h"
#include "SWITCH_private.h"
#include "STD_TYPES.h"

void SWITCH_INTI()
{
    GPIO_SetPinDirection(SWTICH_0_PORT, SWITCH_0_PIN, GPIO_INPUT);
    GPIO_SetPinDirection(SWITCH_1_PORT, SWITCH_1_PIN, GPIO_INPUT);
}

bool SWITCH_CHECK(unsigned int switch_)
{
    switch(switch_)
    {
    case SWITCH_0:
        return GPIO_GetPinValue(SWTICH_0_PORT,SWITCH_0_PIN);

    case SWITCH_1:
        return GPIO_GetPinValue(SWITCH_1_PORT,SWITCH_1_PIN);
    
    default:
        return false;
        break;
    }
}