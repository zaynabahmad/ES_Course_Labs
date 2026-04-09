#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"

void SPI_Init(u8 Mode, u8 ClockSpeed)
{
    /* Configure SPI pins */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_OUTPUT);  /* RC3/SCK */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_INPUT);   /* RC5/MISO */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_OUTPUT);  /* RC4/MOSI */

    /* Configure SSPSTAT for SPI mode */
    if(Mode == SPI_MODE_0) {
        SSPSTAT = 0x00;  /* CKE=0, SMP=0 */
    }
    else if(Mode == SPI_MODE_1) {
        SET_BIT(SSPSTAT, CKE);  /* CKE=1, SMP=0 */
    }
    else if(Mode == SPI_MODE_2) {
        SET_BIT(SSPSTAT, SMP);  /* CKE=0, SMP=1 */
    }
    else if(Mode == SPI_MODE_3) {
        SSPSTAT = (1 << CKE) | (1 << SMP);  /* CKE=1, SMP=1 */
    }

    /* Configure SSPCON for SPI Master mode */
    u8 sspcon_value = (ClockSpeed & 0x03) | (1 << SSPEN);
    SSPCON = sspcon_value;
}

void SPI_Write(u8 Data)
{
    SSPBUF = Data;

    /* Wait for transmission to complete */
    while(!GET_BIT(SSPSTAT, BF));
}

u8 SPI_Read(void)
{
    /* Send dummy byte to clock in data */
    SSPBUF = 0xFF;

    /* Wait for reception complete */
    while(!GET_BIT(SSPSTAT, BF));

    /* Return received data */
    return SSPBUF;
}

u8 SPI_Transfer(u8 Data)
{
    /* Send data and read simultaneously */
    SSPBUF = Data;

    /* Wait for transfer complete */
    while(!GET_BIT(SSPSTAT, BF));

    /* Return received data */
    return SSPBUF;
}

void SPI_ChipSelect(u8 Pin, u8 State)
{
    /* Note: CS pin must be managed by application layer */
    /* This is a helper function for convenience */
    GPIO_SetPinValue(GPIO_PORTC, Pin, State);
}
