#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"

void SPI_Init(SPI_ConfigType *ConfigPtr)
{
    if (ConfigPtr == 0)
    {
        return;
    }

    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_OUTPUT);

    SSPCON &= (u8)~0x3F;
    SSPCON |= (ConfigPtr->Mode & 0x0F);

    if (ConfigPtr->ClockPolarity != 0)
    {
        SET_BIT(SSPCON, CKP_BIT);
    }
    else
    {
        CLR_BIT(SSPCON, CKP_BIT);
    }

    if (ConfigPtr->ClockPhase != 0)
    {
        SET_BIT(SSPSTAT, CKE_BIT);
    }
    else
    {
        CLR_BIT(SSPSTAT, CKE_BIT);
    }

    if (ConfigPtr->SampleAtEnd != 0)
    {
        SET_BIT(SSPSTAT, SMP_BIT);
    }
    else
    {
        CLR_BIT(SSPSTAT, SMP_BIT);
    }

    SET_BIT(SSPCON, SSPEN_BIT);
}

u8 SPI_Transfer(u8 Data)
{
    CLR_BIT(PIR1_S, SSPIF_BIT);
    SSPBUF = Data;

    while (GET_BIT(PIR1_S, SSPIF_BIT) == 0)
    {
    }

    return SSPBUF;
}
