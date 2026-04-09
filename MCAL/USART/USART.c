#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"

#include "../../SERVICES/BIT_MATH.h"

/* Global Pointer To Callback Function */
void (*UART_Callback)(u8) = NULL;

void UART_RX_Init(void)
{
    /* Set Baud Rate using the calculated value */
    SPBRG = SPBRG_VALUE;

    /* Set Speed Mode */
    #if UART_HIGH_SPEED == 1
        SET_BIT(TXSTA, BRGH_BIT);
    #else
        CLR_BIT(TXSTA, BRGH_BIT);
    #endif

    /* Set Asynchronous Mode */
    CLR_BIT(TXSTA, SYNC_BIT);

    /* Enable Serial Port */
    SET_BIT(RCSTA, SPEN_BIT);

    /* Enable Continuous Receive */
    SET_BIT(RCSTA, CREN_BIT);

    /* Enable UART RX Interrupt */
    SET_BIT(PIE1, RCIE_BIT);

    /* Enable Peripheral Interrupt */
    SET_BIT(INTCON, PEIE_BIT);

    /* Enable Global Interrupt */
    SET_BIT(INTCON, GIE_BIT);
}

void UART_TX_Init(void)
{
    /* Set Baud Rate using the calculated value */
    SPBRG = SPBRG_VALUE;

    /* Set Speed Mode */
    #if UART_HIGH_SPEED == 1
        SET_BIT(TXSTA, BRGH_BIT);
    #else
        CLR_BIT(TXSTA, BRGH_BIT);
    #endif

    /* Set Asynchronous Mode */
    CLR_BIT(TXSTA, SYNC_BIT);
    
    /* Enable Serial Port */
    SET_BIT(RCSTA, SPEN_BIT);

    /* Enable Transmission */
    SET_BIT(TXSTA, TXEN_BIT);
}

void UART_Write(u8 Data)
{
    /* Wait until the Transmit Shift Register is empty */
    while(!GET_BIT(TXSTA, TRMT_BIT));
    
    /* Send the data byte */
    TXREG = Data;
}

u8 UART_Read(void)
{
    /* Wait until data is received and the buffer is full */
    while(!GET_BIT(PIR1, RCIF_BIT));

    /* Return the received data */
    return RCREG;
}

u8 UART_TX_Empty(void)
{
    return GET_BIT(TXSTA, TRMT_BIT);
}

void UART_SetCallback(void (*Callback)(u8))
{
    if(Callback != NULL)
    {
        UART_Callback = Callback;
    }
}

void UART_SendString(char* str)
{
    u8 i = 0;
    while(str[i] != '\0')
    {
        UART_Write(str[i]);
        i++;
    }
}

void UART_SendNumber(s32 num)
{
    char str[13]; // Buffer for up to 10 digits + sign
    
    /* mikroC has a built-in function to convert Long to String */
    LongToStr(num, str);
    
    /* The LongToStr often adds spaces at the start, 
       we send the whole converted string. */
    UART_SendString(str);
}

void UART_ISR(void)
{
    /* Reading RCREG automatically clears the RCIF flag */
    u8 uart_data = RCREG;

    /* Execute the callback if it is registered */
    if(UART_Callback != NULL)
    {
        UART_Callback(uart_data);
    }
}
