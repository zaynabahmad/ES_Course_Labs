#include "../../SERVICES/Bit_Math.h"
#include "SPI.h"

/* Register Definitions (Private to SPI.c) */
#define SSPSTAT     *((volatile u8*)0x94)
#define SSPCON      *((volatile u8*)0x14)
#define SSPBUF      *((volatile u8*)0x13)
#define TRISC       *((volatile u8*)0x87)

void M_SPI_voidMasterInit(void) {
    /* 1. Configuration of SPI Pins on PORTC */
    CLR_BIT(TRISC, 3); // SCK as Output
    SET_BIT(TRISC, 4); // SDI as Input
    CLR_BIT(TRISC, 5); // SDO as Output

    /* 2. SSPSTAT: 
       Bit 7: SMP = 1 (Input data sampled at end of data output time)
       Bit 6: CKE = 0 (Transmit on transition from Idle to Active clock state)
    */
    SSPSTAT = 0x80;

    /* 3. SSPCON: 
       Bit 5: SSPEN = 1 (Enable Serial Port)
       Bit 4: CKP = 0 (Idle state for clock is low level)
       Bits 3-0: SSPM = 0000 (SPI Master mode, clock = Fosc/4 = 2MHz at 8MHz crystal)
    */
    SSPCON = 0x20;
}

u8 M_SPI_u8Tranceive(u8 copy_u8Data) {
    /* 1. Load data into the Buffer to start transmission */
    SSPBUF = copy_u8Data;

    /* 2. Wait until the Buffer Full (BF) flag is set (conversion complete) */
    while(GET_BIT(SSPSTAT, 0) == 0);

    /* 3. Return the received data from the buffer */
    return SSPBUF;
}