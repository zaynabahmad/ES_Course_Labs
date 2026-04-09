
#include "../pic_config.h"
#include "i2c.h"
#include "../GPIO/gpio.h"


#define LM75_ADDR 0x48

void main() {
    ADCON1 = 0x06;
    TRISD  = 0x00;

    I2C1_Init(100000);    // 100 kHz

    while (1) {
        I2C1_Start();
        I2C1_Wr((LM75_ADDR << 1) | 1);  // Address + READ
        uint8 temp = I2C1_Rd(0);         // Read, send NACK (last byte)
        I2C1_Stop();

        PORTD = temp;
        Delay_ms(1000);
    }
}
