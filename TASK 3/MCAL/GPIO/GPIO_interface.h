#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define PORTB_ID    1
#define PORTD_ID    3

#define PIN_INPUT   1
#define PIN_OUTPUT  0

void MGPIO_vSetPinDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction);
void MGPIO_vTogglePin(uint8 Copy_u8Port, uint8 Copy_u8Pin);

#endif