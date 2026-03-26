#include "../SERVICES/Std_Types.h"
#include "../SERVICES/Bit_Math.h"
#include "../MCAL/GIE/GIE.h"
#include "../MCAL/UART/UART.h"
#include "../MCAL/Timer0/Timer0.h"
#include "../HAL/LED/LED.h"
#include "../HAL/SWITCH/BUTTON.h"
#include "../HAL/LM35/LM35.h"
#include "../HAL/MOTOR/MOTOR.h"

/* Global Flag for 1-second task */
volatile u8 g_u8OneSecFlag = 0;

/* Callback function for Timer0 (called every 1 second) */
void App_voidTimerTask(void) {
    g_u8OneSecFlag = 1;
}

void main(void) {
    /* 1. Variables */
    u8 last_button_state = 0;
    u8 current_button = 0;
    f32 temp = 0.0;
    u8 temp_int = 0; // Use integer for smaller code size

    /* 2. Initializations */
    M_ADC_voidInit();
    UART_voidInit();
    M_TIMER0_voidInit();

    H_LED_voidInit(PORTB_ID, PIN1);
    H_LED_voidInit(PORTB_ID, PIN2);
    H_Button_voidInit(PORTB_ID, PIN0);
    H_Button_voidInit(PORTD_ID, PIN0);
    H_Motor_voidInit(PORTC_ID, PIN0, PIN1);

    /* 3. Set Callbacks and Enable Global Interrupts */
    M_TIMER0_voidSetCallBack(App_voidTimerTask);
    M_GIE_voidEnable();

    while(1) {
        // --- Task 1: Switch logic (Direct Control) ---
        if(H_Button_u8GetValue(PORTB_ID, PIN0) == 1) {
            H_LED_voidOn(PORTB_ID, PIN1);
        } else {
            H_LED_voidOff(PORTB_ID, PIN1);
        }

        // --- Task 2: Toggle logic (Edge Detection) ---
        current_button = H_Button_u8GetValue(PORTD_ID, PIN0);
        if(current_button == 1 && last_button_state == 0) {
            H_LED_voidToggle(PORTB_ID, PIN2);
        }
        last_button_state = current_button;

        // --- Task 3: 1-Second Periodic Task (UART & Motor) ---
        if(g_u8OneSecFlag == 1) {
            temp = H_LM35_f32ReadTemp(0);
            temp_int = (u8)temp; // Cast to integer to simplify UART math

            /* Manual Lightweight UART Printing (No Conversions Library needed) */
            UART_voidSendString("Temp: ");
            UART_voidSendData((temp_int / 10) + '0'); // Tens digit
            UART_voidSendData((temp_int % 10) + '0'); // Ones digit
            UART_voidSendString(" C\r\n");

            /* Control Motor Speed based on Temp */
            if(temp_int < 25)      H_Motor_voidSetSpeed(0);
            else if(temp_int < 35) H_Motor_voidSetSpeed(50);
            else                   H_Motor_voidSetSpeed(100);

            g_u8OneSecFlag = 0;
        }
    }
}

/* 4. THE UNIFIED ISR */
void interrupt() {
    if (GET_BIT(*((volatile u8*)0x0B), 2) == 1) {
        static u16 local_u16Counter = 0;
        local_u16Counter++;

        if (local_u16Counter == 1000) {
            if (Timer0_CallBackPtr != 0) { // Changed NULL to 0 for small code
                Timer0_CallBackPtr();
            }
            local_u16Counter = 0;
        }

        *((volatile u8*)0x01) = 6;
        *((volatile u8*)0x0B) &= ~(1 << 2);
    }
}