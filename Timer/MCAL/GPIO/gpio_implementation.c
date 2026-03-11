#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "gpio_interface.h"



void set_pin_direction(u8 port, u8 pin, u8 direction) {
    switch(port) {
        case _PORTA:
            if(direction == OUTPUT) {
                CLR_BIT(TRISA, pin);  /* Clear bit for output */
            } else if (direction == INPUT) {
                SET_BIT(TRISA, pin);  /* Set bit for input */
            }
            break;
        case _PORTB:
            if(direction == OUTPUT) {
                CLR_BIT(TRISB, pin);
            } else if (direction == INPUT) {
                SET_BIT(TRISB, pin);
            }
            break;
        case _PORTC:
            if(direction == OUTPUT) {
                CLR_BIT(TRISC, pin);
            } else if (direction == INPUT) {
                SET_BIT(TRISC, pin);
            }
            break;
        case _PORTD:
            if(direction == OUTPUT) {
                CLR_BIT(TRISD, pin);
            } else if (direction == INPUT) {
                SET_BIT(TRISD, pin);
            }
            break;
        case _PORTE:
            if(direction == OUTPUT) {
                CLR_BIT(TRISE, pin);
            } else if (direction == INPUT) {
                SET_BIT(TRISE, pin);
            }
            break;
    }
}

void set_pin_value(u8 port, u8 pin, u8 value) {
    switch(port) {
        case _PORTA:
            if(value == HIGH) {
                SET_BIT(PORTA, pin);
            } else {
                CLR_BIT(PORTA, pin);
            }
            break;
        case _PORTB:
            if(value == HIGH) {
                SET_BIT(PORTB, pin);
            } else {
                CLR_BIT(PORTB, pin);
            }
            break;
        case _PORTC:
            if(value == HIGH) {
                SET_BIT(PORTC, pin);
            } else {
                CLR_BIT(PORTC, pin);
            }
            break;
        case _PORTD:
            if(value == HIGH) {
                SET_BIT(PORTD, pin);
            } else {
                CLR_BIT(PORTD, pin);
            }
            break;
        case _PORTE:
            if(value == HIGH) {
                SET_BIT(PORTE, pin);
            } else {
                CLR_BIT(PORTE, pin);
            }
            break;
    }
}

u8 get_pin_value(u8 port, u8 pin) {
    switch(port) {
        case _PORTA: return GET_BIT(PORTA, pin);
        case _PORTB: return GET_BIT(PORTB, pin);
        case _PORTC: return GET_BIT(PORTC, pin);
        case _PORTD: return GET_BIT(PORTD, pin);
        case _PORTE: return GET_BIT(PORTE, pin);
        default:     return 0;
    }
}
void toggle_pin(u8 port, u8 pin) {
    switch(port) {
        case _PORTA:
            PORTA ^= (1 << pin);
            break;

        case _PORTB:
            PORTB ^= (1 << pin);
            break;

        case _PORTC:
            PORTC ^= (1 << pin);
            break;

        case _PORTD:
            PORTD ^= (1 << pin);
            break;

        case _PORTE:
            PORTE ^= (1 << pin);
            break;
    }
}