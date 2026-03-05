#include "../SERVICES/Std_Types.h"             
#include "../MCAL/EXT_INT/EXT_INT0.h"         
#include "../HAL/LED/LED.h"           
#include "../HAL/Switch/Switch.h"     

void App_InterruptLogic(void) {
    Delay_ms(30);
    if (SWITCH_Read(0) == LOW) { 
        LED_Toggle(2); 
    }
}

void main() {
    LED_Init(0); 
    LED_Init(1); 
    LED_Init(2);
    
    SWITCH_Init(0); // Added to init the RB0 pin properly
    SWITCH_Init(1); 
    SWITCH_Init(2); 
    
    EXT_INT0_Init();
    EXT_INT0_SetEdge(INT0_FALLING_EDGE); 
    EXT_INT0_SetCallback(App_InterruptLogic);
    
    // EXT_INT0_Enable(); 

    while(1) {
        if (SWITCH_Read(1) == LOW) {
            LED_On(0);
            Delay_ms(1); 
            LED_On(1);

            Delay_ms(200); 

            LED_Off(0);
            Delay_ms(1); 
            LED_Off(1);

            Delay_ms(200); 
        }
        else if (SWITCH_Read(2) == LOW) {
            LED_On(0);
            Delay_ms(1); 
            LED_On(1);

            Delay_ms(500); 

            LED_Off(0);
            Delay_ms(1); 
            LED_Off(1);

            Delay_ms(500); 
        }
        else {
            LED_Off(0);
            LED_Off(1);
        }
    }
}