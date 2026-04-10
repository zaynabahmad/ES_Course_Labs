#include "TIMER_INTERFACE.h"
void Timer0_initialize()
{
 OPTION_REG |= 0x07;  //PRE-SCALE P0,P1,P2
 CLR_BIT(OPTION_REG,3); //PSA
 CLR_BIT(OPTION_REG,5); //T0CS
 CLR_BIT(INTCON,2); //T0IF
 TMR0=0;
}
void Timer0_Enable(void)
{
    SET_BIT(INTCON,5);   // T0IE
    SET_BIT(INTCON,7);   // GIE
}
void Timer0_Disable(void)
{
    CLR_BIT(INTCON,5);   // T0IE
}
static void (*TMR0_Callback)(void) = 0;

void TMR0_SetCallback(void (*ptr)(void))
{
    TMR0_Callback = ptr;
    }
    

void Timer0_Reset(){
TMR0=0;

}
void Timer0_Set(u8 value){
TMR0=value;

}



u8 Tmr_get_flag(){
return GET_BIT(INTCON,2);
}
void Tmr_set_flag(){

SET_BIT(INTCON,2);
}
void Tmr_clr_flag(){
CLR_BIT(INTCON,2);

}


/*void interrupt(){
if(GET_BIT(INTCON,2)==1){
CLR_BIT(INTCON,2);
if(overflow_count1<30){
TMR0=0;
overflow_count1++;

}
else if(overflow_count1==30){
TMR0=125;
overflow_count1=0;
overflow_count2++;
//Task1
if(overflow_conut2==2){
//Task2
overflow_conut2=0;
}
}       */
void interrupt(){
if(GET_BIT(INTCON,2)==1){
CLR_BIT(INTCON,2);
if(TMR0_Callback){
TMR0_Callback();

}

}

}