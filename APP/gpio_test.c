#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"

/* Static helper functions so they are only visible inside this test file */
static void delay(void) {
    volatile unsigned int i;
    for(i = 0; i < 50000; i++);
}

static void ShortSeq(void) {
    LED_On(GPIO_PORTB, GPIO_PIN0);
    LED_On(GPIO_PORTB, GPIO_PIN1);
    delay();
    LED_Off(GPIO_PORTB, GPIO_PIN0);
    LED_Off(GPIO_PORTB, GPIO_PIN1);
    delay();
}

static void LongSeq(void) {
    LED_On(GPIO_PORTB, GPIO_PIN0);
    LED_On(GPIO_PORTB, GPIO_PIN1);
    delay();
    delay();
    LED_Off(GPIO_PORTB, GPIO_PIN0);
    LED_Off(GPIO_PORTB, GPIO_PIN1);
    delay();
    delay();
}

/* The main GPIO Test Function to be called from main.c */
void APP_vidGpioTest(void) {
    /* 1. Initialize LEDs */
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    LED_Init(GPIO_PORTB, GPIO_PIN1);

    /* 2. Initialize Switches */
    SWITCH_Init(GPIO_PORTB, GPIO_PIN2);
    SWITCH_Init(GPIO_PORTB, GPIO_PIN3);

    /* 3. Super Loop (Polling) */
    while(1) {
        if (GetSwitchState(GPIO_PORTB, GPIO_PIN2)) {
            ShortSeq();
        }
        else if (GetSwitchState(GPIO_PORTB, GPIO_PIN3)) {
            LongSeq();
        }
        else {
            LED_Off(GPIO_PORTB, GPIO_PIN0);
            LED_Off(GPIO_PORTB, GPIO_PIN1);
        }
    }
}