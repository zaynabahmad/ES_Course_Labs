#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

/* MCAL Layer Inclusions */
#include "../../MCAL/GPIO/GPIO_interface.h"

/* HAL Layer Inclusions */
#include "SWITCH_config.h"
#include "SWITCH_private.h"
#include "SWITCH_interface.h"

void SWITCH_voidInit(u8 Copy_u8SwitchId)
{
    if (Copy_u8SwitchId == SWITCH_1)
    {
        GPIO_SetPinDirection(SW1_PORT, SW1_PIN, GPIO_INPUT);
    }
    else if (Copy_u8SwitchId == SWITCH_2)
    {
        GPIO_SetPinDirection(SW2_PORT, SW2_PIN, GPIO_INPUT);
    }
}

u8 SWITCH_u8GetState(u8 Copy_u8SwitchId)
{
    u8 Local_u8State = SWITCH_NOT_PRESSED;
    u8 Local_u8PinValue = 0;

    if (Copy_u8SwitchId == SWITCH_1)
    {
        Local_u8PinValue = GPIO_GetPinValue(SW1_PORT, SW1_PIN);
        
        /* Check against Active Low state */
        if (Local_u8PinValue == SW1_ACTIVE_STATE)
        {
            Local_u8State = SWITCH_PRESSED;
        }
    }
    else if (Copy_u8SwitchId == SWITCH_2)
    {
        Local_u8PinValue = GPIO_GetPinValue(SW2_PORT, SW2_PIN);
        
        /* Check against Active High state */
        if (Local_u8PinValue == SW2_ACTIVE_STATE)
        {
            Local_u8State = SWITCH_PRESSED;
        }
    }

    return Local_u8State;
}

/* Wrapper function to match the exact syntax requested in the lab skeleton */
u8 SW2_Read(void)
{
    /* * This simply calls our standard, reusable HAL function 
     * but provides the specific API name the instructor wants.
     */
    return SWITCH_u8GetState(SWITCH_2);
}