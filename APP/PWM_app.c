#include "../SERVICES/Std_Types.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/EXT_INT/EXT_INT0.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../HAL/LED/LED.h"
#include "../HAL/Switch/Switch.h"
#include "../HAL/MOTOR/Motor.h"

volatile u8 button_pressed = 0;  // Flag for button press from interrupt

void delay(void){
    unsigned int i;
    for ( i = 0; i < 50000; i++);
}

void interrupt_logic(void){
    button_pressed = 1;  
}

void main() {

    SWITCH_Init(GPIO_PORTB, GPIO_PIN0); // Switch 1
    
    /* Initialize Motor PWM Control */
    Motor_Init();
    
    EXT_INT0_Init();
    EXT_INT0_SetEdge(INT0_FALLING_EDGE);
    EXT_INT0_SetCallback(interrupt_logic);
    EXT_INT0_Enable();
    
    while(1){
        if(button_pressed) {
            button_pressed = 0;  // Clear flag
            Motor_SpeedUp();     // Increase motor speed to next level
        }
    }

}
void interrupt() {
    // MikroC sends all hardware interrupts to this exact function.
    // We pass the control over to your MCAL handler.
    EXT_INT0_ISR_Handler(); 
}