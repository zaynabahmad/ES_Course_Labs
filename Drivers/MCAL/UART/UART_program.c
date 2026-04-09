
#include "../../SERVICES/BIT_MATH.h"
#include "../../MCAL/UART/UART_private.h"
#include "../../MCAL/UART/UART_interface.h"
#include "../../MCAL/UART/UART_config.h"


void UART_voidInit(uint32 Copy_BaudRate) {
    // RC6/TX, RC7/RX as I/O
    GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN6, GPIO_PIN_OUTPUT);
    GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN7, GPIO_PIN_INPUT);
    
    // SPBRG = Fosc/(16*Baud) - 1  (8MHz, High Speed)
    uint16 spbrg = (8000000UL / (16UL * Copy_BaudRate)) - 1;
    SPBRG = (uint8)spbrg;
    
    // 8-bit, High speed, Async, TX/RX enable
    TXSTA = 0x24;
    RCSTA = 0x90;
}

void UART_voidTransmit(uint8 Copy_Data) {
    while(GET_BIT(TXSTA, 1) == 0);  // Wait TXREG empty
    TXREG = Copy_Data;
}

uint8 UART_u8Receive(void) {
    while(GET_BIT(RCSTA, 0) == 0);  // Wait data ready
    return RCREG;
}