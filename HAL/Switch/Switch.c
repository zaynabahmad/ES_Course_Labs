#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "Switch_Interface.h"
#include "Switch_Private.h"

/* Arrays for indirect register access */
static volatile u8* const TRIS_REGS[] = {&TRISA_REG, &TRISB_REG, &TRISC_REG, &TRISD_REG};
static volatile u8* const PORT_REGS[] = {&PORTA_REG, &PORTB_REG, &PORTC_REG, &PORTD_REG};

/* =========================================================
   SW_voidInit
========================================================= */
void SW_voidInit(const SW_Type* Copy_pswSwitch)
{
    if (Copy_pswSwitch != NULL && Copy_pswSwitch->Port <= SW_PORTD)
    {
        /* Set direction as Input (1 for PIC TRIS) */
        SET_BIT(*(TRIS_REGS[Copy_pswSwitch->Port]), Copy_pswSwitch->Pin);

        /* Note: PIC16F877A only has internal pull-ups on PORTB.
           If using PORTB and Active Low, pull-ups must be enabled via OPTION_REG.
        */
    }
}

/* =========================================================
   SW_stGetState
========================================================= */
SW_Status_t SW_stGetState(const SW_Type* Copy_pswSwitch)
{
    SW_Status_t Local_stState = SW_RELEASED;
    u8 Local_u8BitValue;

    if (Copy_pswSwitch != NULL && Copy_pswSwitch->Port <= SW_PORTD)
    {
        /* Read the pin value */
        Local_u8BitValue = GET_BIT(*(PORT_REGS[Copy_pswSwitch->Port]), Copy_pswSwitch->Pin);

        /* Logic for Active Low: Pressed if bit is 0
           Logic for Active High: Pressed if bit is 1
        */
        if (Copy_pswSwitch->Logic == SW_ACTIVE_LOW)
        {
            if (Local_u8BitValue == 0) { Local_stState = SW_PRESSED; }
        }
        else /* SW_ACTIVE_HIGH */
        {
            if (Local_u8BitValue == 1) { Local_stState = SW_PRESSED; }
        }
    }

    return Local_stState;
}