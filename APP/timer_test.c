#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"

void TIMER0_AppAction(void) {
    static u16 count = 0;
    count++;
    if (count == 31) { 
        LED_Toggle(GPIO_PORTB, GPIO_PIN1);
        count = 0;
        TIMER0_voidSetPreload(124);
    }
}

void TIMER0_Test(void) {
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    TIMER0_voidSetCallback(TIMER0_AppAction);
    TIMER0_voidInit();
    TIMER0_voidSetPreload(124);
}