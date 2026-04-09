#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"


typedef enum {
    GPIO_PORTA = 0,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE
} GPIO_Port_t;

typedef enum {
    GPIO_PIN0 = 0, GPIO_PIN1, GPIO_PIN2, GPIO_PIN3, GPIO_PIN4,
    GPIO_PIN5, GPIO_PIN6, GPIO_PIN7
} GPIO_Pin_t;

typedef enum {
    GPIO_PIN_INPUT  = 1,
    GPIO_PIN_OUTPUT = 0
} GPIO_PinDir_t;

void GPIO_voidSetPinDirection(GPIO_Port_t Copy_Port, GPIO_Pin_t Copy_Pin, GPIO_PinDir_t Copy_Dir);
void GPIO_voidSetPinValue(GPIO_Port_t Copy_Port, GPIO_Pin_t Copy_Pin, uint8 Copy_Value);
uint8 GPIO_u8GetPinValue(GPIO_Port_t Copy_Port, GPIO_Pin_t Copy_Pin);

#endif