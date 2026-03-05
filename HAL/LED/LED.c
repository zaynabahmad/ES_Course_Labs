#include "LED.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void LED_Init(uint8 pin) {
    if (pin == 0) GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN0, GPIO_OUTPUT);
    if (pin == 1) GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN1, GPIO_OUTPUT);
    if (pin == 2) GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN2, GPIO_OUTPUT);
}

void LED_On(uint8 pin) {
    if (pin == 0) GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN0, GPIO_HIGH);
    if (pin == 1) GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN1, GPIO_HIGH);
    if (pin == 2) GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN2, GPIO_HIGH);
}

void LED_Off(uint8 pin) {
    if (pin == 0) GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN0, GPIO_LOW);
    if (pin == 1) GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN1, GPIO_LOW);
    if (pin == 2) GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN2, GPIO_LOW);
}

void LED_Toggle(uint8 pin) {
    u8 current_val = 0;
    if (pin == 0) { 
        current_val = GPIO_GetPinValue(GPIO_PORTD, GPIO_PIN0); 
        GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN0, !current_val); 
    }
    if (pin == 1) { 
        current_val = GPIO_GetPinValue(GPIO_PORTD, GPIO_PIN1); 
        GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN1, !current_val); 
    }
    if (pin == 2) { 
        current_val = GPIO_GetPinValue(GPIO_PORTD, GPIO_PIN2); 
        GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN2, !current_val); 
    }
}