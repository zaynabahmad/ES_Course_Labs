#include "../MCAL Layer/EXT_INT0.h"
#include "../Services Layer/Std_Types.h"
#include "../HAL Layer/SWITCH.h"

#define PORTD_REG (*((volatile uint8*)0x08))
#define TRISD_REG (*((volatile uint8*)0x88))


void App_ToggleLED(void) {
  PORTD_REG ^= (1 << 0);
}

void main() {

    TRISD_REG &= ~(1 << 0);
    PORTD_REG &= ~(1 << 0);


    SWITCH_Init(0);

    EXT_INT0_Init();
    EXT_INT0_SetEdge(RISING_EDGE);

    EXT_INT0_SetCallback(App_ToggleLED);

    EXT_INT0_Enable();

    while(1) {

    }

}
