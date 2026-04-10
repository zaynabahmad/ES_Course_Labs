#include "SPI_Config.h"
#include "SPI_Private.h"
#include "SPI_interface.h"

void SPI_Master_Init() {

  // Set SPI to master and sck to fosc/64
  CLR_BIT(SSPCON, SSPM0_BIT);
  CLR_BIT(SSPCON, SSPM1_BIT);
  CLR_BIT(SSPCON, SSPM2_BIT);
  CLR_BIT(SSPCON, SSPM3_BIT);

  // Enable sync serial port
  SET_BIT(SSPCON, SSPEN_BIT);

  // Configure clock polarity and phase
  CLR_BIT(SSPCON, CKP_BIT);
  CLR_BIT(SSPSTAT, CKE_BIT);

  // Configure sampling time
  CLR_BIT(SSPSTAT, SMP_BIT);

  GPIO_SetPinDirection(SPI_PORT, SPI_SDO_PIN, GPIO_OUTPUT);
  GPIO_SetPinDirection(SPI_PORT, SPI_SDI_PIN, GPIO_INPUT);
  GPIO_SetPinDirection(SPI_PORT, SPI_SCK_PIN, GPIO_OUTPUT);
}

void SPI_Slave_Init(void) {
  // Set SPI to master and sck to fosc/64
  CLR_BIT(SSPCON, SSPM0_BIT);
  CLR_BIT(SSPCON, SSPM1_BIT);
  SET_BIT(SSPCON, SSPM2_BIT);
  CLR_BIT(SSPCON, SSPM3_BIT);

  // Enable sync serial port
  SET_BIT(SSPCON, SSPEN_BIT);

  // Configure clock polarity and phase
  CLR_BIT(SSPCON, CKP_BIT);
  CLR_BIT(SSPSTAT, CKE_BIT);

  // Configure sampling time
  CLR_BIT(SSPSTAT, SMP_BIT);

  // Config io pins for slave mode
  GPIO_SetPinDirection(SPI_PORT, SPI_SDO_PIN, GPIO_OUTPUT);
  GPIO_SetPinDirection(SPI_PORT, SPI_SDI_PIN, GPIO_INPUT);
  GPIO_SetPinDirection(SPI_PORT, SPI_SCK_PIN, GPIO_INPUT);

  CLR_BIT(ADCON1, PCFG0_BIT); // set pin a5 as SS
  CLR_BIT(ADCON1, PCFG1_BIT);
  SET_BIT(ADCON1, PCFG2_BIT);
  CLR_BIT(ADCON1, PCFG3_BIT);

  GPIO_SetPinDirection(SS_PORT, SS_PIN, GPIO_INPUT);

  CLR_BIT(PIR1, SSPIF_BIT); // Enable Interrupts

  SET_BIT(PIE1, SSPIE_BIT);

  SET_BIT(INTCON, PEIE_BIT);
  SET_BIT(INTCON, GIE_BIT);
}

void SPI_Write(unsigned char Data) {
  SSPBUF = Data;
  while (!GET_BIT(SSPSTAT, BF_BIT)) {
  };
}

unsigned char SPI_Read_Byte(void) {
  u8 Data;
  if (GET_BIT(SSPSTAT, BF_BIT)) {
    Data = SSPBUF;
    CLR_BIT(SSPSTAT, BF_BIT);
    CLR_BIT(PIR1, SSPIF_BIT);
    CLR_BIT(SSPCON, SSPOV_BIT);
  }

  return Data;
}

void (*SPI_Callback)(u8) = 0;

void SPI_SetCallback(void (*Callback)(u8)) {
  if (Callback != 0) {
    SPI_Callback = Callback;
  }
}
void SPI_ISR(void) {
  u8 SPI_data = SSPBUF; //
  CLR_BIT(PIR1, SSPIF_BIT);
  if (SPI_Callback != 0) {
    SPI_Callback(SPI_data); //
  }
}
