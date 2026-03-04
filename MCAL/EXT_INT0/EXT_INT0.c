#include "../GPIO/GPIO_interface.h"
#include "EXT_INT0_config.h"
#include "EXT_INT0_interface.h"
#include "EXT_INT0_private.h"

#include "../../SERVICES/BIT_MATH.h"

void EXT_INT0_Init(void) {
  GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
  EXT_INT0_SetEdge(INTEDG_RISING);
  CLR_BIT(INTCON, INTE);
  CLR_BIT(INTCON, GIE);
  CLR_BIT(INTCON, INTF);
}
void EXT_INT0_Enable(void) {
  SET_BIT(INTCON, GIE);
  SET_BIT(INTCON, INTE);
  CLR_BIT(INTCON, INTF);
}
void EXT_INT0_Disable(void) {
  CLR_BIT(INTCON, GIE);
  CLR_BIT(INTCON, INTE);
  CLR_BIT(INTCON, INTF);
}
void EXT_INT0_SetEdge(u8 edge_type) {
  switch (edge_type) {
  case INTEDG_RISING:
    SET_BIT(OPTION_REG, INTEDG);
    break;
  case INTEDG_FALLING:
    CLR_BIT(OPTION_REG, INTEDG);
    break;
  }
}

static void (*EXT_INT0_Callback)(void) = 0;
void EXT_INT0_SetCallback(void (*ptr)(void)) { EXT_INT0_Callback = ptr; }

void interrupt() {
  if (GET_BIT(INTCON, INTF)) {
    EXT_INT0_Callback();
    CLR_BIT(INTCON, INTF);
  }
}
