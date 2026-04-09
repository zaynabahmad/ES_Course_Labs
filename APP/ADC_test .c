#include "../MCAL/ADC/ADC_interface.h"
#include "../HAL/LED/LED_interface.h"

void ADC_test(void) {
    u16 Local_u16Result;

    ADC_voidInit();
    LED_voidInit(LED0);

    while(1) {
        Local_u16Result = ADC_u16ReadChannel(ADC_CH0);

        /* If voltage > ~2.5V  */
        if(Local_u16Result > 512) {
            LED_voidOn(LED0);
        } else {
            LED_voidOff(LED0);
        }
    }
}