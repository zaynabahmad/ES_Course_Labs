#include "../MCAL/PWM/PWM_interface.h"

void PWM_test(void) {
    u8 i;
    PWM_voidInit();

    while(1) {
        /* Brighten LED on RC2 */
        for(i=0; i<=100; i++) {
            PWM_voidSetDutyCycle(i);
            Delay_ms(20);
        }
    }
}