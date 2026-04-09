#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "UART_private.h"
#include "UART_interface.h"

void UART_voidInit(void) {
    /* Set Baud Rate to 9600 for an 8MHz clock (Value = 51) */
    SPBRG_REG = 51;

    /* Enable High-Speed Baud Rate mode and turn on the Transmitter */
    SET_BIT(TXSTA_REG, 2);
    SET_BIT(TXSTA_REG, 5);

    /* Enable the Serial Port and turn on the Receiver for incoming data */
    SET_BIT(RCSTA_REG, 7);
    SET_BIT(RCSTA_REG, 4);
}

void UART_voidSendData(u8 copy_u8Data) {
    /* Wait  until the Transmit Buffer is empty and ready for new data */
    while(GET_BIT(PIR1_REG, 4) == 0);
    TXREG_REG = copy_u8Data;
}

u8 UART_u8ReceiveData(void) {
    /* Wait until the Receive Flag is set, indicating data has arrived */
    while(GET_BIT(PIR1_REG, 5) == 0);
    return RCREG_REG;
}

void UART_voidSendString(u8 *copy_u8String) {
    u8 i = 0;
    /* Loop through the string and send each character until the null terminator */
    while(copy_u8String[i] != '\0') {
        UART_voidSendData(copy_u8String[i]);
        i++;
    }
}