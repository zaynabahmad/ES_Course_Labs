#include "LED.h"

void H_LED_voidInit(u8 copy_u8Port, u8 copy_u8Pin) {
    GPIO_voidSetPinDirection(copy_u8Port, copy_u8Pin, OUTPUT);
}

void H_LED_voidOn(u8 copy_u8Port, u8 copy_u8Pin) {
    GPIO_voidSetPinValue(copy_u8Port, copy_u8Pin, HIGH);
}

void H_LED_voidOff(u8 copy_u8Port, u8 copy_u8Pin) {
    GPIO_voidSetPinValue(copy_u8Port, copy_u8Pin, LOW);
}

void H_LED_voidToggle(u8 copy_u8Port, u8 copy_u8Pin) {
    u8 local_u8State = GPIO_u8GetPinValue(copy_u8Port, copy_u8Pin);
    if(local_u8State == LOW) GPIO_voidSetPinValue(copy_u8Port, copy_u8Pin, HIGH);
    else                     GPIO_voidSetPinValue(copy_u8Port, copy_u8Pin, LOW);
}