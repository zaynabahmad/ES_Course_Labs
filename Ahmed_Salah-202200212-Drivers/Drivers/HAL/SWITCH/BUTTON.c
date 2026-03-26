#include "../../SERVICES/Std_Types.h"
#include "BUTTON.h"

void H_Button_voidInit(u8 copy_u8Port, u8 copy_u8Pin) {
    GPIO_voidSetPinDirection(copy_u8Port, copy_u8Pin, INPUT);
}

u8 H_Button_u8GetValue(u8 copy_u8Port, u8 copy_u8Pin) {
    return GPIO_u8GetPinValue(copy_u8Port, copy_u8Pin);
}