#include "../pic_config.h"
#include "exti.h"
#include "../GPIO/gpio.h"

void interrupt() {
    if (INTF_bit) {
        TOGGLE_BIT(PORTD, 0);
        INTF_bit = 0;
    }
}

int main(void) {
    ADCON1 = 0x06;   

    GPIO_setupPinDirection(PORTD_ID, PIN0_ID, PIN_OUTPUT);
    GPIO_writePin(PORTD_ID, PIN0_ID, GPIO_LOW);

    OPTION_REGbits.nRBPU = 0;

    EXTI_init(EXTI_INT_PIN, EXTI_FALLING_EDGE);

    while (1) {
    }
    return 0;
}
