#include "../../APP/app_interface.h"
#include "../../MCAL/TIMER0/TIMER0_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void APP_TIMER0_Test(void) {
    GPIO_voidSetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_PIN_OUTPUT);
    TIMER0_voidInit();
    
    while(1) {
        GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN0, STD_HIGH);
        TIMER0_voidSetDelay(1000);
        GPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN0, STD_LOW);
        TIMER0_voidSetDelay(1000);
    }
}