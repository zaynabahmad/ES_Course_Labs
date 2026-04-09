#ifndef GPIO_H
#define GPIO_H

#include "../std_types.h"
#include <xc.h>

typedef enum {
    PORTA_ID,
    PORTB_ID,
    PORTC_ID,
    PORTD_ID,
    PORTE_ID
} GPIO_PortID;

typedef enum {
    PIN0_ID = 0,
    PIN1_ID = 1,
    PIN2_ID = 2,
    PIN3_ID = 3,
    PIN4_ID = 4,
    PIN5_ID = 5,
    PIN6_ID = 6,
    PIN7_ID = 7
} GPIO_PinID;

typedef enum { PIN_INPUT  = 1, PIN_OUTPUT = 0 } GPIO_PinDirection;
typedef enum { PORT_INPUT = 0xFF, PORT_OUTPUT = 0x00 } GPIO_PortDirection;

#define GPIO_HIGH   1
#define GPIO_LOW    0

void  GPIO_setupPinDirection (GPIO_PortID port, GPIO_PinID pin, GPIO_PinDirection dir);
void  GPIO_writePin          (GPIO_PortID port, GPIO_PinID pin, uint8 value);
uint8 GPIO_readPin           (GPIO_PortID port, GPIO_PinID pin);
void  GPIO_setupPortDirection(GPIO_PortID port, GPIO_PortDirection dir);
void  GPIO_writePort         (GPIO_PortID port, uint8 value);
uint8 GPIO_readPort          (GPIO_PortID port);

#endif /* GPIO_H */
