#include "INT_private.h"
#include "INT_interface.h"
#include "INT_config.h"
#include "GPIO_interface.h"
#include "BIT_MATH.h"

//PTR to a function which takes no inputs & returns void
//Its global, static & intialized to zeros so stored in  .bss 
static void (*PTR_EXT_INTO_CALLBACK)(void) = 0;

void EXT_INTO_Init(void)
{
    GPIO_SetPinDirection(INT_PORT,INT_PIN,GPIO_INPUT);
    EXT_INTO_SetEdge(INT_EDGE_CONTROL);
}

void EXT_INTO_Enable(void)
{
    SET_BIT(INTCON,INTE);
    SET_BIT(INTCON,GIE);

}

void EXT_INTO_Disable(void)
{
    CLR_BIT(INTCON,INTE);
}

void EXT_INTO_SetEdge(u8 edge_type)
{
    if(edge_type == 1)
    {
        SET_BIT(OPTION_REG,INTEDG);

    }
    else if (edge_type == 0)
    {
        CLR_BIT(OPTION_REG,INTEDG);

    }
}

void EXT_INTO_SetCallback(void (*ptr)(void))
{
    PTR_EXT_INTO_CALLBACK = ptr; 
}


void __interrupt() ISR_ExtCall(void)
{

    //Checks to see if this interrupt is external
    if(GET_BIT(INTCON,INTF) == 1)
    {
        //Acknowledge that i am servicing interrupt by clearing INTF 
        CLR_BIT(INTCON,INTF);
        PTR_EXT_INTO_CALLBACK();

    }


}
