#include "USART_interface.h"

void (*UART_Callback) (u8)=0;

void UART_TX_init(){

         SET_BIT(TXSTA,BRGH);
         SPBRG=25;
         CLR_BIT(TXSTA,SYNC);
         CLR_BIT(RCSTA,SPEN);
         SET_BIT(TXSTA,TXEN);

}
void UART_RX_init(){
         SET_BIT(TXSTA,BRGH);
         SPBRG=25;
         CLR_BIT(TXSTA,SYNC);
         CLR_BIT(RCSTA,SPEN);
         SET_BIT(RCSTA,CREN);
         SET_BIT(PIE1,RCIE);
         SET_BIT(INTCON,PEIE);
         SET_BIT(INTCON,GIE);




}
void UART_Write(u8 bits){

        while(!GET_BIT(TXSTA,TRMT));
        TXREG=bits;




}
u8 UART_Read(){
while(!GET_BIT(PIR1,RCREG));
return RCREG;


}
void UART_SetCallback(void (*callback)(u8))
{
    if(callback!=0){
    UART_Callback = callback;
    }
    
    
}
void UART_ISR(void){
     u8 bits=RCREG;
     CLR_BIT(PIR1,RCIF);
     if(UART_Callback!=0){
     UART_Callback(bits);
     }
     
}