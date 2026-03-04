#include "../SERVICES/STD_TYPES.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"

#define MAX_SAMPLES 50

/* Use volatile for variables modified inside ISR and used in Main */
volatile u8 Global_State = 0; /* 0: Idle, 1: Record, 2: Playback */
u8 sequence[MAX_SAMPLES];     /* Sequence doesn't need to be volatile */

/* Callback function that will be called by the EXTI Driver */
void MyButtonISR(void)
{
    if(Global_State == 0)
    {
        Global_State = 1; // Start recording
    }
}

void main()
{
    u8 sample_index = 0;
    unsigned int blink_counter = 0;
    unsigned int sample_counter = 0;

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

    while(1)
    {
        /* 10ms base tick */
        Delay_ms(10);

        /* --- 1. Normal LED Blinking Logic --- */
        blink_counter++;
        if(blink_counter >= 50) /* 50 * 10ms = 500ms */
        {
            LED_Toggle(GPIO_PORTB, GPIO_PIN2);
            blink_counter = 0;
        }

        /* --- 2. Sequence Record & Playback Logic --- */
        if(Global_State == 1) /* RECORDING SEQUENCE */
        {
            sample_counter++;
            if(sample_counter >= 5) /* Sample every 50ms */
            {
                u8 current_val = GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN0);
                sequence[sample_index] = current_val;

                if(current_val == GPIO_HIGH) LED_On(GPIO_PORTB, GPIO_PIN1);
                else LED_Off(GPIO_PORTB, GPIO_PIN1);

                sample_index++;
                sample_counter = 0;

                if(sample_index >= MAX_SAMPLES)
                {
                    Global_State = 2;
                    sample_index = 0;
                    LED_Off(GPIO_PORTB, GPIO_PIN1);
                    Delay_ms(500); // Visual pause
                }
            }
        }
        else if(Global_State == 2) /* PLAYBACK SEQUENCE */
        {
            sample_counter++;
            if(sample_counter >= 5)
            {
                if(sequence[sample_index] == GPIO_HIGH) LED_On(GPIO_PORTB, GPIO_PIN1);
                else LED_Off(GPIO_PORTB, GPIO_PIN1);

                sample_index++;
                sample_counter = 0;

                if(sample_index >= MAX_SAMPLES)
                {
                    Global_State = 0;
                    LED_Off(GPIO_PORTB, GPIO_PIN1);
                }
            }
        }
    }
}