<<<<<<< Updated upstream
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"


#define MOTOR_PORT GPIO_PORTC
#define MOTOR_PIN1  GPIO_PIN0
#define MOTOR_PIN2  GPIO_PIN2

#define LED_PORT   GPIO_PORTC
#define LED_PIN    GPIO_PIN1

//u8 USART_data = 0;
void Bluetooth_UART_Callback(u8 UART_data)
{
     //UART_Write(UART_data);
    if (UART_data == 'f')  // forward
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
    //UART_Write('A');  // write  A  to the  Virtual Terminal


    // Set UART callback
    UART_SetCallback(Bluetooth_UART_Callback);
=======

#include "SERVICES/STD_TYPES.h"


extern void APP_GPIO_Test(void);
extern void APP_EXT_INT_Test(void);
extern void APP_Timer0_Test(void);
extern void APP_PWM_Test(void);
extern void APP_ADC_Test(void);
extern void APP_UART_Test(void);
extern void APP_SPI_Test(void);
extern void APP_I2C_Test(void);

void main(void) 
{
   
    /* --- Basic I/O & Timers --- */
    // APP_GPIO_Test();
    // APP_EXT_INT_Test();
    // APP_Timer0_Test();
    // APP_PWM_Test();

    /* --- Analog & Communications --- */
    APP_ADC_Test();    
    // APP_UART_Test();
    // APP_SPI_Test();
    // APP_I2C_Test();
>>>>>>> Stashed changes

    while(1) 
    {
<<<<<<< Updated upstream
        // main loop can be empty because interrupts handle everything
=======
       
>>>>>>> Stashed changes
    }

    return 0;
}
