#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/TIMER1/TIMER1_interface.h"

#define MAX_SAMPLES 50

/* Local Register Definitions used only for MikroC's global interrupt routing */
#define INTCON_REG  (*((volatile u8*)0x0B))
#define PIR1_REG    (*((volatile u8*)0x0C))

/* --- Global Variables --- */
volatile u8 Global_State = 0; /* 0: Idle, 1: Record, 2: Playback */
u8 sequence[MAX_SAMPLES];

/* Flags set by Timer ISRs */
volatile u8 flag_1sec = 0;
volatile u8 flag_200ms = 0;

/* --- Callbacks --- */

/* Callback function that will be called by the EXTI Driver */
void MyButtonISR(void)
{
    if(Global_State == 0)
    {
        Global_State = 1; // Start recording
    }
}

/* Timer0 Callback - Fires every 1 Second */
void Timer0_Action(void)
{
    flag_1sec = 1;
}

/* Timer1 Callback - Fires every 200 ms */
void Timer1_Action(void)
{
    flag_200ms = 1;
}

/* --- MikroC Global Interrupt Router --- */
void interrupt()
{
    /* EXTI Interrupt Check (RB0) */
    if (GET_BIT(INTCON_REG, 1) == 1) { // INTF
        EXTI_ISR_Handler();
        CLR_BIT(INTCON_REG, 1); // Clear Flag
    }

    /* Timer0 Interrupt Check */
    if (GET_BIT(INTCON_REG, 2) == 1) { // TMR0IF
        TIMER0_ISR_Handler();
        CLR_BIT(INTCON_REG, 2); // Clear Flag
    }

    /* Timer1 Interrupt Check */
    if (GET_BIT(PIR1_REG, 0) == 1) {   // TMR1IF
        TIMER1_ISR_Handler();
        CLR_BIT(PIR1_REG, 0);   // Clear Flag
    }
}

/* --- Main Program --- */
void main()
{
    u8 sample_index = 0;

    /* Initialize Peripherals */
    GPIO_Init();

    /* LED 1: Standard continuous blink (PIN2) */
    LED_Init(GPIO_PORTB, GPIO_PIN2);

    /* LED 2: Sequence visualizer (PIN1) */
    LED_Init(GPIO_PORTB, GPIO_PIN1);

    /* Configure RB0 as Input for the Button/Interrupt */
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);

    /* Configure External Interrupt on RB0 */
    EXTI_Int0SetEdge(EXTI_RISING_EDGE);
    EXTI_Int0SetCallBack(MyButtonISR);
    EXTI_Int0Init();

    /* Configure Timer0 (1 Second) */
    TIMER0_SetCallBack(Timer0_Action);
    TIMER0_Init();

    /* Configure Timer1 (200 Milliseconds) */
    TIMER1_SetCallBack(Timer1_Action);
    TIMER1_Init();

    while(1)
    {
        /* --- 1. Normal LED Blinking Logic (Driven by Timer0) --- */
        if(flag_1sec == 1)
        {
            flag_1sec = 0;
            LED_Toggle(GPIO_PORTB, GPIO_PIN2);
        }

        /* --- 2. Sequence Record & Playback Logic (Driven by Timer1) --- */
        if(flag_200ms == 1)
        {
            flag_200ms = 0;

            if(Global_State == 1) /* RECORDING SEQUENCE */
            {
                u8 current_val = GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN0);
                sequence[sample_index] = current_val;

                if(current_val == GPIO_HIGH) LED_On(GPIO_PORTB, GPIO_PIN1);
                else LED_Off(GPIO_PORTB, GPIO_PIN1);

                sample_index++;

                if(sample_index >= MAX_SAMPLES)
                {
                    Global_State = 2;
                    sample_index = 0;
                    LED_Off(GPIO_PORTB, GPIO_PIN1);
                    Delay_ms(500); // Visual pause before playback
                }
            }
            else if(Global_State == 2) /* PLAYBACK SEQUENCE */
            {
                if(sequence[sample_index] == GPIO_HIGH) LED_On(GPIO_PORTB, GPIO_PIN1);
                else LED_Off(GPIO_PORTB, GPIO_PIN1);

                sample_index++;

                if(sample_index >= MAX_SAMPLES)
                {
                    Global_State = 0;
                    sample_index = 0;
                    LED_Off(GPIO_PORTB, GPIO_PIN1);
                }
            }
        }
    }
}
