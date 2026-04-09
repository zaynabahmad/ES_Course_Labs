#include "ext_int.h"
#include "bit_math.h"

void EXT_INT_Init(void)
{
    /* Set edge trigger */
    #if EXT_INT_TRIGGER_EDGE == EXT_INT_RISING_EDGE
        SET_BIT(OPTION_REG, 6);   /* INTEDG = 1 ? rising edge  */
    #else
        CLR_BIT(OPTION_REG, 6);   /* INTEDG = 0 ? falling edge */
    #endif

    EXT_INT_ClearFlag();          /* Clear any pending flag     */
    EXT_INT_Enable();             /* Enable INT0                */
}

void EXT_INT_Enable(void)
{
    SET_BIT(INTCON, 4);           /* INT0IE = 1 */
    SET_BIT(INTCON, 7);           /* GIE    = 1 */
}

void EXT_INT_Disable(void)
{
    CLR_BIT(INTCON, 4);           /* INT0IE = 0 */
}

void EXT_INT_ClearFlag(void)
{
    CLR_BIT(INTCON, 1);           /* INT0IF = 0 */
}
uint8 EXT_INT_GetFlag(void)
{
    return GET_BIT(INTCON, 1);
}