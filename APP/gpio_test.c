 #include "../MCAL/GPIO/GPIO_interface.h"

void GPIO_Test(void) {
    /* Set Port B Pin 0 as output */
    GPIO_voidSetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_OUTPUT);

    while(1) {
        GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN0, GPIO_HIGH);
        Delay_ms(500);
        GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN0, GPIO_LOW);
        Delay_ms(500);
    }
}