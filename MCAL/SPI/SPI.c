#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*SPI_Callback)(u8) = NULL;

void SPI_Init(void)
{
    /* 1. Configure GPIO Pins (RC3=SCK, RC4=SDI, RC5=SDO) */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_OUTPUT);

    /* 2. Configure Clock Phase and Polarity based on Config */
    #if (SPI_MODE == SPI_MODE_0) || (SPI_MODE == SPI_MODE_2)
        CLR_BIT(SSPSTAT, CKE_BIT);
    #else
        SET_BIT(SSPSTAT, CKE_BIT);
    #endif

    #if (SPI_MODE == SPI_MODE_0) || (SPI_MODE == SPI_MODE_1)
        CLR_BIT(SSPCON, CKP_BIT);
    #else
        SET_BIT(SSPCON, CKP_BIT);
    #endif

    /* 3. Set Master Mode & Clock Rate */
    SSPCON = (SSPCON & 0xF0) | SPI_MASTER_CLOCK_RATE;

    /* 4. Enable Module */
    SET_BIT(SSPCON, SSPEN_BIT);
}

u8 SPI_Tranceive(u8 trans_data)
{
    SSPBUF = trans_data;
    while (GET_BIT(SSPSTAT, BF_BIT) == 0);
    return SSPBUF;
}

/* Improvement 1: CS logic is just GPIO abstraction */
void SPI_SelectSlave(u8 Port, u8 Pin) {
    GPIO_SetPinValue(Port, Pin, GPIO_LOW);
}

void SPI_DeselectSlave(u8 Port, u8 Pin) {
    GPIO_SetPinValue(Port, Pin, GPIO_HIGH);
}

/* Improvement 2: Block transfer wrapper */
void SPI_TransmitBlock(u8* data_out, u8 length) {
    u8 i;
    for(i=0; i<length; i++) {
        SPI_Tranceive(data_out[i]);
    }
}

void SPI_ReceiveBlock(u8* data_in, u8 length) {
    u8 i;
    for(i=0; i<length; i++) {
        data_in[i] = SPI_Tranceive(0xFF); /* Send dummy 0xFF to read */
    }
}

/* Improvement 3: Interrupt Implementation */
void SPI_EnableInterrupt(void) {
    SET_BIT(PIE1, SSPIE_BIT);
}

void SPI_DisableInterrupt(void) {
    CLR_BIT(PIE1, SSPIE_BIT);
}

void SPI_SetCallback(void (*ptr)(u8)) {
    if(ptr != NULL) SPI_Callback = ptr;
}

void SPI_ISR(void) {
    /* Clear flag first */
    CLR_BIT(PIR1, SSPIF_BIT);
    
    if(SPI_Callback != NULL) {
        SPI_Callback(SSPBUF); /* Read the incoming byte and pass to app */
    }
}