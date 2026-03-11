#include "../../SERVICES/STD_TYPES.h"
#include "SWITCH_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void SWITCH_Init(u8 pin) {
    
    GPIO_SetPinDirection(GPIO_PORTB, pin, GPIO_INPUT);
}