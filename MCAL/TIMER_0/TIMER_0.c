#include "TIMER_0_interface.h"

void TIMER_0_Init(void) {
  /* Initialize the tmr0 reg */
  TMR0 = 0;

  SET_BIT(OPTION_REG, T0CS_BIT); // internal clock

  /* Prescaler */
  SET_BIT(OPTION_REG, PSA_BIT); // internal clock
  SET_BIT(OPTION_REG, PS2_BIT); // Prescaler 256
  SET_BIT(OPTION_REG, PS1_BIT); // Prescaler 256
  SET_BIT(OPTION_REG, PS0_BIT); // Prescaler 256

  /* Configure the edge type for the external interrupt */
  TIMER_0_SetEdge(
      falling_edge); // Default to falling edge, can be changed later

  /* Clear the interrupt flag */
  CLR_BIT(INTCON, T0IF_BIT);
  CLR_BIT(INTCON,
          T0IE_BIT); // Ensure the external interrupt is disabled initially
}

void TIMER_0_Enable(void) {
  /* Enable the timer0 interrupt */
  SET_BIT(INTCON, T0IE_BIT);
  /* Enable global interrupts */
  SET_BIT(INTCON, GIE_BIT);

  CLR_BIT(INTCON, T0IF_BIT); // Clear any pending Timer flag
}

void TIMER_0_Disable(void) {
  /* Clear the interrupt flag */
  CLR_BIT(INTCON, T0IF_BIT);
  /* Disable the Timer interrupt */
  CLR_BIT(INTCON, T0IE_BIT);
}

void TIMER_0_SetEdge(u8 Edgetype) {
  if (Edgetype == rising_edge) {
    /* Configure for rising edge */
    CLR_BIT(OPTION_REG, INTEDGE_BIT); // INTEDG0 = 0 for rising edge
  } else if (Edgetype == falling_edge) {
    /* Configure for falling edge */
    SET_BIT(OPTION_REG, INTEDGE_BIT); // INTEDG0 = 1 for falling edge
  }
}
void TIMER_0_SetPSR(u8 PrescalerRate) {
  CLR_BIT(OPTION_REG, PS2_BIT);
  CLR_BIT(OPTION_REG, PS1_BIT);
  CLR_BIT(OPTION_REG, PS0_BIT);

  OPTION_REG |= (PrescalerRate & 0b111);
}

void (*TIMER_0_Callback)(void) = 0;

void TIMER_0_SetCallback(void (*ptr)(void)) {
  if (ptr != 0) {
    TIMER_0_Callback = ptr;
  }
}

void TIMER_0_ISR(void) {

  CLR_BIT(INTCON, T0IF_BIT);

  if (TIMER_0_Callback != 0) {
    TIMER_0_Callback();
  }
}
