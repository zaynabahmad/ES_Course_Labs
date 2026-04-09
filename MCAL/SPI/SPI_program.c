#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"


/* ════════════════════════════════════════
   INIT
   ════════════════════════════════════════ */
void SPI_Init(void)
{
  
    CLR_BIT(TRISC, TRISC3);   /* SCK output */
    CLR_BIT(TRISC, TRISC5);   /* SDO output */
    SET_BIT(TRISC, TRISC4);   /* SDI input  */

    GPIO_SetPinDirection(SPI_CS_PORT, SPI_CS_PIN, GPIO_OUTPUT);
    GPIO_SetPinValue(SPI_CS_PORT, SPI_CS_PIN, GPIO_HIGH);  /* CS idle HIGH */

 
    SSPSTAT = 0x00;
#if SPI_SMP_CONFIG == 1
    SET_BIT(SSPSTAT, SSPSTAT_SMP);
#else
    CLR_BIT(SSPSTAT, SSPSTAT_SMP);
#endif

#if SPI_CKE_CONFIG == 1
    SET_BIT(SSPSTAT, SSPSTAT_CKE);
#else
    CLR_BIT(SSPSTAT, SSPSTAT_CKE);
#endif


    SSPCON = 0x00;

#if SPI_CKP_CONFIG == 1
    SET_BIT(SSPCON, SSPCON_CKP);
#else
    CLR_BIT(SSPCON, SSPCON_CKP);
#endif

    /* Load clock divider bits into SSPM[3:0] */
    SSPCON |= (u8)(SPI_CLOCK_CONFIG & 0x0F);

    /* Enable MSSP module */
    SET_BIT(SSPCON, SSPCON_SSPEN);
}



u8 SPI_Transceive(u8 val)
{
    /* Clear BF by reading SSPBUF first (in case a stale byte sits there) */
    (void)SSPBUF;

    /* Load byte → starts transmission */
    SSPBUF = val;

    /* Wait until the 8-bit transfer is complete */
    while (GET_BIT(SSPSTAT, SSPSTAT_BF) == 0) { }

    /* Reading SSPBUF clears BF automatically */
    return SSPBUF;
}



void SPI_SendByte(u8 val)
{
    (void)SPI_Transceive(val);   /* RX byte discarded */
}

u8 SPI_ReceiveByte(void)
{
    return SPI_Transceive(0xFFu);  /* Clock out dummy 0xFF, capture RX */
}

void SPI_SendBuffer(const u8 *buf, u8 len)
{
    u8 i;
    for (i = 0u; i < len; i++)
    {
        SPI_SendByte(buf[i]);
    }
}

void SPI_ReceiveBuffer(u8 *buf, u8 len)
{
    u8 i;
    for (i = 0u; i < len; i++)
    {
        buf[i] = SPI_ReceiveByte();
    }
}



void SPI_CS_Enable(void)
{
    GPIO_SetPinValue(SPI_CS_PORT, SPI_CS_PIN, GPIO_LOW);
}

void SPI_CS_Disable(void)
{
    GPIO_SetPinValue(SPI_CS_PORT, SPI_CS_PIN, GPIO_HIGH);
}
