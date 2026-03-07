#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/Timer/Timer_interface.h"



void App_ToggleBlue(void) {
    LED_Toggle(LED0_PORT, LED0_PIN);
}

void App_ToggleGreen(void) {
    LED_Toggle(LED1_PORT, LED1_PIN);
}

void App_ToggleRed(void) {
    LED_Toggle(LED2_PORT, LED2_PIN);
}


void main() {

    LED_Init(LED0_PORT, LED0_PIN);
    LED_Init(LED1_PORT, LED1_PIN);
    LED_Init(LED2_PORT, LED2_PIN);


    Timer_SetCallback(0, App_ToggleBlue);
    Timer_SetCallback(1, App_ToggleGreen);
    Timer_SetCallback(2, App_ToggleRed);


    Timer_Init();

    while(1) {

    }
}