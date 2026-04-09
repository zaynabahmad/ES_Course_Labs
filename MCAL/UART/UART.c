#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART_Init(u32 baud) {
    /* 1. Pin Directions */
    CLR_BIT(TRISC, TX_PIN); // TX as Output
    SET_BIT(TRISC, RX_PIN); // RX as Input

    /* 2. Calculate Baud Rate (High Speed Mode BRGH=1) */
    // Formula: SPBRG = (Fosc / (16 * Baud)) - 1
    TXSTA = 0x00;
    SET_BIT(TXSTA, TXSTA_BRGH);
    SPBRG = (u8)((UART_FOSC / (16 * baud)) - 1);

    /* 3. Enable Transmit and Receive */
    SET_BIT(TXSTA, TXSTA_TXEN); // Enable Transmission
    SET_BIT(RCSTA, RCSTA_SPEN); // Enable Serial Port
    SET_BIT(RCSTA, RCSTA_CREN); // Enable Continuous Reception
}

void UART_SendByte(u8 Copy_u8Data) {
    /* Wait until the Transmit Buffer is empty (TXIF is set) */
    while (GET_BIT(PIR1, TXIF) == 0);

    /* Load data into register to start transmission */
    TXREG = Copy_u8Data;
}

u8 UART_ReceiveByte(void) {
    /* Wait until a byte is fully received (RCIF is set) */
    while (GET_BIT(PIR1, RCIF) == 0);

    /* Return the data. Note: Reading RCREG automatically clears RCIF */
    return RCREG;
}

void UART_SendString(const char* Copy_pcString) {
    u32 i = 0;
    while (Copy_pcString[i] != '\0') {
        UART_SendByte(Copy_pcString[i]);
        i++;
    }
}