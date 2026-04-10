// Purpose: Tests PWM by fading LED smoothly on/off
// Connect LED (with resistor) to RC2 pin

#include "pwm.h"
#include "gpio.h"

void PWM_Test(void) {
    uint8 brightness = 0;
    uint8 increasing = 1;

    PWM_Init();
    PWM_Start();

    while(1) {
        PWM_SetDutyCycle(brightness);
        __delay_ms(10);  // Small delay for smooth fading

        // Change brightness
        if(increasing) {
            brightness += 5;
            if(brightness >= 255) {
                brightness = 255;
                increasing = 0;
            }
        } else {
            if(brightness >= 5)
                brightness -= 5;
            else
                brightness = 0;

            if(brightness <= 0) {
                brightness = 0;
                increasing = 1;
            }
        }
    }
}