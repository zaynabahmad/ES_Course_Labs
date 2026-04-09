#include "TIMER0_Interface.h"
#include "LED_interface.h"
#include "GPIO_interface.h"

static u16 Overflow_Counter = 0;

void Timer0_Toggle_Callback(void) {
    Overflow_Counter++;

    if (Overflow_Counter >= 30) {
        LED_Toggle(GPIO_PORTC, GPIO_PIN0);
        Overflow_Counter = 0;
    }
}

void timer0_test_run(void) {
    LED_Init(GPIO_PORTC, GPIO_PIN0);

    TIMER0_Init(TIMER0_PRESCALER_256);
    TIMER0_SetCallback(Timer0_Toggle_Callback);
    TIMER0_EnableInterrupt();

    while(1) {
    }
}