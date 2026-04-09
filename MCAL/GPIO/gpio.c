#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:/ES-Project-Lab/SERVICES/bit_math.h"

#include "gpio_prv.h"
#include "gpio.h"

void GPIO_setPinDirection(u8 port, u8 pin, u8 direction) {
    if(pin > 7) return;
    if (direction == GPIO_INPUT) {
        switch (port) {
            case GPIO_PORTA: SET_BIT(TRISA_REG, pin); break;
            case GPIO_PORTB: SET_BIT(TRISB_REG, pin); break;
            case GPIO_PORTC: SET_BIT(TRISC_REG, pin); break;
            case GPIO_PORTD: SET_BIT(TRISD_REG, pin); break;
            case GPIO_PORTE: SET_BIT(TRISE_REG, pin); break;
        }
    } else {
        switch (port) {
            case GPIO_PORTA: CLR_BIT(TRISA_REG, pin); break;
            case GPIO_PORTB: CLR_BIT(TRISB_REG, pin); break;
            case GPIO_PORTC: CLR_BIT(TRISC_REG, pin); break;
            case GPIO_PORTD: CLR_BIT(TRISD_REG, pin); break;
            case GPIO_PORTE: CLR_BIT(TRISE_REG, pin); break;
        }
    }
}

void GPIO_setPinValue(u8 port, u8 pin, u8 value) {
    if(pin > 7) return;
    if (value == GPIO_HIGH) {
        switch (port) {
            case GPIO_PORTA: SET_BIT(PORTA_REG, pin); break;
            case GPIO_PORTB: SET_BIT(PORTB_REG, pin); break;
            case GPIO_PORTC: SET_BIT(PORTC_REG, pin); break;
            case GPIO_PORTD: SET_BIT(PORTD_REG, pin); break;
            case GPIO_PORTE: SET_BIT(PORTE_REG, pin); break;
        }
    } else {
        switch (port) {
            case GPIO_PORTA: CLR_BIT(PORTA_REG, pin); break;
            case GPIO_PORTB: CLR_BIT(PORTB_REG, pin); break;
            case GPIO_PORTC: CLR_BIT(PORTC_REG, pin); break;
            case GPIO_PORTD: CLR_BIT(PORTD_REG, pin); break;
            case GPIO_PORTE: CLR_BIT(PORTE_REG, pin); break;
        }
    }
}

u8 GPIO_getPinValue(u8 port, u8 pin) {
    u8 pinVal = 0;
    if(pin > 7) return 0;
    switch (port) {
        case GPIO_PORTA: pinVal = GET_BIT(PORTA_REG, pin); break;
        case GPIO_PORTB: pinVal = GET_BIT(PORTB_REG, pin); break;
        case GPIO_PORTC: pinVal = GET_BIT(PORTC_REG, pin); break;
        case GPIO_PORTD: pinVal = GET_BIT(PORTD_REG, pin); break;
        case GPIO_PORTE: pinVal = GET_BIT(PORTE_REG, pin); break;
    }
    return pinVal;
}

void GPIO_setPortDirection(u8 port, u8 direction) {
    switch(port) {
        case GPIO_PORTA: TRISA_REG = direction; break;
        case GPIO_PORTB: TRISB_REG = direction; break;
        case GPIO_PORTC: TRISC_REG = direction; break;
        case GPIO_PORTD: TRISD_REG = direction; break;
        case GPIO_PORTE: TRISE_REG = direction; break;
    }
}

void GPIO_setPortValue(u8 port, u8 value) {
    switch(port) {
        case GPIO_PORTA: PORTA_REG = value; break;
        case GPIO_PORTB: PORTB_REG = value; break;
        case GPIO_PORTC: PORTC_REG = value; break;
        case GPIO_PORTD: PORTD_REG = value; break;
        case GPIO_PORTE: PORTE_REG = value; break;
    }
}