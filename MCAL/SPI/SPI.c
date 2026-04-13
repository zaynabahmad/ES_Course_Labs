#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*SPI_Callback)(u8) = NULL_PTR;
static u8 Local_SPI_Mode = SPI_MASTER;

void SPI_Init(u8 mode, u8 clockSpeed, u8 clockMode)
{
    u8 Temp = 0;

    Local_SPI_Mode = mode;
    SSPCON = 0x00;

    if (mode == SPI_MASTER)
    {
        switch (clockSpeed)
        {
            case SPI_CLK_FOSC_4:
                SSPCON = 0x20;
                break;
            case SPI_CLK_FOSC_16:
                SSPCON = 0x21;
                break;
            case SPI_CLK_FOSC_64:
                SSPCON = 0x22;
                break;
            case SPI_CLK_TMR2:
                SSPCON = 0x23;
                break;
            default:
                SSPCON = 0x20;
                break;
        }
    }
    else if (mode == SPI_SLAVE)
    {
        SSPCON = 0x04;
    }

    if ((clockMode == SPI_CPOL_1_CPHA_0) || (clockMode == SPI_CPOL_1_CPHA_1))
        SET_BIT(SSPCON, CKP);
    else
        CLR_BIT(SSPCON, CKP);

    SSPSTAT = 0x00;

    if ((clockMode == SPI_CPOL_0_CPHA_1) || (clockMode == SPI_CPOL_1_CPHA_1))
        SET_BIT(SSPSTAT, CKE);
    else
        SET_BIT(SSPSTAT, SMP);

    SET_BIT(SSPCON, SSPEN);

    if (mode == SPI_MASTER)
    {
        CLR_BIT(TRISC, 3);
        CLR_BIT(TRISC, 5);
        SET_BIT(TRISB, 4);
    }
    else
    {
        SET_BIT(TRISC, 3);
        SET_BIT(TRISC, 5);
        CLR_BIT(TRISB, 4);
    }

    SET_BIT(INTCON, 7);
    SET_BIT(PIE1, SSPIE);
    CLR_BIT(PIR1, SSPIF);
}

u8 SPI_Write(u8 data)
{
    CLR_BIT(SSPCON, SSPOV);
    CLR_BIT(SSPCON, WCOL);

    SSPBUF = data;

    while (!GET_BIT(SSPSTAT, BF));

    return SSPBUF;
}

u8 SPI_Read(void)
{
    SSPBUF = 0x00;

    while (!GET_BIT(SSPSTAT, BF));

    return SSPBUF;
}

u8 SPI_WriteRead(u8 dataOut)
{
    return SPI_Write(dataOut);
}

void SPI_SetCallback(void (*Callback)(u8))
{
    SPI_Callback = Callback;
}

void SPI_ISR(void)
{
    u8 RxData;

    CLR_BIT(PIR1, SSPIF);
    RxData = SSPBUF;

    if (SPI_Callback != NULL_PTR)
        SPI_Callback(RxData);
}

void SPI_Enable(void)
{
    SET_BIT(SSPCON, SSPEN);
}

void SPI_Disable(void)
{
    CLR_BIT(SSPCON, SSPEN);
}
