#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

/* MCAL Dependencies */
#include "../../MCAL/GPIO/GPIO_interface.h"

void LED_Init(u8 Port, u8 Pin, u8 ConnectionType)
{
    /* Set pin direction to output */
    GPIO_SetPinDirection(Port, Pin, GPIO_OUTPUT);
    
    /* Set the initial state to OFF */
    LED_Off(Port, Pin, ConnectionType);
}

void LED_On(u8 Port, u8 Pin, u8 ConnectionType)
{
    if (ConnectionType == LED_ACTIVE_HIGH)
    {
        GPIO_SetPinValue(Port, Pin, GPIO_HIGH);
    }
    else if (ConnectionType == LED_ACTIVE_LOW)
    {
        GPIO_SetPinValue(Port, Pin, GPIO_LOW);
    }
}

void LED_Off(u8 Port, u8 Pin, u8 ConnectionType)
{
    if (ConnectionType == LED_ACTIVE_HIGH)
    {
        GPIO_SetPinValue(Port, Pin, GPIO_LOW);
    }
    else if (ConnectionType == LED_ACTIVE_LOW)
    {
        GPIO_SetPinValue(Port, Pin, GPIO_HIGH);
    }
}

void LED_Toggle(u8 Port, u8 Pin)
{
    /* Utilize the new, efficient GPIO toggle function */
    GPIO_TogglePinValue(Port, Pin);
}