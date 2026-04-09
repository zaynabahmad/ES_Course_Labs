#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"

void SPI_Master_Init(void) 
{
    // Configure I/O Pins
    // RC5/SDO -> Output, RC4/SDI -> Input, RC3/SCK -> Output 
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_OUTPUT);

    //  Mode & Clock (Apply the Master clock config to bottom 4 bits)
    SSPCON = (SSPCON & 0xF0) | SPI_MASTER_MODE_CLOCK;

    // Set Clock Rules (Mode 0: CKP = 0, CKE = 0) 
    CLR_BIT(SSPCON, CKP);
    CLR_BIT(SSPSTAT, CKE);

    // Set Sampling (SMP = 0 for middle of data output time)
    CLR_BIT(SSPSTAT, SMP);

    //Enable SPI 
    SET_BIT(SSPCON, SSPEN);
}

void SPI_Slave_Init(void) 
{
    //Configure I/O Pins
    // RC5/SDO -> Output, RC4/SDI -> Input, RC3/SCK -> Input, RA5/SS -> Input 
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN5, GPIO_INPUT); // SS Pin

    //Set Mode (Apply Slave mode config) 
    SSPCON = (SSPCON & 0xF0) | SPI_SLAVE_MODE;

    // Match Master Clock (Mode 0: CKP = 0, CKE = 0) 
    CLR_BIT(SSPCON, CKP);
    CLR_BIT(SSPSTAT, CKE);

    // Clear Sampling (Must be cleared in slave mode) 
    CLR_BIT(SSPSTAT, SMP);

    // Enable SPI 
    SET_BIT(SSPCON, SSPEN);
}

u8 SPI_Transfer(u8 data) 
{
    // Write a byte to SSPBUF to start transmission 
    SSPBUF = data;

    // Wait until Buffer Full (BF) bit is set
    while(GET_BIT(SSPSTAT, BF) == 0);

    // Read to clear BF and return the received data
    return SSPBUF;
}