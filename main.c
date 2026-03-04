#include "../HAL/LED/LED_INTERFACE.h"
#include "../HAL/SWITCH/SWITCH_INTERFACE.h"
#include "../MCAL/GPIO/GPIO_INTERFACE.h"
#include "../MCAL/EXT_INT0/EXT_INT0_INTERFACE.h"

void Toggle_My_LED(void) {
    LED_Toggle(GPIO_PORTC, GPIO_PIN0);
}

void main() {
    LED_Init(GPIO_PORTC, GPIO_PIN0);
    switchInit(GPIO_PORTB, GPIO_PIN0);

    EXT_INT0_Init();
    EXT_INT0_SetEdge(RISING_EDGE);
    EXT_INT0_SetCallback(Toggle_My_LED);
    EXT_INT0_Enable();

    while(1) {

    }
}