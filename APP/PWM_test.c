#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/PWM/PWM_config.h"

static u8 G_u8DutyIndex = 0;
static u8 G_u8Levels[] = {25, 50, 75, 100};
/* This flag tells the main loop that a button was pressed */
static volatile u8 G_u8UpdateFlag = 0;

/* Callback function: Short and fast */
void APP_vidChangeMotorSpeed(void) {
    /* Just set the flag and leave the ISR as fast as possible */
    G_u8UpdateFlag = 1;
}

void APP_vidPwmTest(void) {
    /* 1. Hardware Pin Setup */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN2, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);

    /* 2. Setup the External Interrupt */
    EXTI_SetCallBack(&APP_vidChangeMotorSpeed);
    EXTI_Init();

    /* 3. Initialize PWM */
    PWM1_Init(PWM_PR2_VALUE);

    /* 4. Set Initial Speed */
    PWM1_SetDutyCycle(G_u8Levels[G_u8DutyIndex]);

    while(1) {
        /* Check if the ISR set the flag */
        if (G_u8UpdateFlag == 1) {
            /* Clear the flag */
            G_u8UpdateFlag = 0;

            /* Update the index */
            G_u8DutyIndex = (G_u8DutyIndex + 1) % 4;


            PWM1_SetDutyCycle(G_u8Levels[G_u8DutyIndex]);
        }
    }
}