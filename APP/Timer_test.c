#include "../HAL/LED/LED_interface.h"
#include "../HAL/Timer/Timer_Interface.h"
#include "../HAL/Switch/Switch_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "../MCAL/Interrupt Manager/Interrupt_manager.h"
// Sets all PORTA/PORTE pins to Digital I/O
// Without this, RA4 will not toggle


u8 volatile timer0_flag = 0;
// Global variable to alternate LED toggling
volatile u8 ext_int_counter = 0;
volatile u8 led1_active = 1; // Start with LED1 active
// Callback function for Timer0 interrupt
void tmr_int_logic() {
    if(led1_active){
        timer0_flag = 1; // Set flag to indicate timer interrupt occurred
    }
}
static volatile u8 led2_state = 0; // Shadow variable (0=OFF, 1=ON)

void ext_int_logic() {
    if(led1_active) {
        led2_state = !led2_state; // Toggle our memory of the state

        if(led2_state == 1) {
            /* LED ON: Make RA4 "Float" by setting it to 1 */
            *((volatile u8*)0x05) |= (1 << 4);
        } else {
            /* LED OFF: Make RA4 "Short to GND" by setting it to 0 */
            *((volatile u8*)0x05) &= ~(1 << 4);
        }

        ext_int_counter++;
        if(ext_int_counter >= 5) {
            led1_active = 0;
            /* Lock LED ON for 5th click */
            *((volatile u8*)0x05) |= (1 << 4);
        }
    }
}

int TIMER_TEST(void) {
    u8 switch_val;
    *((volatile unsigned char*)0x9F) = 0x06; // Direct address for ADCON1
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
    Timer0_SetDelay(2500, tmr_int_logic);

    // Enable global interrupts after Timer0 is configured
    SET_BIT(INTCON, GIE_BIT);

    while (1) {
    // Add this to your while(1) to test hardware override


          switch_val = SWITCH_Read(GPIO_PORTB, GPIO_PIN4);

          if(switch_val){
                         Timer0_reset();
                         ext_int_counter=0;
                         led1_active=1;
          }
        if(timer0_flag){
                LED_Toggle(GPIO_PORTB, GPIO_PIN1);
                timer0_flag = 0; // Clear flag after handling
        }

    }

    return 0;
}