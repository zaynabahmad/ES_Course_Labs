#include "../../SERVICES/BIT_MATH.h"
#include "../EXT_INT/EXT_INT_interface.h"
#include "../I2C/I2C_interface.h"
#include "../SPI/SPI_interface.h"
#include "../TIMER_0/TIMER_0_Interface.h"
#include "../USART/USART_interface.h"

extern void (*EXT_INT_Callback)(void);
extern void (*UART_Callback)(void);
extern void (*TIMER_0_Callback)(void);
extern void (*I2C_Callback)(void);
extern void (*SPI_Callback)(void);

void interrupt() {

  // UART RX interrupt
  if (GET_BIT(PIR1, RCIF)) {
    UART_ISR();
  }

  // external interrupt flag
  if (GET_BIT(INTCON, INTF_BIT)) {
    EXT_INT_ISR();
  }

  // TMR0 interrupt flag
  if (GET_BIT(INTCON, T0IF_BIT)) {
    TIMER_0_ISR();
  }

  // I2C/SPI interrupt flag
  if (GET_BIT(PIR1, SSPIF_BIT)) {
    if ((SSPCON & 0b1111) < 0b0110) {
      SPI_ISR();
    } else {
      I2C_ISR();
    }
  }
}
