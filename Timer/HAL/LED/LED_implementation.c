#include "../../SERVICES/std_types.h"
#include "LED_interface.h"

void LED_Init(u8 port, u8 pin) {
    set_pin_direction(port, pin, OUTPUT);
}

void LED_ON(u8 port, u8 pin) {
    set_pin_value(port, pin, HIGH);
}

void LED_OFF(u8 port, u8 pin) {
    set_pin_value(port, pin, LOW);
}
void LED_Toggle(u8 port, u8 pin) {
    toggle_pin(port, pin);
}