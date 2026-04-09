#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/MOTOR/MOTOR_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"

#define RUN_APPLICATION    1
#define RUN_GPIO_TEST      0
#define RUN_TIMER_TEST     0
#define RUN_EXT_INT_TEST   0
#define RUN_UART_TEST      0
#define RUN_PWM_TEST       0
#define RUN_ADC_TEST       0
#define RUN_I2C_TEST       0
#define RUN_SPI_TEST       0

void GPIO_Test(void);
void TIMER_0_Test(void);
void EXT_INT_Test(void);
void UART_Test(void);
void PWM_Test(void);
void ADC_Test(void);
void I2C_Test(void);
void SPI_Test(void);

#define MOTOR_PORT      GPIO_PORTC
#define MOTOR_PIN1      GPIO_PIN0
#define MOTOR_PIN2      GPIO_PIN2
#define MOTOR_PWM_CH    PWM_CHANNEL_1

#define LED_PORT        GPIO_PORTC
#define LED_PIN         GPIO_PIN1

void Bluetooth_Motor_Callback(u8 command)
{
    if(command == 'f' || command == 'F') {
        MOTOR_Forward(100);
        LED_On(LED_PORT, LED_PIN);
        UART_Write('F'); UART_Write('W'); UART_Write('D'); UART_Write('\n');
    }
    else if(command == 'b' || command == 'B') {
        MOTOR_Backward(100);
        LED_On(LED_PORT, LED_PIN);
        UART_Write('B'); UART_Write('K'); UART_Write('W'); UART_Write('\n');
    }
    else if(command == 's' || command == 'S') {
        MOTOR_Stop();
        LED_Off(LED_PORT, LED_PIN);
        UART_Write('S'); UART_Write('T'); UART_Write('O'); UART_Write('P'); UART_Write('\n');
    }
    else if(command == '1') { MOTOR_Forward(25); UART_Write('2'); UART_Write('5'); UART_Write('%'); UART_Write('\n'); }
    else if(command == '2') { MOTOR_Forward(50); UART_Write('5'); UART_Write('0'); UART_Write('%'); UART_Write('\n'); }
    else if(command == '3') { MOTOR_Forward(75); UART_Write('7'); UART_Write('5'); UART_Write('%'); UART_Write('\n'); }
    else if(command == '4') { MOTOR_Forward(100); UART_Write('1'); UART_Write('0'); UART_Write('0'); UART_Write('%'); UART_Write('\n'); }
}

void Manual_Stop_Callback(void)
{
    MOTOR_Stop();
    LED_Off(LED_PORT, LED_PIN);
    UART_Write('E'); UART_Write('M'); UART_Write('E'); UART_Write('R'); UART_Write('G'); UART_Write('\n');
}

void Application_Init(void)
{
    GPIO_Init();
    LED_Init(LED_PORT, LED_PIN);
    LED_Off(LED_PORT, LED_PIN);
    MOTOR_Init(MOTOR_PORT, MOTOR_PIN1, MOTOR_PIN2, MOTOR_PWM_CH);
    MOTOR_Stop();
    UART_RX_Init();
    UART_TX_Init();
    UART_SetCallback(Bluetooth_Motor_Callback);
    SWITCH_Init();
    SWITCH_SetCallback(Manual_Stop_Callback);
    UART_Write('R'); UART_Write('e'); UART_Write('a'); UART_Write('d'); UART_Write('y'); UART_Write('\n');
}

int main(void)
{
    #if RUN_APPLICATION == 1
    Application_Init();
    while(1);
    #endif

    #if RUN_GPIO_TEST == 1
    while(1) GPIO_Test();
    #endif

    #if RUN_TIMER_TEST == 1
    TIMER_0_Test();
    while(1);
    #endif

    #if RUN_EXT_INT_TEST == 1
    EXT_INT_Test();
    while(1);
    #endif

    #if RUN_UART_TEST == 1
    UART_Test();
    while(1);
    #endif

    #if RUN_PWM_TEST == 1
    PWM_Test();
    #endif

    #if RUN_ADC_TEST == 1
    while(1) ADC_Test();
    #endif

    #if RUN_I2C_TEST == 1
    I2C_Test(); // has internal loop
    #endif

    #if RUN_SPI_TEST == 1
    while(1) {
        SPI_Test();
        for(u16 i = 0; i < 10000; i++);
    }
    #endif

    return 0;
}
