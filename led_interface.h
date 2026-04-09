#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../SERVICES/types.h"
#include "../../MCAL/GPIO/gpio_interface.h"

#define LED_STATE_OFF   0
#define LED_STATE_ON    1

static inline void LED_Setup(u8 port, u8 pin) {
    GPIO_ConfigPin(port, pin, DIR_OUT);
}
static inline void LED_TurnOn(u8 port, u8 pin) {
    GPIO_WritePin(port, pin, LEVEL_HIGH);
}
static inline void LED_TurnOff(u8 port, u8 pin) {
    GPIO_WritePin(port, pin, LEVEL_LOW);
}
static inline void LED_SwitchState(u8 port, u8 pin) {
    u8 cur = GPIO_ReadPin(port, pin);
    GPIO_WritePin(port, pin, (cur == LEVEL_HIGH) ? LEVEL_LOW : LEVEL_HIGH);
}

#endif