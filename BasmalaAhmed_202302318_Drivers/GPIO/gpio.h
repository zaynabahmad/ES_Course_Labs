#ifndef GPIO_H_
#define GPIO_H_

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define OUTPUT 1
#define INPUT  0

void GPIO_setPinDirection(unsigned char port, unsigned char pin, unsigned char direction);
void GPIO_writePin(unsigned char port, unsigned char pin, unsigned char value);

#endif
