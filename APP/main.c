#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"

#define MOTOR_PORT GPIO_PORTC
#define MOTOR_PIN1 GPIO_PIN0
#define MOTOR_PIN2 GPIO_PIN2

#define LED_PORT GPIO_PORTC
#define LED_PIN GPIO_PIN1

// u8 USART_data = 0;
void Bluetooth_UART_Callback(u8 UART_data)
{
    // UART_Write(UART_data);
    if (UART_data == 'f') // forward
    {
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN1, GPIO_HIGH);
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN2, GPIO_LOW);
        GPIO_SetPinValue(LED_PORT, LED_PIN, GPIO_HIGH);
    }
    else if (UART_data == 's') // stop
    {
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN1, GPIO_LOW);
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN2, GPIO_LOW);
        GPIO_SetPinValue(LED_PORT, LED_PIN, GPIO_LOW);
    }
}

int main(void)
{
    // Initialize GPIOs
    GPIO_Init();
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN1, GPIO_OUTPUT);
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN2, GPIO_OUTPUT);
    GPIO_SetPinDirection(LED_PORT, LED_PIN, GPIO_OUTPUT);

    // Initialize UART
    UART_RX_Init();
    UART_TX_Init();
    // UART_Write('A');  // write  A  to the  Virtual Terminal

    // Set UART callback
    UART_SetCallback(Bluetooth_UART_Callback);
/* Include HAL layer */
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH.h"

/* Include MCAL layer */
#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/EXT_INT/ext_int0.h"

/* Define our hardware pins for readability */
#define LED_PORT 2       /* PORTC */
#define TIMER_LED_PIN 0  /* LED toggled by Timer0 */
#define BUTTON_LED_PIN 1 /* LED toggled by External Interrupt */
#define SWITCH_PIN 0     /* RB0 */

    /* =====================================================================
     * EXTERNAL ISR DECLARATIONS
     * We declare these here so main() knows they exist in your MCAL files.
     * ===================================================================== */
    extern void TIMER0_ISR(void);
    extern void EXT_INT0_ISR(void);

    /* =====================================================================
     * CALLBACK FUNCTIONS (Application Logic)
     * ===================================================================== */
    void App_Timer_Action(void)
    {
        LED_Toggle(LED_PORT, TIMER_LED_PIN);
    }

    void App_Button_Action(void)
    {
        /* Toggles immediately when the button is pressed via EXT_INT0 */
        LED_Toggle(LED_PORT, BUTTON_LED_PIN);
    }

    /* =====================================================================
     * MASTER INTERRUPT SERVICE ROUTINE
     * This is the ONLY 'interrupt' function allowed in the entire project!
     * ===================================================================== */
    void interrupt(void)
    {
        /* 1. Check and handle Timer0 Interrupts */
        TIMER0_ISR();

        /* 2. Check and handle External Button Interrupts */
        EXT_INT0_ISR();
    }

    /* =====================================================================
     * MAIN PROGRAM
     * ===================================================================== */
    void main(void)
    {
        /* 1. Initialize HAL Components */
        LED_Init(LED_PORT, TIMER_LED_PIN);
        LED_Init(LED_PORT, BUTTON_LED_PIN);
        SWITCH_Init(SWITCH_PIN);

        /* 2. Initialize and Configure MCAL: TIMER0 */
        TIMER0_Init();
        TIMER0_SetCallback(App_Timer_Action);
        TIMER0_EnableInterrupt();

        /* 3. Initialize and Configure MCAL: EXT_INT0 */
        EXT_INT0_Init();
        EXT_INT0_SetEdge(EXT_INT0_FALLING_EDGE);
        EXT_INT0_SetCallback(App_Button_Action);
        EXT_INT0_Enable();

        /* 4. Infinite Loop */
        while (1)
        {
            // main loop can be empty because interrupts handle everything
            /* The main loop does absolutely nothing!
             * The CPU rests while the hardware timers and external pins
             * handle all the timing and user input in the background.
             */
        }

        return 0;
    }
