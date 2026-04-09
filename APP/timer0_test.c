#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:/ES-Project-Lab/MCAL/GPIO/gpio.h"
#include "D:/ES-Project-Lab/MCAL/TIMER0/timer0_interface.h"
#include "D:/ES-Project-Lab/MCAL/EXTI/exti_interface.h"
#include "D:\ES-Project-Lab\HAL\led_interface.h"
void app_timer0_test(void) {

    LED_Init(GPIO_PORTD, GPIO_PIN1);

    TIMER0_init();
    TIMER0_setPreload(0);
    TIMER0_enableInterrupt();

    while(1) {

        if (timer0_flag == 1) {

            // Toggle LED
            static u8 state = 0;
            state ^= 1;
            LED_Toggle(GPIO_PORTD, GPIO_PIN1);

            TIMER0_setPreload(0);  // reload
            timer0_flag = 0;
        }
    }
}