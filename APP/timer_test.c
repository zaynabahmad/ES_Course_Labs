#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TMR0/TMR0_interface.h"
#include "../HAL/LED/LED_interface.h"

/* Software counters to keep track of the interrupts */
static volatile u8 G_u8Counter1Sec = 0;
static volatile u8 G_u8Counter2Sec = 0;

/* This function is called by the hardware every 20ms */
static void APP_vidTimer0Dispatcher(void) {
    /* Increment both counters */
    G_u8Counter1Sec++;
    G_u8Counter2Sec++;

    /* Check if 1 Second has passed (50 interrupts of 20ms) */
    if (G_u8Counter1Sec >= 50) {
        G_u8Counter1Sec = 0; // Reset counter
        LED_Toggle(GPIO_PORTB, GPIO_PIN2); // Toggle LED2
    }

    /* Check if 2 Seconds have passed (100 interrupts of 20ms) */
    if (G_u8Counter2Sec >= 100) {
        G_u8Counter2Sec = 0; // Reset counter
        LED_Toggle(GPIO_PORTB, GPIO_PIN1); // Toggle LED1
    }
}

/* The main Timer0 Test Function to be called from main.c */
void APP_vidTimer0Test(void) {
    /* 1. Initialize LEDs */
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);

    /* 2. Configure Timer0 */
    TMR0_SetCallBack(&APP_vidTimer0Dispatcher);
    TMR0_Init(); // This also enables Global Interrupts based on your driver
    TMR0_SetPreloadValue(100);

    /* 3. Start the Timer (Enables TMR0IE) */
    TMR0_Start();

    /* 4. Super Loop */
    while(1) {
        /* The CPU is completely free!
         * It can read sensors, send UART messages, or go to sleep here.
         * The LEDs will toggle automatically in the background.
         */
    }
}