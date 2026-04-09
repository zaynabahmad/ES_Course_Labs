#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../SERVICES/BIT_MATH.h"
#include "../SERVICES/STD_TYPES.h"

/* Timer0 Hardware Registers */
#define OPTION_REG  (*((volatile uint8*)0x81))
#define INTCON      (*((volatile uint8*)0x0B))
#define TMR0        (*((volatile uint8*)0x01))

/* Global variables */
volatile uint16 sys_ticks = 0;
volatile uint8 flag_1sec = 0;
volatile uint8 flag_2sec = 0;

void interrupt(void) 
{
    /* Check if Timer0 overflow caused the interrupt */
    if (GET_BIT(INTCON, 2)) 
    {
        TMR0 = 6;               /* Reload preload value for 1ms */
        CLR_BIT(INTCON, 2);     /* Clear the flag */
        
        sys_ticks++;
        
        /* Instead of calling LED functions here, just set flags! */
        if (sys_ticks % 1000 == 0) 
        {
            flag_1sec = 1;
        }
        
        if (sys_ticks % 2000 == 0) 
        {
            flag_2sec = 1;
            sys_ticks = 0;      
        }
    }
}

void main() 
{
    /* 1. Initialize LEDs (This happens in the main thread) */
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);
    
    LED_Off(GPIO_PORTB, GPIO_PIN1);
    LED_Off(GPIO_PORTB, GPIO_PIN2);
    
    /* 2. Initialize Timer0 */
    OPTION_REG &= 0xC0;       
    OPTION_REG |= 0x02;       
    CLR_BIT(OPTION_REG, 5);   
    CLR_BIT(OPTION_REG, 3);   
    
    TMR0 = 6;                 
    
    CLR_BIT(INTCON, 2);       
    SET_BIT(INTCON, 5);       
    SET_BIT(INTCON, 7);       
    
    /* 3. The Super Loop */
    while(1) 
    {
        /* Now the HAL/MCAL functions are ONLY called from main! */
        if (flag_1sec == 1)
        {
            LED_Toggle(GPIO_PORTB, GPIO_PIN2);
            flag_1sec = 0; /* Reset flag after doing the work */
        }

        if (flag_2sec == 1)
        {
            LED_Toggle(GPIO_PORTB, GPIO_PIN1);
            flag_2sec = 0; /* Reset flag after doing the work */
        }
    }
}