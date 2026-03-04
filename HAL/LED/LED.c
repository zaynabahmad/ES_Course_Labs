#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void LED_Init(u8 Port, u8 Pin)



void LED_On(u8 Port, u8 Pin)
{
#if LED_SYSTEM_CONN == LED_FORWARD
    GPIO_SetPinValue(Port, Pin, GPIO_HIGH);
#else
    GPIO_SetPinValue(Port, Pin, GPIO_LOW);
#endif
}


void LED_Off(u8 Port, u8 Pin)
{
#if LED_SYSTEM_CONN == LED_FORWARD
    GPIO_SetPinValue(Port, Pin, GPIO_LOW);
#else
    GPIO_SetPinValue(Port, Pin, GPIO_HIGH);
#endif
}

void LED_Toggle(u8 Port, u8 Pin)
        GPIO_SetPinValue(Port, Pin, GPIO_LOW);
        
        
    else
        GPIO_SetPinValue(Port, Pin, GPIO_HIGH);
}

