#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "../../SERVICES/types.h"

/* Port identifiers */
#define PORTA_ID    0
#define PORTB_ID    1
#define PORTC_ID    2
#define PORTD_ID    3
#define PORTE_ID    4

/* Pin numbers */
#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7

/* Direction modes */
#define DIR_OUT     0
#define DIR_IN      1

/* Logic levels */
#define LEVEL_LOW   0
#define LEVEL_HIGH  1

void GPIO_ConfigPin(u8 port, u8 pin, u8 direction);
void GPIO_WritePin(u8 port, u8 pin, u8 value);
u8 GPIO_ReadPin(u8 port, u8 pin);
void GPIO_InitAll(void);

#endif