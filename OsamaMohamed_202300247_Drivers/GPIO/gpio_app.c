#include "../pic_config.h"   
#include "gpio.h"

int main(void) {
    
    ADCON1 = 0x06;  /* All pins digital */

    
    GPIO_setupPinDirection(PORTD_ID, PIN0_ID, PIN_OUTPUT);
    GPIO_writePin(PORTD_ID, PIN0_ID, GPIO_LOW);

    
    GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_INPUT);
    OPTION_REGbits.nRBPU = 0;  /* Enable PORTB weak pull-ups globally */

    while (1) {
        if (GPIO_readPin(PORTB_ID, PIN0_ID) == 0) {
            GPIO_writePin(PORTD_ID, PIN0_ID, GPIO_HIGH); /* LED ON  */
        } else {
            GPIO_writePin(PORTD_ID, PIN0_ID, GPIO_LOW);  /* LED OFF */
        }
    }
    return 0;
}
