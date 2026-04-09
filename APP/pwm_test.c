#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "../MCAL/PWM/PWM_interface.h"

/* Global state for speed levels */
static u8 Speed_Level = 0;

void PWM_AppAction(void) {
    /* Change speed level each time RB0 button is pressed */
    Speed_Level++;
    if (Speed_Level > 3) Speed_Level = 0;

    switch (Speed_Level) {
    case 0: PWM_voidSetDutyCycle(25);  break;
    case 1: PWM_voidSetDutyCycle(50);  break;
    case 2: PWM_voidSetDutyCycle(75);  break;
    case 3: PWM_voidSetDutyCycle(100); break;
    }
}

void PWM_Test(void) {
    /* Init PWM and Interrupt */
    PWM_voidInit();
    PWM_voidSetDutyCycle(25); 

    EXT_INT0_Init();
    EXT_INT0_SetCallback(PWM_AppAction);
    EXT_INT0_Enable();
}