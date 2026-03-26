#include "SWITCH_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void SWITCH_Init(const Switch_t* sw)
{
    if(sw == NULL_PTR)
        return;

    GPIO_SetPinDirection(sw->Port, sw->Pin, GPIO_INPUT);
}

Switch_State_t SWITCH_GetState(const Switch_t* sw)
{
    u8 raw_value;

    if(sw == NULL_PTR)
        return SWITCH_RELEASED;

    raw_value = GPIO_GetPinValue(sw->Port, sw->Pin);

    if(sw->ConnectionType == SWITCH_ACTIVE_HIGH)
    {
        if(raw_value == GPIO_HIGH)
            return SWITCH_PRESSED;
        else
            return SWITCH_RELEASED;
    }
    else
    {
        if(raw_value == GPIO_LOW)
            return SWITCH_PRESSED;
        else
            return SWITCH_RELEASED;
    }
}