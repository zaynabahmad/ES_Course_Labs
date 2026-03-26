#include "../../SERVICES/Bit_Math.h"
#include "../../SERVICES/Std_Types.h"
#include "UART.h"

/* Register Definitions (Private to UART.c) */
#define TXSTA    *((volatile u8*)0x98)
#define RCSTA    *((volatile u8*)0x18)
#define SPBRG    *((volatile u8*)0x99)
#define TXREG    *((volatile u8*)0x19)
#define RCREG    *((volatile u8*)0x1A)
#define PIR1     *((volatile u8*)0x0C)
#define TRISC    *((volatile u8*)0x87)

void UART_voidInit(void) {
    /* 1. Configure Pins: RC6 (TX) Output, RC7 (RX) Input */
    CLR_BIT(TRISC, 6); 
    SET_BIT(TRISC, 7);

    /* 2. Baud Rate: 9600 @ 8MHz High Speed 
       Formula: (8,000,000 / (16 * 9600)) - 1 = 51 */
    SPBRG = 51; 

    /* 3. TXSTA: 
       Bit 5 (TXEN) = 1, Bit 2 (BRGH) = 1 -> 0x24 */
    TXSTA = 0x24;

    /* 4. RCSTA: 
       Bit 7 (SPEN) = 1, Bit 4 (CREN) = 1 -> 0x90 */
    RCSTA = 0x90;
}

void UART_voidSendData(u8 copy_u8Data) {
    /* Wait for TXIF (Bit 4 of PIR1) to be empty */
    while(GET_BIT(PIR1, 4) == 0); 
    TXREG = copy_u8Data;
}

/* Updated to 'const char' for better compatibility with "strings" */
void UART_voidSendString(char *copy_pu8String) {
    u32 i = 0;
    while(copy_pu8String[i] != '\0') {
        UART_voidSendData(copy_pu8String[i]);
        i++;
    }
}

u8 UART_u8ReceiveData(void) {
    /* Wait for RCIF (Bit 5 of PIR1) to be set */
    while(GET_BIT(PIR1, 5) == 0); 
    return RCREG;
}