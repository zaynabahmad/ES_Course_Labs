#include "../HAL/PWM Control/PWM.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/Timer/Timer_Interface.h"
#include "../HAL/Switch/Switch_interface.h"
#include "../MCAL/Interrupt Manager/Interrupt_manager.h"




volatile u8 g_UpdatePWM_Flag = 0; // Global flag
volatile u8 g_SpeedStep = 0;      // Global step counter

void External_INT_ISR(void) {
    g_SpeedStep++;
    if(g_SpeedStep > 3) g_SpeedStep = 0;

    g_UpdatePWM_Flag = 1; // Just set a flag and leave!
}

int main(void) {
    /* Initialize Hardware */
    LED_Init(GPIO_PORTC, GPIO_PIN2); // RC2 is usually the PWM output
    SWITCH_Init(GPIO_PORTB, GPIO_PIN1);
    // Initialize External Interrupt (RB0/INT)
    // Assuming your Interrupt_manager has an initialization function:
    EXT_INT_Init();

    EXT_INT_SetCallback(External_INT_ISR); // Link the ISR function
    EXT_INT_Enable();

    /* Start with 25% Duty Cycle */ 
    PWM_voidInit();
    PWM_Set_Conditions(25, 500, 16);
    PWM_Start();



    while(1) {
        if(g_UpdatePWM_Flag == 1) {
            // Call the function safely here
            switch(g_SpeedStep) {
                case 0: PWM_Set_Conditions(25,500,16); break;
                case 1: PWM_Set_Conditions(50,500,16); break;
                case 2: PWM_Set_Conditions(75,500,16); break;
                case 3: PWM_Set_Conditions(100,500,16); break;
            }
            g_UpdatePWM_Flag = 0; // Reset the flag
        }

    }
    return 0;
}
