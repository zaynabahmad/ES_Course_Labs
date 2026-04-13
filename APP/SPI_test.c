#include "../MCAL/SPI/SPI_interface.h"

void SPI_Test(void)
{
    u8 TxData = 0xA5;
    u8 RxData;

    /* Test 1: Initialize SPI as Master with Fosc/4 clock and CPOL=0, CPHA=0 */
    SPI_Init(SPI_MASTER, SPI_CLK_FOSC_4, SPI_CPOL_0_CPHA_0);

    /* Test 2: Send a byte and receive response */
    RxData = SPI_Write(TxData);

    /* Test 3: Read a byte (send dummy data) */
    RxData = SPI_Read();

    /* Test 4: Full-duplex operation */
    RxData = SPI_WriteRead(0x5A);

    /* Test 5: Set interrupt callback */
    SPI_SetCallback(NULL_PTR);

    /* Test 6: Send multiple bytes */
    SPI_Write(0xC3);
    SPI_Write(0x3C);

    /* Test 7: Disable SPI */
    SPI_Disable();

    /* Test 8: Re-enable SPI */
    SPI_Enable();
}
