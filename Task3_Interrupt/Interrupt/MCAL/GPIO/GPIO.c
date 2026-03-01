#include "GPIO_interface.h"
#include "../../SERVICES/STD_TYPES.h"


void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction){
    switch(Port){
        case GPIO_PORTA: TRISA |= (Direction << Pin); break;
        case GPIO_PORTB: TRISB |= (Direction << Pin); break;
        case GPIO_PORTC: TRISC |= (Direction << Pin); break;
        case GPIO_PORTD: TRISD |= (Direction << Pin); break;
        case GPIO_PORTE: TRISE |= (Direction << Pin); break;
    }
}

void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value){
    switch(Port){
        case GPIO_PORTA:
            if(Value) PORTA |= (1 << Pin);
            else PORTA &= ~(1 << Pin);
            break;
        case GPIO_PORTB:
            if(Value) PORTB |= (1 << Pin);
            else PORTB &= ~(1 << Pin);
            break;
        case GPIO_PORTC:
            if(Value) PORTC |= (1 << Pin);
            else PORTC &= ~(1 << Pin);
            break;
        case GPIO_PORTD:
            if(Value) PORTD |= (1 << Pin);
            else PORTD &= ~(1 << Pin);
            break;
        case GPIO_PORTE:
            if(Value) PORTE |= (1 << Pin);
            else PORTE &= ~(1 << Pin);
            break;
    }
}

u8 GPIO_GetPinValue(u8 Port, u8 Pin){
    u8 val = 0;
    switch(Port){
        case GPIO_PORTA: val = (PORTA >> Pin) & 1; break;
        case GPIO_PORTB: val = (PORTB >> Pin) & 1; break;
        case GPIO_PORTC: val = (PORTC >> Pin) & 1; break;
        case GPIO_PORTD: val = (PORTD >> Pin) & 1; break;
        case GPIO_PORTE: val = (PORTE >> Pin) & 1; break;
    }
    return val;
}