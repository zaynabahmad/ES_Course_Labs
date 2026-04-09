#include "../HAL/LED/LED_interface.h"

void GPIO_test(void) {
    LED_voidInit(LED0);

    while(1) {
        LED_voidOn(LED0);
        Delay_ms(500);
        LED_voidOff(LED0);
        Delay_ms(500);
    }
}