#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "../../SERVICES/BIT_MATH.h"

static u8 SPI_Mode = SPI_DEFAULT_MODE;

void SPI_Init(u8 Mode)
{
    u8 SSPCON_Value = 0;

    SPI_Mode = Mode;

    if (Mode == SPI_MODE_MASTER)
    {
        CLR_BIT(TRISC, 3);
    }
    else
    {
        SET_BIT(TRISC, 3);
    }
    SET_BIT(TRISC, 4);
    CLR_BIT(TRISC, 5);

    SSPCON_Value = (Mode == SPI_MODE_MASTER) ? 0x52 : 0x44;
    SSPCON = SSPCON_Value;

    SSPSTAT = 0x80;

    CLR_BIT(PIR1, SSPIF);

    if (SPI_INTERRUPT_ENABLE)
    {
        SET_BIT(PIE1, SSIE);
    }
}

void SPI_Write(u8 Data)
{
    while (GET_BIT(SSPSTAT, BF));
    SSPBUF = Data;
}

u8 SPI_Read(void)
{
    while (!GET_BIT(SSPSTAT, BF));
    CLR_BIT(PIR1, SSPIF);
    return SSPBUF;
}

u8 SPI_TransmitReceive(u8 Data)
{
    SPI_Write(Data);

    while (!GET_BIT(SSPSTAT, BF));

    CLR_BIT(PIR1, SSPIF);
    return SSPBUF;
}

void SPI_SetClockRate(u8 ClockRate)
{
    u8 SSPCON_Temp = SSPCON & 0xF0;

    if (SPI_Mode == SPI_MODE_MASTER)
    {
        switch (ClockRate)
        {
        case SPI_CLK_FOSC_4:
            SSPCON_Temp |= 0x00;
            break;
        case SPI_CLK_FOSC_16:
            SSPCON_Temp |= 0x01;
            break;
        case SPI_CLK_FOSC_64:
            SSPCON_Temp |= 0x02;
            break;
        case SPI_CLK_TMR2:
            SSPCON_Temp |= 0x03;
            break;
        }
    }

    SSPCON = SSPCON_Temp;
}

void SPI_SetClockPolarity(u8 Polarity)
{
    if (Polarity == SPI_CPOL_HIGH)
        SET_BIT(SSPSTAT, CKP);
    else
        CLR_BIT(SSPSTAT, CKP);
}

void SPI_SetClockPhase(u8 Phase)
{
    if (Phase == SPI_CPHA_TRAILING)
        SET_BIT(SSPSTAT, SMP_STATUS);
    else
        CLR_BIT(SSPSTAT, SMP_STATUS);
}

void SPI_EnableInterrupt(void)
{
    SET_BIT(PIE1, SSIE);
}

void SPI_DisableInterrupt(void)
{
    CLR_BIT(PIE1, SSIE);
}
