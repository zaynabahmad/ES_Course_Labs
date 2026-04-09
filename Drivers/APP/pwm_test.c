#include "../../APP/app_interface.h"
#include "../../MCAL/PWM/PWM_interface.h"


void APP_PWM_Test(void) {
    PWM_voidInit();
    uint8 duty = 0;
    
    while(1) {
        PWM_voidSetDutyCycle(duty);
        duty += 10;
        if(duty > 100) duty = 0;
        Delay_ms(100);
    }
}