#include "PWM_Config.h"
#include "PWM_Private.h"
#include "PWM_interface.h"

void PWM_Init(void) {
  /* Configure the external interrupt pin as input */

  PWM_SetPeriod(0xF);
  PWM_SetDutyCycle(0x0F);

  GPIO_SetPinDirection(PWM_PORT, PWM_PIN, GPIO_OUTPUT);

  /* TMR2 Setup */
  SET_BIT(T2CON, T2CKPS1);
  SET_BIT(T2CON, T2CKPS0);
  CLR_BIT(T2CON, TMR2ON); // Ensure the timer is disabled initially

  /* CCP1 Setup */
  SET_BIT(CCPR1CON, CCPxM2_BIT);
  SET_BIT(CCPR1CON, CCPxM1_BIT);
}

void PWM_Enable(void) {
  SET_BIT(T2CON, TMR2ON); // Enable timer 2
}

void PWM_Disable(void) {
  CLR_BIT(T2CON, TMR2ON); // Disable timer 2
}

void PWM_SetDutyCycle(u16 DutyCycle) {
  CCPR1L = DutyCycle >> 2;
  u8 mask = (1U << CCPxX) | (1U << CCPxY);
  CCPR1CON = (CCPR1CON & ~(mask)) | ((DutyCycle << CCPxY) & mask);
}

void PWM_SetPeriod(u8 Period) { PR2 = Period; }
