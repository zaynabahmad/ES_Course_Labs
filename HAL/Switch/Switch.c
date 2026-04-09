#include "Switch_interface.h"
#include "Switch_config.h"
#include "Switch_private.h"

/* MCAL Dependencies */
#include "../../MCAL/GPIO/GPIO_interface.h"

void SWITCH_Init(u8 Port, u8 Pin)
{
    /* Configure the specific pin as an input */
    GPIO_SetPinDirection(Port, Pin, GPIO_INPUT);
}

u8 SWITCH_GetState(u8 Port, u8 Pin, u8 ConnectionType)
{
    u8 pin_value = GPIO_GetPinValue(Port, Pin);
    u8 state = SWITCH_RELEASED;

    /* Handle Pull-Up Resistor (Active Low) */
    if (ConnectionType == SWITCH_PULL_UP)
    {
        if (pin_value == GPIO_LOW)
            state = SWITCH_PRESSED;
        else
            state = SWITCH_RELEASED;
    }
    /* Handle Pull-Down Resistor (Active High) */
    else if (ConnectionType == SWITCH_PULL_DOWN)
    {
        if (pin_value == GPIO_HIGH)
            state = SWITCH_PRESSED;
        else
            state = SWITCH_RELEASED;
    }

    return state;
}

u8 SWITCH_GetStateDebounced(u8 Port, u8 Pin, u8 ConnectionType)
{
    u8 state1, state2;
    
    /* Read the switch first time */
    state1 = SWITCH_GetState(Port, Pin, ConnectionType);
    
    /* Wait for the mechanical bounce to settle using mikroC built-in delay */
    Delay_ms(SWITCH_DEBOUNCE_TIME_MS);
    
    /* Read the switch a second time */
    state2 = SWITCH_GetState(Port, Pin, ConnectionType);
    
    /* If both readings are the same, the signal is stable */
    if (state1 == state2)
    {
        return state1;
    }
    
    /* If they differ, it's noise/bouncing. Return released as a safe default */
    return SWITCH_RELEASED;
}