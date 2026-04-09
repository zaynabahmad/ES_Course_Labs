#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"

void EXTI_voidEnable(void)
{
    SET_BIT(INTCON,7); // GIE
    SET_BIT(INTCON,4); // INTE
}