#include "../../APP/app_interface.h"
#include "../../MCAL/SPI/SPI_interface.h"

void APP_SPI_Test(void) {
    SPI_voidInitMaster();
    
    while(1) {
        SPI_u8Transfer('S');
        Delay_ms(200);
    }
}