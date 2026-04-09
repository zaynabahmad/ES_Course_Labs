
#include "../pic_config.h"
#include "pwm.h"

void main() {
    ADCON1 = 0x06;
    TRISC2_bit = 0;    // RC2/CCP1 as output

    PWM1_Init(2500);   // Initialize PWM at 2500 Hz

    uint8 duty = 0;
    int8  step = 5;

    PWM1_Start();

    while (1) {
        PWM1_Set_Duty(duty);   // 0–255 (not percent — scale accordingly)
        Delay_ms(50);
        if (duty == 0)   step =  5;
        if (duty >= 250) step = -5;
        duty += step;
    }
}
