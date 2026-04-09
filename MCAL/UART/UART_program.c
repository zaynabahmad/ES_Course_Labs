#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../GPIO/GPIO_interface.h"
#include "UART_private.h"
#include "UART_interface.h"

void UART_Init(void)
{
    //  Configure UART Pins using GPIO driver
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN6, GPIO_OUTPUT); // TX
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN7, GPIO_INPUT);  // RX

    //  Baud rate (9600 @ 4MHz)
    SPBRG_REG = 25;

    //  UART Mode Configuration
    CLR_BIT(TXSTA_REG, 4); // SYNC = 0 ? Asynchronous
    SET_BIT(TXSTA_REG, 2); // BRGH = 0 ? Low speed

    //  Enable UART
    SET_BIT(TXSTA_REG, TXEN_BIT);   // Enable TX
    SET_BIT(RCSTA_REG, SPEN_BIT);   // Enable serial port
    SET_BIT(RCSTA_REG, CREN_BIT);   // Enable continuous receive
}
void UART_SendChar(u8 _data)
{
    while(!GET_BIT(TXSTA_REG, TRMT_BIT));
    TXREG_REG = _data;
}

u8 UART_ReceiveChar(void)
{
    // Wait until data is received (RCIF bit in PIR1 = bit 5)
    while(!GET_BIT(*((volatile u8*)0x0C), 5)); // PIR1 register

    // Handle Overrun Error (OERR)
    if(GET_BIT(RCSTA_REG, 1))
    {
        CLR_BIT(RCSTA_REG, CREN_BIT);
        SET_BIT(RCSTA_REG, CREN_BIT);
    }

    return RCREG_REG;
}