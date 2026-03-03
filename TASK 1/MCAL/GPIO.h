#ifndef GPIO_H
#define GPIO_H

#define OUTPUT 0
#define INPUT  1

#define LOW  0
#define HIGH 1

void GPIO_SetPinDirection(unsigned short *tris, unsigned short pin, unsigned short direction);
void GPIO_WritePin(unsigned short *port, unsigned short pin, unsigned short value);
unsigned short GPIO_ReadPin(unsigned short *port, unsigned short pin);

#endif