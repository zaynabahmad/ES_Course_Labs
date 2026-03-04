#include "../MCAL Layer/EXT_INT0.h"
#include "../Services Layer/Std_Types.h"
#include "../HAL Layer/SWITCH.h"


void App_ToggleLED(void) {
    PORTD.F0 = ~PORTD.F0;
}

void main() {

    TRISD.F0 = 0;
    PORTD.F0 = 0;


    SWITCH_Init(0);

    EXT_INT0_Init();
    EXT_INT0_SetEdge(RISING_EDGE);

    EXT_INT0_SetCallback(App_ToggleLED);

    EXT_INT0_Enable();

    while(1) {

    }
}