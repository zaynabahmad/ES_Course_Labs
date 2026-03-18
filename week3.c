

#include "HAL/LM35/LM35_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/TMR0/TMR0_interface.h"
#include "SERVICES/STD_TYPES.h"


#define LM35_PORT        GPIO_PORTA
#define LM35_PIN         GPIO_PIN0    
#define LM35_ADC_CH      0u

#define VT_BAUD_RATE     9600u         
#define VT_TX_PORT       GPIO_PORTC
#define VT_TX_PIN        GPIO_PIN6     


extern void (*TMR0_Callback)(void);

#define INTCON          (*(volatile u8*)0x0B)
#define INTCON_T0IF     2
#define TMR0_REG        (*(volatile u8*)0x01)
#define TMR0_PRELOAD    131u

static volatile u8 Flag_PrintTemp = 0;

static void TMR0_1SecCallback(void)
{
    static u8 Local_TickCount = 0;

    Local_TickCount++;

    if (Local_TickCount >= 30u)
    {
        Local_TickCount = 0;
        Flag_PrintTemp  = 1;
    }
}

int main(void)
{
    float Local_Temperature;
    char  Local_TxtBuffer[15];

    LM35_Init();
    UART_Init();
    TMR0_SetCallback(TMR0_1SecCallback);
    TMR0_Init();
    TMR0_Enable();
    while (1)
    {
        if (Flag_PrintTemp == 1)
        {
            Flag_PrintTemp = 0;

            Local_Temperature = LM35_GetTemperature();
            FloatToStr(Local_Temperature, Local_TxtBuffer);

            UART_SendString("Temp = ");
            UART_SendString(Local_TxtBuffer);
            UART_SendString(" C");
            UART_SendNewLine();
        }
    }

    return 0;
}

void interrupt()
{
    if (INTCON & (1 << INTCON_T0IF))
    {
        TMR0_REG = TMR0_PRELOAD;           
        INTCON  &= ~(1 << INTCON_T0IF);   

        if (TMR0_Callback != NULL_PTR)
            TMR0_Callback();               
    }
}