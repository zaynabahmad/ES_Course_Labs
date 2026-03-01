#include "LED_interface.h"
#include "../../SERVICES/STD_TYPES.h"

void LED_Init(unsigned char port, unsigned char pin){
    GPIO_SetPinDirection(port, pin, GPIO_OUTPUT);
    GPIO_SetPinValue(port, pin, GPIO_LOW);
}

void LED_Toggle(unsigned char port, unsigned char pin){
    if(GPIO_GetPinValue(port, pin))
        GPIO_SetPinValue(port, pin, GPIO_LOW);
    else
        GPIO_SetPinValue(port, pin, GPIO_HIGH);
}