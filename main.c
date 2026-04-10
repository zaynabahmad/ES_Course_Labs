/*
 * Project: OmarAli_202301065_Drivers
 * Author: Omar Ali
 * ID: 202301065
 * For: MikroC PRO Compiler
 */

#include "pic_config.h"
#include "gpio.h"

// NO function declarations here - just put the code directly

void main() {
    // Simple test: Blink LED on RB0
    // This proves your setup works

    GPIO_SetPinDirection(PORTB_ID, PIN0, OUTPUT);  // RB0 as output

    while(1) {
        GPIO_WritePin(PORTB_ID, PIN0, HIGH);   // LED ON
        Delay_ms(500);                          // Wait 500ms
        GPIO_WritePin(PORTB_ID, PIN0, LOW);    // LED OFF
        Delay_ms(500);                          // Wait 500ms
    }
}

// If you want to test button, REPLACE the above with this:
/*
void main() {
    GPIO_SetPinDirection(PORTB_ID, PIN0, OUTPUT);  // LED on RB0
    GPIO_SetPinDirection(PORTB_ID, PIN1, INPUT);   // Button on RB1

    while(1) {
        if(GPIO_ReadPin(PORTB_ID, PIN1) == 1) {
            GPIO_WritePin(PORTB_ID, PIN0, HIGH);
        } else {
            GPIO_WritePin(PORTB_ID, PIN0, LOW);
        }
        Delay_ms(50);
    }
}
*/