#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define OUTPUT 1
#define INPUT  0

#define HIGH 1
#define LOW  0

void GPIO_SetPinDirection(char port, char pin, char direction);
void GPIO_WritePin(char port, char pin, char value);
char GPIO_ReadPin(char port, char pin);

#endif