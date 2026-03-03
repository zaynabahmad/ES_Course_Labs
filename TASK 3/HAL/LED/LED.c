#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "LED_config.h"
#include "LED_interface.h"

void HLED_vInit(void) {
    MGPIO_vSetPinDirection(LED_PORT_ID, LED_PIN_ID, PIN_OUTPUT);
}

void HLED_vToggle(void) {
    MGPIO_vTogglePin(LED_PORT_ID, LED_PIN_ID);
}