#ifndef SWITCH_CONFIG_H
#define SWITCH_CONFIG_H

/*
 * Default switch wiring:
 * One side of the switch → PORTB pin 0
 * Other side            → GND
 * Pull-up resistor (or MCU internal pull-up) on the pin
 * → Pin reads HIGH when open, LOW when pressed  (ACTIVE_LOW)
 *
 * Change these to match your hardware.
 */

#define SWITCH_DEFAULT_PORT     GPIO_PORTB
#define SWITCH_DEFAULT_PIN      GPIO_PIN0
#define SWITCH_DEFAULT_ACTIVE   SWITCH_ACTIVE_LOW

#endif