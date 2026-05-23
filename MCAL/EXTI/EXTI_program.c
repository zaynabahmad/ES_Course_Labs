#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\STD_TYPES.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\BIT_MATH.h"

#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\EXTI\EXTI_private.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\EXTI\EXTI_interface.h"

void EXTI_voidEnable(void)
{
    SET_BIT(INTCON,7); // GIE
    SET_BIT(INTCON,4); // INTE
}