#include "../SERVICES/std_types.h"
#include "../SERVICES/bit_math.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"

void GPIO_voidSetPinDirection(unsigned char copy_u8Port, unsigned char copy_u8Pin, unsigned char copy_u8Direction) {
    if (copy_u8Direction == GPIO_INPUT) {
        switch(copy_u8Port) {
            case GPIO_PORTA: SET_BIT(TRISA_REG, copy_u8Pin); break;
            case GPIO_PORTB: SET_BIT(TRISB_REG, copy_u8Pin); break;
            case GPIO_PORTC: SET_BIT(TRISC_REG, copy_u8Pin); break;
            case GPIO_PORTD: SET_BIT(TRISD_REG, copy_u8Pin); break;
        }
    } else {
        switch(copy_u8Port) {
            case GPIO_PORTA: CLR_BIT(TRISA_REG, copy_u8Pin); break;
            case GPIO_PORTB: CLR_BIT(TRISB_REG, copy_u8Pin); break;
            case GPIO_PORTC: CLR_BIT(TRISC_REG, copy_u8Pin); break;
            case GPIO_PORTD: CLR_BIT(TRISD_REG, copy_u8Pin); break;
        }
    }
}

void GPIO_voidSetPinValue(unsigned char copy_u8Port, unsigned char copy_u8Pin, unsigned char copy_u8Value) {
    if (copy_u8Value == GPIO_HIGH) {
        switch(copy_u8Port) {
            case GPIO_PORTA: SET_BIT(PORTA_REG, copy_u8Pin); break;
            case GPIO_PORTB: SET_BIT(PORTB_REG, copy_u8Pin); break;
            case GPIO_PORTC: SET_BIT(PORTC_REG, copy_u8Pin); break;
            case GPIO_PORTD: SET_BIT(PORTD_REG, copy_u8Pin); break;
        }
    } else {
        switch(copy_u8Port) {
            case GPIO_PORTA: CLR_BIT(PORTA_REG, copy_u8Pin); break;
            case GPIO_PORTB: CLR_BIT(PORTB_REG, copy_u8Pin); break;
            case GPIO_PORTC: CLR_BIT(PORTC_REG, copy_u8Pin); break;
            case GPIO_PORTD: CLR_BIT(PORTD_REG, copy_u8Pin); break;
        }
    }
}
