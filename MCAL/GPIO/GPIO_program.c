#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

void GPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction) {
    if (Copy_u8Direction == GPIO_INPUT) {
        switch(Copy_u8Port) {
            case GPIO_PORTA: SET_BIT(TRISA_REG, Copy_u8Pin); break;
            case GPIO_PORTB: SET_BIT(TRISB_REG, Copy_u8Pin); break;
            case GPIO_PORTC: SET_BIT(TRISC_REG, Copy_u8Pin); break;
            case GPIO_PORTD: SET_BIT(TRISD_REG, Copy_u8Pin); break;
        }
    } else {
        switch(Copy_u8Port) {
            case GPIO_PORTA: CLR_BIT(TRISA_REG, Copy_u8Pin); break;
            case GPIO_PORTB: CLR_BIT(TRISB_REG, Copy_u8Pin); break;
            case GPIO_PORTC: CLR_BIT(TRISC_REG, Copy_u8Pin); break;
            case GPIO_PORTD: CLR_BIT(TRISD_REG, Copy_u8Pin); break;
        }
    }
}

void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value) {
    if (Copy_u8Value == GPIO_HIGH) {
        switch(Copy_u8Port) {
            case GPIO_PORTA: SET_BIT(PORTA_REG, Copy_u8Pin); break;
            case GPIO_PORTB: SET_BIT(PORTB_REG, Copy_u8Pin); break;
            case GPIO_PORTC: SET_BIT(PORTC_REG, Copy_u8Pin); break;
            case GPIO_PORTD: SET_BIT(PORTD_REG, Copy_u8Pin); break;
        }
    } else {
        switch(Copy_u8Port) {
            case GPIO_PORTA: CLR_BIT(PORTA_REG, Copy_u8Pin); break;
            case GPIO_PORTB: CLR_BIT(PORTB_REG, Copy_u8Pin); break;
            case GPIO_PORTC: CLR_BIT(PORTC_REG, Copy_u8Pin); break;
            case GPIO_PORTD: CLR_BIT(PORTD_REG, Copy_u8Pin); break;
        }
    }
}