#include "../../APP/app_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "../../MCAL/PWM/PWM_interface.h"

void APP_ADC_Test(void) {
    uint16 adc_val;
    uint8 duty;
    
    ADC_voidInit();
    PWM_voidInit();
    
    while(1) {
        adc_val = ADC_u16ReadChannel(0);
        duty = (adc_val * 100) / 1023;
        PWM_voidSetDutyCycle(duty);
    }
}