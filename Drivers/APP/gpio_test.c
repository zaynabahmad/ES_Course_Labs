#include "../../APP/app_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void APP_GPIO_Test(void) {
    GPIO_voidSetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_PIN_OUTPUT);
    
    while(1) {
        GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN0, STD_HIGH);
        Delay_ms(500);
        GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN0, STD_LOW);
        Delay_ms(500);
    }
}