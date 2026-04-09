#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"

void SPI_Init(u8 Mode, u8 ClockSpeed)
{
    /* --- Configure SPI Master pins (lab slide 39) ---
     * RC3 / SCK  -> Output  (master drives clock)
     * RC4 / SDI  -> Input   (master receives data on MISO)   [was wrongly OUTPUT]
     * RC5 / SDO  -> Output  (master sends data on MOSI)      [was wrongly INPUT]
     */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_OUTPUT); /* SCK  */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);  /* MISO */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_OUTPUT); /* MOSI */

    /* Configure SSPSTAT: clock edge and sample point */
    SSPSTAT = 0x00;  /* SMP=0 (sample middle), CKE=0 by default */

    switch(Mode)
    {
        case SPI_MODE_0:                          /* CKP=0, CKE=0 */
            SSPSTAT &= ~(1 << CKE);
            break;
        case SPI_MODE_1:                          /* CKP=0, CKE=1 */
            SET_BIT(SSPSTAT, CKE);
            break;
        case SPI_MODE_2:                          /* CKP=1, CKE=0 */
            /* CKP is in SSPCON — set after SSPCON write below */
            break;
        case SPI_MODE_3:                          /* CKP=1, CKE=1 */
            SET_BIT(SSPSTAT, CKE);
            break;
        default:
            break;
    }
    SSPCON = (u8)((ClockSpeed & 0x03) | (1 << SSPEN));

    /* Set CKP for Mode 2 and Mode 3 after SSPCON is written */
    if(Mode == SPI_MODE_2 || Mode == SPI_MODE_3)
        SET_BIT(SSPCON, CKP);
}

void SPI_Write(u8 Data)
{
    SSPBUF = Data;

    /* Wait for transmission to complete (BF goes high when done) */
    while(!GET_BIT(SSPSTAT, BF));

    (void)SSPBUF; /* Dummy read to clear BF */
}

u8 SPI_Read(void)
{
    /* Clock in data by sending a dummy byte */
    SSPBUF = 0xFF;

    while(!GET_BIT(SSPSTAT, BF));

    return SSPBUF;
}

u8 SPI_Transfer(u8 Data)
{
    SSPBUF = Data;

    while(!GET_BIT(SSPSTAT, BF));

    return SSPBUF;  /* Contains received byte (MISO data) */
}

void SPI_ChipSelect(u8 Pin, u8 State)
{
    GPIO_SetPinValue(GPIO_PORTC, Pin, State);
}