#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "GPIO_interface.h"

void MGPIO_vSetPinDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction) {
    if (Copy_u8Port == PORTB_ID) {
        if (Copy_u8Direction == PIN_INPUT) SET_BIT(TRISB, Copy_u8Pin);
        else CLR_BIT(TRISB, Copy_u8Pin);
    } else if (Copy_u8Port == PORTD_ID) {
        if (Copy_u8Direction == PIN_INPUT) SET_BIT(TRISD, Copy_u8Pin);
        else CLR_BIT(TRISD, Copy_u8Pin);
    }
}

void MGPIO_vTogglePin(uint8 Copy_u8Port, uint8 Copy_u8Pin) {
    if (Copy_u8Port == PORTB_ID) TOG_BIT(PORTB, Copy_u8Pin);
    else if (Copy_u8Port == PORTD_ID) TOG_BIT(PORTD, Copy_u8Pin);
}