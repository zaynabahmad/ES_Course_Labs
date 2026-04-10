#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

/* --- HAL & MCAL INCLUDES --- */
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/PWM/PWM_Interface.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/I2C/I2C_Interface.h"
#include "../MCAL/USART/USART_Interface.h"

/* --- PIN DEFINITIONS --- */
#define HEARTBEAT_LED_PORT  GPIO_PORTD
#define HEARTBEAT_LED_PIN   GPIO_PIN0

#define ESTOP_LED_PORT      GPIO_PORTD
#define ESTOP_LED_PIN       GPIO_PIN1

#define MOTOR_DIR_PORT      GPIO_PORTC
#define MOTOR_DIR_PIN1      GPIO_PIN0
#define MOTOR_DIR_PIN2      GPIO_PIN1

/* --- GLOBAL FLAGS --- */
volatile u8 Emergency_Stop = 0;
volatile u16 Heartbeat_Ticks = 0;

/* --- INTERRUPT CALLBACKS --- */

/* 1. Timer0: System Heartbeat (Blinks RD0) */
void System_Heartbeat_Callback(void)
{
    Heartbeat_Ticks++;
    if(Heartbeat_Ticks >= 15) // Approx delay at 4MHz
    {
        LED_Toggle(HEARTBEAT_LED_PORT, HEARTBEAT_LED_PIN);
        Heartbeat_Ticks = 0;
    }
}

/* 2. External Interrupt: Emergency Stop Button (RB0) */
void Emergency_Stop_Callback(void)
{
    Emergency_Stop = 1; // Trigger E-Stop flag
    PWM1_SetDutyCycle(0); // Instantly kill motor power
    LED_On(ESTOP_LED_PORT, ESTOP_LED_PIN); // Turn on Red E-Stop LED
    GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_DIR_PIN1, GPIO_LOW);
    GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_DIR_PIN2, GPIO_LOW);
}

/* 3. UART: Bluetooth Remote Control */
void Bluetooth_Command_Callback(u8 command)
{
    if(Emergency_Stop) return; // Ignore commands if in E-Stop

    if(command == 'f') // Forward
    {
        GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_DIR_PIN1, GPIO_HIGH);
        GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_DIR_PIN2, GPIO_LOW);
    }
    else if(command == 'r') // Reverse
    {
        GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_DIR_PIN1, GPIO_LOW);
        GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_DIR_PIN2, GPIO_HIGH);
    }
    else if(command == 's') // Stop
    {
        GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_DIR_PIN1, GPIO_LOW);
        GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_DIR_PIN2, GPIO_LOW);
    }
}

/* --- MAIN APPLICATION --- */
int main(void)
{
    /* =========================================
       PHASE 1: HARDWARE INITIALIZATION
       ========================================= */

    // LEDs & Motor Direction Pins
    LED_Init(HEARTBEAT_LED_PORT, HEARTBEAT_LED_PIN);
    LED_Init(ESTOP_LED_PORT, ESTOP_LED_PIN);
    GPIO_SetPinDirection(MOTOR_DIR_PORT, MOTOR_DIR_PIN1, GPIO_OUTPUT);
    GPIO_SetPinDirection(MOTOR_DIR_PORT, MOTOR_DIR_PIN2, GPIO_OUTPUT);

    // Core Subsystems
    ADC_Init();
    PWM1_Init();

    // UART for Bluetooth
    UART_RX_Init();
    UART_TX_Init();
    UART_SetCallback(Bluetooth_Command_Callback);

    // Timer0 for Heartbeat
    TIMER0_Init();
    TIMER0_SetCallback(System_Heartbeat_Callback);
    TIMER0_EnableInterrupt();

    // EXT_INT for Emergency Stop Button
    EXT_INT_Init();
    EXT_INT_SetEdge(falling_edge);
    EXT_INT_SetCallback(Emergency_Stop_Callback);
    EXT_INT_Enable();

    /* =========================================
       PHASE 2: I2C BOOT SEQUENCE
       ========================================= */
    /* Emulate reading a config byte from an I2C EEPROM on startup */
    I2C_Master_Init(100000);
    I2C_Start();
    I2C_Write(0xA0); // Dummy EEPROM Address
    I2C_Write(0x00); // Dummy Register
    I2C_Write(0xFF); // Dummy Config Data
    I2C_Stop();

    // Give the hardware a moment to settle after releasing I2C
    for(volatile u16 i = 0; i < 5000; i++);

    /* =========================================
       PHASE 3: RUNTIME SPI DASHBOARD MODE
       ========================================= */
    /* Reconfigure MSSP hardware for SPI to send live data to dashboard */
    SPI_MasterInit();

    u16 gas_pedal = 0;
    u8  motor_speed = 0;

    /* Infinite Control Loop */
    while(1)
    {
        if(Emergency_Stop == 0)
        {
            // 1. Read Potentiometer (ADC Channel 0)
            gas_pedal = ADC_Read(ADC_CHANNEL_0);

            // 2. Map 10-bit ADC (0-1023) to 8-bit PWM % (0-100)
            motor_speed = (u8)((gas_pedal * 100) / 1023);

            // 3. Update Motor PWM
            PWM1_SetDutyCycle(motor_speed);

            // 4. Send current speed to the SPI Dashboard Display
            SPI_Transfer(motor_speed);

            // Short delay to avoid flooding SPI
            for(volatile u16 i = 0; i < 10000; i++);
        }
        else
        {
            // If Emergency Stop is active, send Error Code (0xFF) via SPI
            SPI_Transfer(0xFF);
            for(volatile u16 i = 0; i < 30000; i++);
        }
    }

    return 0;
}
