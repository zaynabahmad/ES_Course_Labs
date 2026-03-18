#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/EXT_int/EXT_INT_interface.h"
#include "MCAL/EXT_int/EXT_INT_private.h"
#include "MCAL/PWM/PWM_interface.h"

#define HBRIDGE_DIR_PORT     GPIO_PORTC
#define HBRIDGE_DIR_PIN      GPIO_PIN3

#define SWITCH_PORT          GPIO_PORTB
#define SWITCH_PIN           GPIO_PIN0    

#define INTCON               (*(volatile u8*)0x0B)
#define INTCON_INTF          1


extern void (*EXT_INT0_Callback)(void);

int main(void)
{

    GPIO_Init();

    GPIO_SetPinDirection(HBRIDGE_DIR_PORT, HBRIDGE_DIR_PIN, GPIO_OUTPUT);
    GPIO_SetPinValue(HBRIDGE_DIR_PORT, HBRIDGE_DIR_PIN, GPIO_HIGH);

    PWM_Init();

    EXT_INT0_SetCallback(PWM_NextDutyLevel);

    EXT_INT0_Init();

    EXT_INT0_Enable();

    while (1)
    {
    }

    return 0;
}


void interrupt()
{
    if (INTCON & (1 << INTCON_INTF))
    {
        INTCON &= ~(1 << INTCON_INTF);    

        if (EXT_INT0_Callback != NULL_PTR)
            EXT_INT0_Callback();           
    }
}