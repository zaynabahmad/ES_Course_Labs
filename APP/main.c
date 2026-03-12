#include "../HAL/LED/LED_interface.h"
#include "../HAL/Timer/Timer_Interface.h"
#include "../MCAL/Interrupt Manager/Interrupt_manager.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"

volatile u8 press_count = 0;
volatile u8 is_locked = 0;

void Timer_Callback(void) {
    if (!is_locked) {
        LED_Toggle(GPIO_PORTB, GPIO_PIN1); // LED1 on RB1
    }
}

void SW1_Callback(void) {
    if (!is_locked) {
        LED_Toggle(GPIO_PORTB, GPIO_PIN2); // LED2 on RB2
        press_count++;
        if (press_count >= 5) {
            is_locked = 1;
            LED_Off(GPIO_PORTB, GPIO_PIN1); // Ensure LED1 is OFF
            LED_On(GPIO_PORTB, GPIO_PIN2);  // Lock LED2 ON
            CLR_BIT(INTCON, TMR0IE_BIT);    // Stop Timer0 Interrupts
        }
    }
}

int main(void) {
    GPIO_Init();

    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);

    Timer0_Init(128);
    Timer0_SetDelay(2500, Timer_Callback); // 2.5 seconds

    EXT_INT_Init();
    EXT_INT_SetEdge(falling_edge);
    EXT_INT_SetCallback(SW1_Callback);
    EXT_INT_Enable();

    SET_BIT(INTCON, GIE_BIT);

    while (1) {
        // System is interrupt-driven. Reset button must be connected to MCLR pin.
    }
    return 0;
}