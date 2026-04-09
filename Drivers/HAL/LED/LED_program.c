#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../HAL/LED/LED_interface.h"


void HAL_LED_voidTurnOn(uint8 Copy_Port, uint8 Copy_Pin) {
    GPIO_voidSetPinDirection(Copy_Port, Copy_Pin, GPIO_PIN_OUTPUT);
    GPIO_voidSetPinValue(Copy_Port, Copy_Pin, STD_HIGH);
}

void HAL_LED_voidTurnOff(uint8 Copy_Port, uint8 Copy_Pin) {
    GPIO_voidSetPinDirection(Copy_Port, Copy_Pin, GPIO_PIN_OUTPUT);
    GPIO_voidSetPinValue(Copy_Port, Copy_Pin, STD_LOW);
}