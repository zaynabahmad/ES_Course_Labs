#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Port IDs */
#define GPIO_PORTA   0
#define GPIO_PORTB   1
#define GPIO_PORTC   2
#define GPIO_PORTD   3
#define GPIO_PORTE   4

/* Pin IDs */
#define GPIO_PIN0    0
#define GPIO_PIN1    1
#define GPIO_PIN2    2
#define GPIO_PIN3    3
#define GPIO_PIN4    4
#define GPIO_PIN5    5
#define GPIO_PIN6    6
#define GPIO_PIN7    7

/* Direction */
#define GPIO_OUTPUT  0
#define GPIO_INPUT   1

/* Values */
#define GPIO_LOW     0
#define GPIO_HIGH    1

void GPIO_SetPinDirection(uint8 Port, uint8 Pin, uint8 Direction);
void GPIO_SetPinValue(uint8 Port, uint8 Pin, uint8 Value);
uint8 GPIO_GetPinValue(uint8 Port, uint8 Pin);
void GPIO_Init(void);

#endif