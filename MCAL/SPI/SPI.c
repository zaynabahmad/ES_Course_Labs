#include "SPI_Interface.h"

void SPI_Init(u8 Mode)
{
    SSPCON &= 0xF0;
    SSPCON |= (Mode & 0x0F);
    
    CLR_BIT(SSPSTAT, CKE);
    CLR_BIT(SSPCON, CKP);
    
    SET_BIT(SSPCON, SSPEN);
}

u8 SPI_Transceive(u8 Data)
{
    SSPBUF = Data;
    
    while(!GET_BIT(SSPSTAT, BF));
    
    return SSPBUF;
}

void SPI_Write(u8 Data)
{
    SSPBUF = Data;
    
    while(!GET_BIT(SSPSTAT, BF));
}

u8 SPI_Read(void)
{
    SSPBUF = 0xFF;
    
    while(!GET_BIT(SSPSTAT, BF));
    
    return SSPBUF;
}
