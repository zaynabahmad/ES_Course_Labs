#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define OUTPUT 0
#define INPUT  1

#define HIGH 1
#define LOW  0

void GPIO_voidSetPinDirection(u8 port, u8 pin, u8 dir);
void GPIO_voidSetPinValue(u8 port, u8 pin, u8 val);

#endif