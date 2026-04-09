#include "app_tests.h"
#include "../MCAL/UART/UART_Interface.h"

static u8 APP_UART_Message[] = "UART Ready\r\n";
static volatile u8 APP_UART_LastByte = 0;
static UART_ConfigType APP_UART_Config = {9600UL, 1, 1, 1, 1};

static void APP_UART_EchoCallback(u8 Data)
{
    APP_UART_LastByte = Data;
}

void APP_UART_Test(void)
{
    UART_Init(&APP_UART_Config);
    UART_SetCallback(APP_UART_EchoCallback);
    UART_WriteString(APP_UART_Message);
}
