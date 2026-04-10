#include "SPI_INTERFACE.h"

void SPI_Master_init(){

CLR_BIT(SSPCON,SSPM0);
CLR_BIT(SSPCON,SSPM1);
CLR_BIT(SSPCON,SSPM2);
CLR_BIT(SSPCON,SSPM3);
SET_BIT(SSPCON,SSPEN);
CLR_BIT(SSPCON,CKP);
CLR_BIT(SSPSTAT,CKE);
CLR_BIT(SSPSTAT,SMP);
CLR_BIT(TRISC,5);
SET_BIT(TRISC,4);
CLR_BIT(TRISC,3);
SET_BIT(PIE1,SSPIE);


}
void SPI_write(u8 bits){
SSPBUF=bits;
while(!GET_BIT(SSPSTAT,BF));

}
void SPI_Slave_init(){

CLR_BIT(SSPCON,SSPM0);
CLR_BIT(SSPCON,SSPM1);
SET_BIT(SSPCON,SSPM2);
CLR_BIT(SSPCON,SSPM3);
SET_BIT(SSPCON,SSPEN);
CLR_BIT(SSPCON,CKP);
CLR_BIT(SSPSTAT,CKE);
CLR_BIT(SSPSTAT,SMP);
CLR_BIT(TRISC,5);
SET_BIT(TRISC,4);
SET_BIT(TRISC,3);
SET_BIT(TRISA,5);
SET_BIT(PIE1,SSPIE);
SET_BIT(INTCON,GIE);
SET_BIT(INTCON,PEIE);
CLR_BIT(ADCON1,PCFG3);
SET_BIT(ADCON1,PCFG2);
CLR_BIT(ADCON1,PCFG1);
CLR_BIT(ADCON1,PCFG0);

}

u8 SPI_Read(void)
{
    SSPBUF = 0xFF;
    while(!GET_BIT(SSPSTAT, BF));
    return SSPBUF;
}

// ================= CALLBACK =================
static void (*SPI_Callback)(u8) = 0;

void SPI_SetCallback(void (*callback)(u8))
{
    if(callback != 0){
        SPI_Callback = callback;
    }
}

// ================= ISR =================
void SPI_ISR(void)
{
    u8 bits = SSPBUF;

    CLR_BIT(PIR1, SSPIF);

    if(SPI_Callback != 0){
        SPI_Callback(bits);
    }
}




