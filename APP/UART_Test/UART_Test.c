#include "UART_Test.h"
#include "../../MCAL/USART/USART_Interface.h"
#include "../../HAL/LED/LED_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

/* Define Status LED Pin (e.g. PORTC Pin 0) */
#define STATUS_LED_PORT     GPIO_PORTC
#define STATUS_LED_PIN      GPIO_PIN0

/* Software flags for UART RX */
volatile u8 g_u8ReceivedData = 0;
volatile u8 g_u8DataReady = 0;

/* Helper function to send simple strings over UART */
static void UART_SendString(char *str)
{
    while (*str)
    {
        UART_Write(*str);
        str++;
    }
}

/* Interrupt Callback Routine for UART RX */
void App_UART_RX_Callback(u8 Data)
{
    /* Set flag and store data inside ISR to trigger app logic */
    g_u8ReceivedData = Data;
    g_u8DataReady = 1;
}

void UART_Test_Init(void)
{
    /* 1. Setup Status LED using HAL Driver */
    LED_Init(STATUS_LED_PORT, STATUS_LED_PIN);
    
    /* 2. Setup UART Transmission and Reception */
    UART_TX_Init();
    UART_RX_Init();
    
    /* 3. Register UART RX Callback to listen for incoming data */
    UART_SetCallback(App_UART_RX_Callback);
    
    /* Send initial ready message */
    UART_SendString("System Ready. Send '1'(ON), '0'(OFF) or toggle any key: \r\n");
}

void UART_Test_App(void)
{
    /* Poll the software flag set by the ISR continuously in the main loop */
    if (g_u8DataReady == 1)
    {
        /* Clear the software flag first */
        g_u8DataReady = 0;
        
        /* Process the received command */
        if (g_u8ReceivedData == '1')
        {
            LED_On(STATUS_LED_PORT, STATUS_LED_PIN);
            UART_SendString("LED Turned ON \r\n");
        }
        else if (g_u8ReceivedData == '0')
        {
            LED_Off(STATUS_LED_PORT, STATUS_LED_PIN);
            UART_SendString("LED Turned OFF \r\n");
        }
        else
        {
            LED_Toggle(STATUS_LED_PORT, STATUS_LED_PIN);
            UART_SendString("LED Toggled \r\n");
        }
    }
}
