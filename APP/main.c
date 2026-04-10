/*
 * ----------------------- TEST SUMMARY -----------------------------------------
 * Press a number on your UART terminal to run the corresponding driver test:
 * 1. GPIO_test:   Blinks an LED every 500ms to verify Pin Output logic.
 * 2. EXTI_test:   Toggles an LED using the External Interrupt (RB0/INT0) flag.
 * 3. TIMER0_test: Uses Timer0 overflow to toggle an LED at precise intervals.
 * 4. PWM_test:    Fades an LED on RC2 (CCP1) from 0% to 100% duty cycle.
 * 5. ADC_test:    Reads Analog input; turns LED ON if voltage is > 2.5V (512).
 * 6. UART_test:   Sends "UART Ready" and echoes back any received characters.
 * 7. SPI_test:    Transmits a fixed character ('A') via the SPI Master lines.
 * 8. I2C_test:    Sends an I2C Start condition and a dummy Slave Address (0xA0).
 * ------------------------------------------------------------------------------
 */


#include "../SERVICES/std_types.h"
#include "../SERVICES/bit_math.h"

/* Include the UART interface to handle the Menu Selection */
#include "../MCAL/UART/UART_interface.h"

/* Function Prototypes */
void GPIO_test(void);
void EXTI_test(void);
void TIMER0_test(void);
void PWM_test(void);
void ADC_test(void);
void UART_test(void);
void SPI_test(void);
void I2C_test(void);


#pragma config FOSC = HS, WDTE = OFF, PWRTE = ON, BOREN = ON, LVP = OFF, CPD = OFF, WRT = OFF, CP = OFF

void main(void) {
    u8 Local_u8Choice = 0;

    /* Initialize UART for the Interactive Menu */
    UART_voidInit();

    UART_voidSendString("\r\n--- PIC16F877A System Ready ---\r\n");
    UART_voidSendString("Select Test: 1-GPIO, 2-EXTI, 3-TMR0, 4-PWM, 5-ADC, 6-UART, 7-SPI, 8-I2C\r\n");

    while(1) {
        /* Receive the user choice */
        Local_u8Choice = UART_u8ReceiveData();

        UART_voidSendString("\r\nStarting Test Selection...\r\n");

        switch(Local_u8Choice) {
            case '1': GPIO_test();   break;
            case '2': EXTI_test();   break;
            case '3': TIMER0_test(); break;
            case '4': PWM_test();    break;
            case '5': ADC_test();    break;
            case '6': UART_test();   break;
            case '7': SPI_test();    break;
            case '8': I2C_test();    break;
            default:  UART_voidSendString("Invalid input! Please press 1-8.\r\n"); break;
        }
    }
}

/* * TEST INSTRUCTIONS:
 * 1. Use UART at 9600 Baud (RC6=TX, RC7=RX).
 * 2. Press keys 1-8 to run specific driver tests.
 * 3. Reset the MCU to return to the menu and switch tests.
 */