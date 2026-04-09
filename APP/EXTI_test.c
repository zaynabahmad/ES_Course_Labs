#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"

/* Callback function to be executed inside the ISR */
static void ToggleLED(void) {
    LED_Toggle(GPIO_PORTB, GPIO_PIN1);
}

/* The main EXTI Test Function to be called from main.c */
void APP_vidExtiTest(void) {
    /* 1. Initialize Hardware */
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    SWITCH_Init(GPIO_PORTB, GPIO_PIN0);

    /* 2. Register the callback using the EXACT name from your EXTI.c */
    EXTI_SetCallBack(&ToggleLED);

    /* Initialize EXTI (Note: Your EXTI_Init already enables GIE inside it!) */
    EXTI_Init();

    /* Just to be safe, using your exact Global Interrupt function name */
    EXTI_GlobalInterruptEnable();

    /* 3. Super Loop */
    while(1) {
        /* CPU does nothing here.
         * The LED only toggles when the switch on RB0 is pressed
         * and the hardware interrupt fires!
         */
    }
}