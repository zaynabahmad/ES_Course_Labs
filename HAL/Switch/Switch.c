#include "Switch.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void SWITCH_Init(uint8 pin) {
    if (pin == 0) GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT); 
    if (pin == 1) GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN1, GPIO_INPUT); 
    if (pin == 2) GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN2, GPIO_INPUT); 
}

uint8 SWITCH_Read(uint8 pin) {
    if (pin == 0) return GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN0);
    if (pin == 1) return GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN1);
    if (pin == 2) return GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN2);
    return GPIO_HIGH; 
}