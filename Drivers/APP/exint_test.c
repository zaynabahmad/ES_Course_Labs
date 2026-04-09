#include "../../APP/app_interface.h"
#include "../../MCAL/EXINT/EXINT_interface.h"
#include "../../HAL/LED/LED_interface.h"


static void EXINT_Action(void) {
    static uint8 state = 0;
    state ^= 1;
    if(state) HAL_LED_voidTurnOn(GPIO_PORTB, GPIO_PIN1);
    else HAL_LED_voidTurnOff(GPIO_PORTB, GPIO_PIN1);
}

void APP_EXINT_Test(void) {
    HAL_LED_voidTurnOff(GPIO_PORTB, GPIO_PIN1);
    EXINT_voidSetCallback(EXINT_Action);
    EXINT_voidInit();
    
    while(1) {}  // Wait for interrupt
}