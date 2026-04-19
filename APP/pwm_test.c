#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void PWM_Test_voidInit(void) {
    PWM_voidInit();
}

void PWM_Test_voidRun(void) {
    u8 i;
    /* Fade In */
    for(i=0; i<=100; i++) {
        PWM_voidSetDutyCycle(i);
        Delay_ms(20);
    }
    /* Fade Out */
    for(i=100; i>0; i--) {
        PWM_voidSetDutyCycle(i);
        Delay_ms(20);
    }
}