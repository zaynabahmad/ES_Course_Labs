#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"

#if MSSP_ACTIVE_MODE != MSSP_MODE_SPI

/* --- SPI disabled: MSSP configured for I2C --- */
void SPI_Init(void)                              {}
void SPI_Transmit(u8 Data)                       { (void)Data; }
u8   SPI_Receive(void)                           { return 0; }
void SPI_TransmitReceive(u8 TxData, u8 *RxData) { (void)TxData; if (RxData) *RxData = 0; }

#else

/* --- Full SPI Master implementation --- */

void SPI_Init(void)
{
    /* Pin directions: SCK=RC3 output, SDO=RC5 output, SDI=RC4 input */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);

    /* SSPSTAT: SMP and CKE */
#if SPI_SMP
    SET_BIT(SSPSTAT, SMP_BIT);
#else
    CLR_BIT(SSPSTAT, SMP_BIT);
#endif

#if SPI_CKE
    SET_BIT(SSPSTAT, CKE_BIT);
#else
    CLR_BIT(SSPSTAT, CKE_BIT);
#endif

    /* SSPCON: CKP, SSPM<3:0>, then enable */
#if SPI_CKP
    SET_BIT(SSPCON, CKP_BIT);
#else
    CLR_BIT(SSPCON, CKP_BIT);
#endif

    /* Set SSPM bits */
    SSPCON = (SSPCON & 0xF0) | (SPI_SSPM_BITS & 0x0F);

#if SPI_CKP
    SET_BIT(SSPCON, CKP_BIT);
#endif

    /* Enable MSSP */
    SET_BIT(SSPCON, SSPEN_BIT);
}

void SPI_Transmit(u8 Data)
{
    SSPBUF = Data;
    while (!GET_BIT(SSPSTAT, BF_BIT)) {}
    (void)SSPBUF;   /* Clear BF by reading */
}

u8 SPI_Receive(void)
{
    SSPBUF = 0xFF;  /* Send dummy byte to generate clock */
    while (!GET_BIT(SSPSTAT, BF_BIT)) {}
    return SSPBUF;
}

void SPI_TransmitReceive(u8 TxData, u8 *RxData)
{
    SSPBUF = TxData;
    while (!GET_BIT(SSPSTAT, BF_BIT)) {}
    if (RxData != 0)
        *RxData = SSPBUF;
    else
        (void)SSPBUF;
}

#endif /* MSSP_ACTIVE_MODE */
