 #include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void SPI_Test_voidInit(void) {
    SPI_voidInitMaster();
    GPIO_voidSetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_OUTPUT); // Status LED
}

void SPI_Test_voidRun(void) {
    u8 Local_u8ReceivedData;

    /* Send test byte */
    Local_u8ReceivedData = SPI_u8Transceive(0x55);

    /* Logic: If received specific data, toggle LED */
    if(Local_u8ReceivedData == 0x55) {
        GPIO_voidTogglePin(GPIO_PORTB, GPIO_PIN0);
    }
}