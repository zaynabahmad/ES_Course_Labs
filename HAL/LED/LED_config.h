#ifndef LED_CONFIG_H
#define LED_CONFIG_H

#include "../../MCAL/GPIO/GPIO_interface.h"

#define LED1_PORT    GPIO_PORTB
#define LED1_PIN     GPIO_PIN1    /* RB1 — toggles every 2 seconds */

#define LED2_PORT    GPIO_PORTB
#define LED2_PIN     GPIO_PIN2    /* RB2 — toggles every 1 second  */

#endif
