#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define INPUT  1
#define OUTPUT 0

#define LOW  0
#define HIGH 1

// Ports
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4

// Pins
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

void GPIO_SetPinDirection(unsigned char port, unsigned char pin, unsigned char direction);
void GPIO_WritePin(unsigned char port, unsigned char pin, unsigned char value);
unsigned char GPIO_ReadPin(unsigned char port, unsigned char pin);
void GPIO_TogglePin(unsigned char port, unsigned char pin);

#endif