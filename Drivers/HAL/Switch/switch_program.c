#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../HAL/Switch/switch_interface.h"


uint8 HAL_SWITCH_u8GetState(uint8 Copy_Port, uint8 Copy_Pin) {
    GPIO_voidSetPinDirection(Copy_Port, Copy_Pin, GPIO_PIN_INPUT);
    return GPIO_u8GetPinValue(Copy_Port, Copy_Pin);
}