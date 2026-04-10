#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "LED_interface.h"

void LED_voidInit(u8 copy_u8Led) {
    if(copy_u8Led == LED0) {
        GPIO_voidSetPinDirection(GPIO_PORTB, 0, GPIO_OUTPUT);
    }
}

void LED_voidOn(u8 copy_u8Led) {
    if(copy_u8Led == LED0) {
        GPIO_voidSetPinValue(GPIO_PORTB, 0, GPIO_HIGH);
    }
}

void LED_voidOff(u8 copy_u8Led) {
    if(copy_u8Led == LED0) {
        GPIO_voidSetPinValue(GPIO_PORTB, 0, GPIO_LOW);
    }
}