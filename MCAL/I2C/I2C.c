#include "I2C_Config.h"
#include "I2C_Private.h"
#include "I2C_interface.h"

void I2C_Wait() {

  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F))
    ;
}

void I2C_Master_Init(u8 BaudRate)

{

  SSPCON = 0x28;

  SSPCON2 = 0x00;

  SSPSTAT = 0x00;

  SSPADD = ((_XTAL_FREQ / 4) / BaudRate) - 1;

  GPIO_SetPinDirection(I2C_PORT, I2C_SDA_PIN, GPIO_INPUT);
  GPIO_SetPinDirection(I2C_PORT, I2C_SCL_PIN, GPIO_INPUT);
}
void I2C_Start()

{

  //---[ Initiate I2C Start Condition Sequence ]---

  I2C_Wait();

  SET_BIT(SSPCON2, SEN_BIT);
}

void I2C_Restart() {

  //---[ Initiate I2C Restart Condition Sequence ]---

  I2C_Wait();

  SET_BIT(SSPCON2, RSEN_BIT);
}

void I2C_ACK(void)

{

  //---[ Send ACK - For Master Receiver Mode ]---

  I2C_Wait();

  CLR_BIT(SSPCON2, ACKDT_BIT); // 0 -> ACK, 1 -> NACK

  SET_BIT(SSPCON2, ACKEN_BIT); // Send ACK Signal!
}

void I2C_NACK(void)

{

  //---[ Send NACK - For Master Receiver Mode ]---

  I2C_Wait();

  SET_BIT(SSPCON2, ACKDT_BIT); // 0 -> ACK, 1 -> NACK

  SET_BIT(SSPCON2, ACKEN_BIT); // Send NACK Signal!
}
unsigned char I2C_Write(unsigned char Data)

{

  //---[ Send Byte, Return The ACK/NACK ]---

  I2C_Wait();

  SSPBUF = Data;

  I2C_Wait();

  return GET_BIT(SSPCON2, ACKSTAT_BIT);
}

unsigned char I2C_Read_Byte(void)

{

  //---[ Receive & Return A Byte ]---

  SET_BIT(SSPCON2, RCEN_BIT); // Enable & Start Reception

  while (!GET_BIT(PIR1, SSPIF_BIT))
    ; // Wait Until Completion

  CLR_BIT(PIR1, SSPIF_BIT); // Clear The Interrupt Flag Bit

  return SSPBUF; // Return The Received Byte
}
