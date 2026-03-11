#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "LED_interface.h"
#include "TIMER0_interface.h"
#include "GIE_interface.h"
volatile unsigned int TimerCounter = 0;
static unsigned char Led1_State = 0;
static unsigned char Led2_State = 0;

// This function runs automatically every 1 ms
void App_Timer0_Action(void) {
    TimerCounter++;

    // LED 2: Toggle every 1 second (1000 ms)
    if (TimerCounter % 1000 == 0) {
        if (Led2_State == 0) {
            LED_On(GPIO_PORTB, GPIO_PIN2);
            Led2_State = 1;
        }
        else {
            LED_Off(GPIO_PORTB, GPIO_PIN2);
            Led2_State = 0;
        }
    }

    // LED 1: Toggle every 2 seconds (2000 ms)
    if (TimerCounter % 2000 == 0) {
        if (Led1_State == 0) {
            LED_On(GPIO_PORTB, GPIO_PIN1);
            Led1_State = 1;
        }
        else {
            LED_Off(GPIO_PORTB, GPIO_PIN1);
            Led1_State = 0;
        }
    }
    // Reset counter to prevent overflow
    if (TimerCounter == 2000) {
        TimerCounter = 0;
    }
}

void main() {

    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2); 
    TIMER0_voidInit();
    TIMER0_voidSetPreload(6);                 
    TIMER0_voidSetCallBack(App_Timer0_Action); 
    TIMER0_voidEnableInterrupt();
    GIE_voidEnable();
    while (1) {
        
    }
}