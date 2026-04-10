#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/* Port Definitions */
#define GPIO_PORTA  0
#define GPIO_PORTB  1
#define GPIO_PORTC  2
#define GPIO_PORTD  3
#define GPIO_PORTE  4

/* Direction Definitions */
#define GPIO_OUTPUT 0
#define GPIO_INPUT  1

/* Value Definitions */
#define GPIO_LOW    0
#define GPIO_HIGH   1

/* Function Prototypes */
void GPIO_voidSetPortDirection(unsigned char copy_u8Port, unsigned char copy_u8Direction);
void GPIO_voidSetPinDirection(unsigned char copy_u8Port, unsigned char copy_u8Pin, unsigned char copy_u8Direction);
void GPIO_voidSetPortValue(unsigned char copy_u8Port, unsigned char copy_u8Value);
void GPIO_voidSetPinValue(unsigned char copy_u8Port, unsigned char copy_u8Pin, unsigned char copy_u8Value);
unsigned char GPIO_u8GetPinValue(unsigned char copy_u8Port, unsigned char copy_u8Pin);

#endif