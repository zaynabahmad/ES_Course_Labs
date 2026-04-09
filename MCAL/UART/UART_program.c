#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "UART_interface.h"
#include "UART_private.h"

void UART_voidInit(void) {
    /* Set for High-Speed Baud Rate */
    SET_BIT(TXSTA, 2); // BRGH = 1

    /* Set Baud Rate to 9600 bps (assuming 4MHz Fosc) */
    SPBRG = 25;

    /* Enable Asynchronous Serial Port */
    CLR_BIT(TXSTA, 4); // SYNC = 0
    SET_BIT(RCSTA, 7); // SPEN = 1

    /* Set RX-TX Pins to be in UART mode */
    SET_BIT(TRISC, 6); // TRISC6 = 1
    SET_BIT(TRISC, 7); // TRISC7 = 1

    /* Enable Transmission and Reception */
    SET_BIT(TXSTA, 5); // TXEN = 1
    SET_BIT(RCSTA, 4); // CREN = 1
}

void UART_voidTransmit(u8 Copy_u8Data) {
    /* Wait until Transmit Shift Register is empty (TRMT == 1) */
    while (GET_BIT(TXSTA, 1) == 0);
    TXREG = Copy_u8Data;
}

u8 UART_u8Receive(void) {
    /* Wait until Receive Interrupt Flag is set (RCIF == 1) */
    while (GET_BIT(PIR1, 5) == 0);
    return RCREG;
}