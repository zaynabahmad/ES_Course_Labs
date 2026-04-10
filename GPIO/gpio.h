// gpio.h - GPIO driver header
#ifndef GPIO_H
#define GPIO_H

#include "std_types.h"
#include "common_macros.h"
#include "pic_config.h"

#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3
#define PORTE_ID 4

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define INPUT 1
#define OUTPUT 0

#define LOW 0
#define HIGH 1

// Function prototypes
void GPIO_SetPinDirection(uint8 port_id, uint8 pin_num, uint8 direction);
void GPIO_WritePin(uint8 port_id, uint8 pin_num, uint8 value);
uint8 GPIO_ReadPin(uint8 port_id, uint8 pin_num);
void GPIO_TogglePin(uint8 port_id, uint8 pin_num);

#endif