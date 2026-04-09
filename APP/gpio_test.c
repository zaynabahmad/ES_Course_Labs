#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:/ES-Project-Lab/MCAL/GPIO/gpio.h"
#include "D:/ES-Project-Lab/MCAL/GPIO/gpio_prv.h"
#include "D:\ES-Project-Lab\HAL\led_interface.h"
void dummy_delay(u32 count) {
    volatile u32 i;
    for(i = 0; i < count; i++);
}

void app_gpio_test(void) {
    // For PIC16F877A: Set PORTA and PORTE as digital I/O instead of analog
    ADCON1_REG = 0x06;

    // Test standard I/O
    GPIO_setPinDirection(GPIO_PORTD, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_setPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);

    // Let's test PORTE output as well since we added it
    GPIO_setPinDirection(GPIO_PORTE, GPIO_PIN0, GPIO_OUTPUT);

    while(1) {
        if(GPIO_getPinValue(GPIO_PORTB, GPIO_PIN0) == 1) {
            LED_On(GPIO_PORTD, GPIO_PIN0);
            GPIO_setPinValue(GPIO_PORTE, GPIO_PIN0, GPIO_HIGH);
        } else {
            GPIO_setPinValue(GPIO_PORTD, GPIO_PIN0, GPIO_LOW);
            GPIO_setPinValue(GPIO_PORTE, GPIO_PIN0, GPIO_LOW);
        }
        dummy_delay(1000);
    }
}