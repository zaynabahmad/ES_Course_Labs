#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

/* HAL Drivers */
#include "../HAL/LED/LED_interface.h"
#include "../HAL/Switch/Switch_interface.h"

/* MCAL Drivers */
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "../MCAL/TIMER_0/Timer0_interface.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/I2C/I2C_interface.h"

/* --- Prototypes for Test Functions --- */
void Test_GPIO_LED_Switch(void);
void Test_External_Interrupt(void);
void Test_Timer0_OneSecond(void);
void Test_ADC_UART(void);
void Test_PWM_Signal(void);
void Test_SPI_Communication(void);
void Test_I2C_Communication(void);

/* --- Global Flags for ISR Testing --- */
volatile u8 g_EXT_INT_Flag = 0;
volatile u32 g_Timer0_Counter = 0;

/* Callback for External Interrupt */
void My_EXT_INT_Handler(void) {
    g_EXT_INT_Flag = 1;
}

/* Callback for Timer0 */
void My_Timer0_Handler(void) {
    g_Timer0_Counter++;
}

/* ==========================================================================
   MAIN FUNCTION
   ========================================================================== */
void main() {
    /* 1. Global GPIO Initialization (Sets all ports to default) */
    GPIO_Init();
    
    /* 2. UNCOMMENT THE ONE YOU WANT TO TEST RIGHT NOW */
    
    // Test_GPIO_LED_Switch();
    // Test_External_Interrupt();
    // Test_Timer0_OneSecond();
    // Test_ADC_UART();
    // Test_PWM_Signal();
    // Test_SPI_Communication();
    // Test_I2C_Communication();

    while(1) {
        /* If no test is selected, the CPU just waits here */
    }
}

/* ==========================================================================
   TEST IMPLEMENTATIONS
   ========================================================================== */

/* Task: Press Switch on RB1 to turn on LED on RA0 */
void Test_GPIO_LED_Switch(void) {
    /* Change PIN0 to PIN1 because D1 is now on RA1 (Pin 3) */
    LED_Init(GPIO_PORTA, GPIO_PIN1, LED_ACTIVE_HIGH);
    SWITCH_Init(GPIO_PORTB, GPIO_PIN1);

    while(1) {
        /* When button on RB1 is pressed, turn on LED on RA1 */
        if (SWITCH_GetStateDebounced(GPIO_PORTB, GPIO_PIN1, SWITCH_PULL_DOWN) == SWITCH_PRESSED) {
            LED_On(GPIO_PORTA, GPIO_PIN1, LED_ACTIVE_HIGH);
        } else {
            LED_Off(GPIO_PORTA, GPIO_PIN1, LED_ACTIVE_HIGH);
        }
    }
}

/* Task: Press button on RB0 (INT0) to toggle LED on RA1 using ISR */
void Test_External_Interrupt(void) {
    LED_Init(GPIO_PORTA, GPIO_PIN1, LED_ACTIVE_HIGH);
    EXT_INT_Init();
    EXT_INT_SetEdge(rising_edge);
    EXT_INT_SetCallback(My_EXT_INT_Handler);
    EXT_INT_Enable();
    
    while(1) {
        if (g_EXT_INT_Flag == 1) {
            LED_Toggle(GPIO_PORTA, GPIO_PIN1);
            g_EXT_INT_Flag = 0; // Reset flag
        }
    }
}

/* Task: Use Timer0 to toggle LED on RA2 every 1 second */
void Test_Timer0_OneSecond(void) {
    LED_Init(GPIO_PORTA, GPIO_PIN2, LED_ACTIVE_HIGH);
    TIMER0_Init(); // Configured in Timer0_config.h
    TIMER0_SetCallback(My_Timer0_Handler);
    TIMER0_EnableInterrupt();
    
    while(1) {
        /* If using 4MHz and Prescaler 8, 1 second is approx 488 overflows */
        if (g_Timer0_Counter >= 488) {
            LED_Toggle(GPIO_PORTA, GPIO_PIN2);
            g_Timer0_Counter = 0;
        }
    }
}

/* Task: Read Potentiometer on AN0 and show value on Virtual Terminal */
void Test_ADC_UART(void) {
    u16 adc_val;
    ADC_Init();
    UART_TX_Init();
    
    UART_SendString("--- ADC Monitoring ---\r\n");
    
    while(1) {
        adc_val = ADC_Read(ADC_CHANNEL_AN0);
        UART_SendString("Value: ");
        UART_SendNumber(adc_val);
        UART_SendString("\r\n");
        Delay_ms(500);
    }
}

/* Task: Generate 1kHz PWM on RC2 (CCP1) and vary duty cycle */
void Test_PWM_Signal(void) {
    u8 duty;
    PWM_Init(PWM_CHANNEL_1);
    PWM_Start();
    
    while(1) {
        /* Gradually increase brightness */
        for(duty = 0; duty <= 100; duty += 10) {
            PWM_SetDutyCycle(PWM_CHANNEL_1, duty);
            Delay_ms(200);
        }
    }
}

/* Task: Send a block of data over SPI and see it on SPI Debugger */
void Test_SPI_Communication(void) {
    u8 data_to_send[5] = {0x10, 0x20, 0x30, 0x40, 0x50};
    SPI_Init();
    
    while(1) {
        SPI_TransmitBlock(data_to_send, 5);
        Delay_ms(1000);
    }
}

/* Task: Send I2C Start, Address, and Data to see on I2C Debugger */
void Test_I2C_Communication(void) {
    u8 sensor_data[2] = {0xAA, 0xBB};
    I2C_Init();
    
    while(1) {
        /* Write two bytes to slave address 0x50 */
        I2C_WriteBlock(0x50, sensor_data, 2);
        Delay_ms(2000);
    }
}