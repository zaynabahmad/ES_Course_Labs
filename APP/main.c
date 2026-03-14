#include "../HAL/LED/LED_interface.h"
#include "../HAL/Timer/Timer_Interface.h"
#include "../HAL/Switch/Switch_interface.h"
#include "../MCAL/Interrupt Manager/Interrupt_manager.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"

// Global variable to alternate LED toggling
volatile u8 ext_int_counter = 0;
volatile u8 led1_active = 1; // Start with LED1 active
// Callback function for Timer0 interrupt
void tmr_int_logic() {
    if(led1_active){
        LED_Toggle(GPIO_PORTB,GPIO_PIN1);
    }
}
void ext_int_logic() {
    LED_Toggle(GPIO_PORTB,GPIO_PIN1);
    ext_int_counter++;
    if(ext_int_counter==4){
        LED_Toggle(GPIO_PORTA,GPIO_PIN4);
        led1_active=0;
    }
}

int main(void) {
    // Initialize LEDs

    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTA, GPIO_PIN4);
    SWITCH_Init(GPIO_PORTB, GPIO_PIN0);
    SWITCH_Init(GPIO_PORTB, GPIO_PIN4);

    EXT_INT_Init();
    EXT_INT_Enable();
    EXT_INT_SetCallback(ext_int_logic);

    // Initialize Timer0 with prescaler 128
    Timer0_Init(128);

    // Set Timer0 delay to 2000ms and register callback
    Timer0_SetDelay(2000, tmr_int_logic);

    // Enable global interrupts after Timer0 is configured
    SET_BIT(INTCON, GIE_BIT);

    while (1) {
        if(SWITCH_Read(GPIO_PORTB, GPIO_PIN4)){
            Timer0_reset();
        }
        
    }

    return 0;
}
