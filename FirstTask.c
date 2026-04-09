
#include "HAL/LED/LED_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "SERVICES/BIT_MATH.h"
#include "SERVICES/STD_TYPES.h"



#define OPTION_REG   (*(volatile unsigned char*)0x81)

/* --- Function Prototypes --------------------------------------------- */
static void delay_ms(u16 ms);
static void LEDs_Off(void);
static void LEDs_Blink_Short(void);
static void LEDs_Blink_Long(void);

/* --- Main Function --------------------------------------------------- */
void main(void)
{               
    OPTION_REG &= ~(1 << 7);

    GPIO_Init();


    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN1, GPIO_OUTPUT);


    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN2, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN3, GPIO_INPUT);


    GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN2, GPIO_HIGH);
    GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN3, GPIO_HIGH);

    LED_Init(GPIO_PORTB, GPIO_PIN0);
    LED_Init(GPIO_PORTB, GPIO_PIN1);


    LEDs_Off();

    while (1)
    {

        u8 sw1_state = GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN2);
        u8 sw2_state = GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN3);

        if (sw1_state == GPIO_LOW)          // Switch 1 Pressed
        {
            LEDs_Blink_Short();
        }
        else if (sw2_state == GPIO_LOW)     // Switch 2 Pressed
        {
            LEDs_Blink_Long();
        }
        else                                //No Switch Pressed
        {
            LEDs_Off();
        }
    }
}

// --- Helper Functions ------------------------------------------------ 

static void LEDs_Blink_Short(void)
{
    LED_On(GPIO_PORTB, GPIO_PIN0);
    LED_On(GPIO_PORTB, GPIO_PIN1);
    delay_ms(200);

    LED_Off(GPIO_PORTB, GPIO_PIN0);
    LED_Off(GPIO_PORTB, GPIO_PIN1);
    delay_ms(200);
}

static void LEDs_Blink_Long(void)
{
    LED_On(GPIO_PORTB, GPIO_PIN0);
    LED_On(GPIO_PORTB, GPIO_PIN1);
    delay_ms(500);

    LED_Off(GPIO_PORTB, GPIO_PIN0);
    LED_Off(GPIO_PORTB, GPIO_PIN1);
    delay_ms(500);
}

static void LEDs_Off(void)
{
    LED_Off(GPIO_PORTB, GPIO_PIN0);
    LED_Off(GPIO_PORTB, GPIO_PIN1);
}

static void delay_ms(u16 ms)
{
    u16 i, j;
    for (i = 0; i < ms; i++)
    {
        /* ~1ms loop for 8MHz clock */
        for (j = 0; j < 800u; j++)
        {
        }
    }
}