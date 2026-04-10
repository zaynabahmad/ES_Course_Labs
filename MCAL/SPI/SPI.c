#include "SPI_interface.h"
#include "SPI_private.h"
#include "../../SERVICES/BIT_MATH.h"

void SPI_Master_Init(void) 
{
    /* 1. Configure SSPSTAT: 
       - SMP = 0: Data sampled at middle of data output time
       - CKE = 0: Transmit on transition from Idle to Active clock state */
    SSPSTAT = 0x00;

    /* 2. Configure SSPCON:
       - SSPM3:SSPM0 = 0000: SPI Master mode, clock = Fosc/4
       - CKP = 0: Idle state for clock is a low level
       - SSPEN = 1: Enable serial port */
    SSPCON = 0x20; 
}

void SPI_Slave_Init(void) 
{
    SSPSTAT = 0x00;
    /* SSPM3:SSPM0 = 0100: SPI Slave mode, clock = SCK pin, SS pin control disabled */
    SSPCON = 0x24; 
}

uint8 SPI_Exchange(uint8 data) 
{
    /* 1. Load data into buffer to start transmission */
    SSPBUF = data;

    /* 2. Wait until the transmission/reception is complete (BF bit is set) */
    while (GET_BIT(SSPSTAT, BF_BIT) == 0);

    /* 3. Return the received data from the buffer */
    return SSPBUF;
}