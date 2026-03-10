#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "EXT_INT0_interface.h"
#include "SWITCH_interface.h"
#include "LED_interface.h"


#define APP_LED_PORT  GPIO_PORTD
#define APP_LED_PIN   GPIO_PIN0

void App_ToggleLED_ISR(void) {
    
    Delay_ms(30);

 
    LED_Toggle(APP_LED_PORT, APP_LED_PIN);
}

void main() {
 
    LED_Init(APP_LED_PORT, APP_LED_PIN);

   
    SWITCH_Init(GPIO_PIN0);

    EXT_INT0_Init();

   
    EXT_INT0_SetCallback(App_ToggleLED_ISR);

   
    EXT_INT0_Enable();


    while (1) {

    }
}