#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/EXTI0/exti0_interface.h"
#include "../HAL/LED/LED_interface.h"

void App_vToggleLogic(void) {
    HLED_vToggle();
}

void main(void) {
    HLED_vInit();
    MEXTI0_vSetCallback(App_vToggleLogic);
    MEXTI0_vInit();

    while(1) {
        // CPU remains idle, waiting for interrupt
    }
}