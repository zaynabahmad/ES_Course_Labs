#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_InitMaster(void) {
    /* 1. Pin Directions */
    CLR_BIT(TRISC, SCL_SCK_PIN); // SCK is Output
    SET_BIT(TRISC, SDI_PIN);     // SDI is Input
    CLR_BIT(TRISC, SDO_PIN);     // SDO is Output

    /* 2. Configure SSPSTAT */
    // SMP = 0 (Sample at middle), CKE = 0 (Transmit on idle-to-active)
    SSPSTAT = 0x00;

    /* 3. Configure SSPCON */
    // SSPEN = 1 (Enable), CKP = 0 (Idle low), Mode = 0000 (Fosc/4)
    SSPCON = 0x20;
}

u8 SPI_Transceive(u8 Copy_u8Data) {
    /* 1. Put data into buffer to start transmission */
    SSPBUF = Copy_u8Data;

    /* 2. Wait for the SSPIF flag to indicate completion */
    while (GET_BIT(PIR1, SSPIF) == 0);

    /* 3. Clear the flag for next time */
    CLR_BIT(PIR1, SSPIF);

    /* 4. Return the data that was shifted in from the slave */
    return SSPBUF;
}