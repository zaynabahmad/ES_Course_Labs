#include "../pic_config.h"
#include "timer1.h"
#include "../GPIO/gpio.h"

static volatile uint8 g_tickCount = 0;

void timer1_tick(void) {
    g_tickCount++;
    if (g_tickCount >= 50) {     
        g_tickCount = 0;
        TOGGLE_BIT(PORTD, 0);  
    }
}

void interrupt() {
    if (TMR1IF_bit) {
        TMR1IF_bit = 0;
        TMR1H = 0xF6;
        TMR1L = 0x3C;
        toggle_count++;
        if (toggle_count >= 50) {
            toggle_count = 0;
            TOGGLE_BIT(PORTD, 0);
        }
    }
}

int main(void) {
    ADCON1 = 0x06;   /* All digital */

    GPIO_setupPinDirection(PORTD_ID, PIN0_ID, PIN_OUTPUT);
    GPIO_writePin(PORTD_ID, PIN0_ID, GPIO_LOW);

    Timer1_Config cfg = {
        .prescaler    = TIMER1_PRESCALER_8,
        .preloadValue = 0xF63C,   /* 63036 decimal */
        .enableInt    = TRUE
    };

    Timer1_setCallBack(timer1_tick);
    Timer1_init(&cfg);

    while (1) { /* All work in ISR */ }
    return 0;
}
