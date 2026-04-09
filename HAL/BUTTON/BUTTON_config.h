#ifndef BUTTON_CONFIG_H
#define BUTTON_CONFIG_H

/* Button active level:
 *   BUTTON_ACTIVE_LOW  — button connects pin to GND (pull-up on VDD side)
 *   BUTTON_ACTIVE_HIGH — button connects pin to VDD (pull-down on GND side)
 */
#define BUTTON_ACTIVE_LOW   0
#define BUTTON_ACTIVE_HIGH  1

#define BUTTON_LOGIC   BUTTON_ACTIVE_LOW

#endif
