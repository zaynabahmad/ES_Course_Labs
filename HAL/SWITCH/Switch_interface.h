#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "Switch_private.h"
#include "Switch_config.h"

/* Return values for Switch_GetState */
#define SWITCH_PRESSED      1
#define SWITCH_RELEASED     0

/*
 * Configure the pin as an input.
 * port      : GPIO_PORTA … GPIO_PORTE
 * pin       : GPIO_PIN0  … GPIO_PIN7
 * active    : SWITCH_ACTIVE_LOW or SWITCH_ACTIVE_HIGH
 */
void Switch_Init(u8 port, u8 pin, u8 active);

/*
 * Return SWITCH_PRESSED (1) or SWITCH_RELEASED (0).
 * active must match what was passed to Switch_Init().
 */
u8 Switch_GetState(u8 port, u8 pin, u8 active);

/*
 * Convenience: returns 1 if the switch is currently pressed.
 */
u8 Switch_IsPressed(u8 port, u8 pin, u8 active);

#endif