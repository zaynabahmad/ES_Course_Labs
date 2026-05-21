#include "SPI_Interface.h"

void SPI_MasterInit(void)
{
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_OUTPUT);

    SSPSTAT = 0x00;
    if(SPI_SMP_VALUE) { SET_BIT(SSPSTAT, SMP_BIT); } else { CLR_BIT(SSPSTAT, SMP_BIT); }
    if(SPI_CKE_VALUE) { SET_BIT(SSPSTAT, CKE_BIT); } else { CLR_BIT(SSPSTAT, CKE_BIT); }

    SSPCON = (SSPCON & ~SSPM_MASK) | (SPI_SPEED_MODE & SSPM_MASK);
    if(SPI_CKP_VALUE) { SET_BIT(SSPCON, CKP_BIT); } else { CLR_BIT(SSPCON, CKP_BIT); }
    SET_BIT(SSPCON, SSPEN_BIT);

    CLR_BIT(PIR1, SSPIF_BIT);
}

u8 SPI_Transceive(u8 Data)
{
    CLR_BIT(PIR1, SSPIF_BIT);
    SSPBUF = Data;

    while(!GET_BIT(SSPSTAT, BF_BIT)) { ; }

    CLR_BIT(PIR1, SSPIF_BIT);

    return SSPBUF;
}

void SPI_Write(u8 Data)
{
    (void)SPI_Transceive(Data);
}

u8 SPI_Read(void)
{
    return SPI_Transceive(0xFF);
}

void SPI_Disable(void)
{
    CLR_BIT(SSPCON, SSPEN_BIT);
}
