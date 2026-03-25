#include "PUSH_BUTTON_INTERFACE.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void PUSH_BUTTON_Init(u8 Port, u8 Pin)
{
    GPIO_SetPinDirection(Port, Pin, GPIO_INPUT);
}

 unsigned int BUTTON_Read(u8 Port , u8 Pin) {
    if(port == GPIO_PORTB) {
        return (PORTB & (1 << pin)) ? 1 : 0;
    }
    return 0;
 }
