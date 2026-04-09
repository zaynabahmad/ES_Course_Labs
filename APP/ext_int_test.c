#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../HAL/LED/LED_interface.h"


void Button_Pressed_Callback(void) {
    LED_Toggle(GPIO_PORTC, GPIO_PIN0);
}

void ext_int_test_run(void) {

    LED_Init(GPIO_PORTC, GPIO_PIN0);


    EXT_INT_Init();


    EXT_INT_SetCallback(Button_Pressed_Callback);


    EXT_INT_SetEdge(falling_edge);


    EXT_INT_Enable();

    while(1) {

    }
}