#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIO_INPUT     1
#define GPIO_OUTPUT    0

#define GPIO_LOW       0
#define GPIO_HIGH      1

#define GPIO_PORTA     0
#define GPIO_PORTB     1
#define GPIO_PORTC     2
#define GPIO_PORTD     3
#define GPIO_PORTE     4

#define GPIO_PIN0      0
#define GPIO_PIN1      1
#define GPIO_PIN2      2
#define GPIO_PIN3      3
#define GPIO_PIN4      4
#define GPIO_PIN5      5
#define GPIO_PIN6      6
#define GPIO_PIN7      7

void GPIO_SetPinDirection(unsigned char port, unsigned char pin, unsigned char dir);
void GPIO_WritePin(unsigned char port, unsigned char pin, unsigned char val);
unsigned char GPIO_ReadPin(unsigned char port, unsigned char pin);
void GPIO_TogglePin(unsigned char port, unsigned char pin);

#endif