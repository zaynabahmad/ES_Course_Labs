#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"
#include "../../SERVICES/BIT_MATH.h"

void SPI_InitMaster(void)
{
    /* Configure SPI Pins */
    CLR_BIT(TRISC, 5); // SDO as output
    CLR_BIT(TRISC, 3); // SCK as output
    SET_BIT(TRISC, 4); // SDI as input
    
    /* Config SPI mode to FOSC/4 */
    SSPCON &= 0xF0; 
    SSPCON |= SPI_MASTER_OSC_DIV_4;
    
    /* Set Clock Polarity */
#if SPI_CLOCK_POLARITY == 1
    SET_BIT(SSPCON, CKP);
#else
    CLR_BIT(SSPCON, CKP);
#endif

    /* Set Clock Edge */
#if SPI_CLOCK_EDGE == 1
    SET_BIT(SSPSTAT, CKE);
#else
    CLR_BIT(SSPSTAT, CKE);
#endif

    /* Set Sample Phase */
#if SPI_SAMPLE_PHASE == 1
    SET_BIT(SSPSTAT, SMP);
#else
    CLR_BIT(SSPSTAT, SMP);
#endif

    /* Enable SPI Module */
    SET_BIT(SSPCON, SSPEN);
}

void SPI_InitSlave(void)
{
    /* Configure SPI Pins */
    CLR_BIT(TRISC, 5); // SDO as output
    SET_BIT(TRISC, 3); // SCK as input
    SET_BIT(TRISC, 4); // SDI as input
    SET_BIT(TRISA, 5); // SS as input
    
    /* Set Slave Mode with SS enabled */
    SSPCON &= 0xF0; 
    SSPCON |= 0x04; // SSPM3:SSPM0 = 0100 (Slave mode, clock = SCK pin, SS pin control enabled)
    
    /* Set Clock Polarity */
#if SPI_CLOCK_POLARITY == 1
    SET_BIT(SSPCON, CKP);
#else
    CLR_BIT(SSPCON, CKP);
#endif

    /* Set Clock Edge */
#if SPI_CLOCK_EDGE == 1
    SET_BIT(SSPSTAT, CKE);
#else
    CLR_BIT(SSPSTAT, CKE);
#endif

    /* Sample Phase must be 0 in Slave Mode */
    CLR_BIT(SSPSTAT, SMP);

    /* Enable SPI Module */
    SET_BIT(SSPCON, SSPEN);
}

u8 SPI_Transfer(u8 Data)
{
    SSPBUF = Data;
    while(!GET_BIT(SSPSTAT, BF)); // Wait until buffer is full
    return SSPBUF;
}
