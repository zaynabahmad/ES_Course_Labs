

#include "../../MCAL/External_Interrupt_INT0/EXT_INT0.h"


void EXT_INT0_Init(void){

GPIO_SetPinDirection(GPIO_PORTB,GPIO_PIN0,GPIO_INPUT);
CLR_BIT(INTCON,1); //INTF
CLR_BIT(INTCON,4); //INTE
}
void EXT_INT0_Enable(void){
CLR_BIT(INTCON,1); //INTF
//INTE_bit=1;
SET_BIT(INTCON,4);
//GIE_bit=1;
SET_BIT(INTCON,7);
}
void EXT_INT0_Disable(void){

CLR_BIT(INTCON,4);    //INTE
CLR_BIT(INTCON,1);   //INTF

}
void EXT_INT0_SetEdge(u8 edge_type){
if(edge_type == 0) {
        SET_BIT(OPTION_REG, 6);  //INTEDG (Rising)
    } 
else if (edge_type==1){
        CLR_BIT(OPTION_REG, 6);  //INTEDG (Falling)
    }

}
static void (*EXT_INT0_Callback)(void) = 0;

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    EXT_INT0_Callback = ptr;
    }


void interrupt()
{
    if(GET_BIT(INTCON, 1)) {
        CLR_BIT(INTCON, 1);
        if(EXT_INT0_Callback) {
            EXT_INT0_Callback();
        }
    }
}