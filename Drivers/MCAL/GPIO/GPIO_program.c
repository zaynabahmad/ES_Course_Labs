#include "../../SERVICES/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_private.h"
#include "../../MCAL/GPIO/GPIO_config.h"
#include "../../MCAL/GPIO/GPIO_interface.h"


void GPIO_voidSetPinDirection(GPIO_Port_t Copy_Port, GPIO_Pin_t Copy_Pin, GPIO_PinDir_t Copy_Dir) {
    switch(Copy_Port) {
        case GPIO_PORTA: (Copy_Dir == GPIO_PIN_OUTPUT) ? CLEAR_BIT(TRISA, Copy_Pin) : SET_BIT(TRISA, Copy_Pin); break;
        case GPIO_PORTB: (Copy_Dir == GPIO_PIN_OUTPUT) ? CLEAR_BIT(TRISB, Copy_Pin) : SET_BIT(TRISB, Copy_Pin); break;
        case GPIO_PORTC: (Copy_Dir == GPIO_PIN_OUTPUT) ? CLEAR_BIT(TRISC, Copy_Pin) : SET_BIT(TRISC, Copy_Pin); break;
        case GPIO_PORTD: (Copy_Dir == GPIO_PIN_OUTPUT) ? CLEAR_BIT(TRISD, Copy_Pin) : SET_BIT(TRISD, Copy_Pin); break;
        case GPIO_PORTE: (Copy_Dir == GPIO_PIN_OUTPUT) ? CLEAR_BIT(TRISE, Copy_Pin) : SET_BIT(TRISE, Copy_Pin); break;
    }
}

void GPIO_voidSetPinValue(GPIO_Port_t Copy_Port, GPIO_Pin_t Copy_Pin, uint8 Copy_Value) {
    switch(Copy_Port) {
        case GPIO_PORTA: (Copy_Value == STD_HIGH) ? SET_BIT(PORTA, Copy_Pin) : CLEAR_BIT(PORTA, Copy_Pin); break;
        case GPIO_PORTB: (Copy_Value == STD_HIGH) ? SET_BIT(PORTB, Copy_Pin) : CLEAR_BIT(PORTB, Copy_Pin); break;
        case GPIO_PORTC: (Copy_Value == STD_HIGH) ? SET_BIT(PORTC, Copy_Pin) : CLEAR_BIT(PORTC, Copy_Pin); break;
        case GPIO_PORTD: (Copy_Value == STD_HIGH) ? SET_BIT(PORTD, Copy_Pin) : CLEAR_BIT(PORTD, Copy_Pin); break;
        case GPIO_PORTE: (Copy_Value == STD_HIGH) ? SET_BIT(PORTE, Copy_Pin) : CLEAR_BIT(PORTE, Copy_Pin); break;
    }
}

uint8 GPIO_u8GetPinValue(GPIO_Port_t Copy_Port, GPIO_Pin_t Copy_Pin) {
    switch(Copy_Port) {
        case GPIO_PORTA: return GET_BIT(PORTA, Copy_Pin);
        case GPIO_PORTB: return GET_BIT(PORTB, Copy_Pin);
        case GPIO_PORTC: return GET_BIT(PORTC, Copy_Pin);
        case GPIO_PORTD: return GET_BIT(PORTD, Copy_Pin);
        case GPIO_PORTE: return GET_BIT(PORTE, Copy_Pin);
        default: return 0;
    }
}
