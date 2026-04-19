#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "../GPIO/GPIO_interface.h"

void UART_voidInit(u32 Copy_u32BaudRate) {
    /* 1. Set RC6 (TX) as Output and RC7 (RX) as Input using our GPIO Driver */
    GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN6, GPIO_OUTPUT);
    GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN7, GPIO_INPUT);

    /* 2. Baud Rate Calculation for 8MHz (High Speed BRGH=1)
       Formula: SPBRG = (Fosc / (16 * Baud)) - 1 */
    if(Copy_u32BaudRate == 9600) {
        SPBRG_REG = 51;
    }

    /* 3. Configure TXSTA: High Speed BRGH=1, Transmit Enable */
    TXSTA_REG = 0x24;

    /* 4. Configure RCSTA: Serial Port Enable, Continuous Receive */
    RCSTA_REG = 0x90;
}

void UART_voidSendData(u8 Copy_u8Data) {
    /* Wait for Transmit Buffer to be empty */
    while(GET_BIT(PIR1_REG, TXIF_BIT) == 0);
    TXREG_REG = Copy_u8Data;
}

u8 UART_u8ReceiveData(void) {
    /* Wait for Receive Buffer to be full */
    while(GET_BIT(PIR1_REG, RCIF_BIT) == 0);
    return RCREG_REG;
}

void UART_voidSendString(char* Copy_pchString) {
    u8 i = 0;
    while(Copy_pchString[i] != '\0') {
        UART_voidSendData(Copy_pchString[i]);
        i++;
    }
}