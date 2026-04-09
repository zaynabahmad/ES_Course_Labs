#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:/ES-Project-Lab/MCAL/GPIO/gpio.h"
#include "D:/ES-Project-Lab/MCAL/EXTI/exti_interface.h"
#include "D:\ES-Project-Lab\HAL\led_interface.h"
void toggle_led(void) {
    static u8 state = 0;
    if(state == 0) {
        LED_On(GPIO_PORTD, GPIO_PIN1);
        state = 1;
    } else {
        LED_off(GPIO_PORTD, GPIO_PIN1);
        state = 0;
    }
}

void app_exti_test(void) {
    GPIO_setPinDirection(GPIO_PORTD, GPIO_PIN1, GPIO_OUTPUT);
    GPIO_setPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);

    EXTI_init(EXTI_FALLING_EDGE);

    while(1) {
        if (exti_flag == 1) {
            toggle_led();   // ? SAFE: called in main, not interrupt
            exti_flag = 0;
        }
    }
}