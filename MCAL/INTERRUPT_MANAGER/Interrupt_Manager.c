#include "../../SERVICES/BIT_MATH.h"
#include "../EXT_INT/EXT_INT_interface.h"
#include "../TIMER_0/TIMER_0_Interface.h"
#include "../USART/USART_interface.h"

extern void (*EXT_INT_Callback)(void);
extern void (*UART_Callback)(void);
extern void (*TIMER_0_Callback)(void);

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
}
