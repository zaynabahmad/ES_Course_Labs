// gpio.c - GPIO driver implementation
#include "gpio.h"

void GPIO_SetPinDirection(uint8 port_id, uint8 pin_num, uint8 direction) {
    switch(port_id) {
        case PORTA_ID:
            if(direction == OUTPUT)
                CLEAR_BIT(TRISA, pin_num);
            else
                SET_BIT(TRISA, pin_num);
            break;
        case PORTB_ID:
            if(direction == OUTPUT)
                CLEAR_BIT(TRISB, pin_num);
            else
                SET_BIT(TRISB, pin_num);
            break;
        case PORTC_ID:
            if(direction == OUTPUT)
                CLEAR_BIT(TRISC, pin_num);
            else
                SET_BIT(TRISC, pin_num);
            break;
        case PORTD_ID:
            if(direction == OUTPUT)
                CLEAR_BIT(TRISD, pin_num);
            else
                SET_BIT(TRISD, pin_num);
            break;
        case PORTE_ID:
            if(direction == OUTPUT)
                CLEAR_BIT(TRISE, pin_num);
            else
                SET_BIT(TRISE, pin_num);
            break;
    }
}

void GPIO_WritePin(uint8 port_id, uint8 pin_num, uint8 value) {
    switch(port_id) {
        case PORTA_ID:
            if(value == HIGH)
                SET_BIT(PORTA, pin_num);
            else
                CLEAR_BIT(PORTA, pin_num);
            break;
        case PORTB_ID:
            if(value == HIGH)
                SET_BIT(PORTB, pin_num);
            else
                CLEAR_BIT(PORTB, pin_num);
            break;
        case PORTC_ID:
            if(value == HIGH)
                SET_BIT(PORTC, pin_num);
            else
                CLEAR_BIT(PORTC, pin_num);
            break;
        case PORTD_ID:
            if(value == HIGH)
                SET_BIT(PORTD, pin_num);
            else
                CLEAR_BIT(PORTD, pin_num);
            break;
        case PORTE_ID:
            if(value == HIGH)
                SET_BIT(PORTE, pin_num);
            else
                CLEAR_BIT(PORTE, pin_num);
            break;
    }
}

uint8 GPIO_ReadPin(uint8 port_id, uint8 pin_num) {
    switch(port_id) {
        case PORTA_ID: return READ_BIT(PORTA, pin_num);
        case PORTB_ID: return READ_BIT(PORTB, pin_num);
        case PORTC_ID: return READ_BIT(PORTC, pin_num);
        case PORTD_ID: return READ_BIT(PORTD, pin_num);
        case PORTE_ID: return READ_BIT(PORTE, pin_num);
        default: return 0;
    }
}

void GPIO_TogglePin(uint8 port_id, uint8 pin_num) {
    switch(port_id) {
        case PORTA_ID: TOGGLE_BIT(PORTA, pin_num); break;
        case PORTB_ID: TOGGLE_BIT(PORTB, pin_num); break;
        case PORTC_ID: TOGGLE_BIT(PORTC, pin_num); break;
        case PORTD_ID: TOGGLE_BIT(PORTD, pin_num); break;
        case PORTE_ID: TOGGLE_BIT(PORTE, pin_num); break;
    }
}