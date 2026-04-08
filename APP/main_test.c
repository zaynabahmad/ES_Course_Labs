#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

/* MCAL Includes */
#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../MCAL/INTERRUPT_MANAGER/Interrupt_Manager.c" /* Assuming you have this handling GIE/PEIE */
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/PWM/PWM_Interface.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/I2C/I2C_Interface.h"

/* =========================================================
   Test Global Variables
========================================================= */
volatile u8 g_Timer0_TickCount = 0;
volatile u8 g_Button_Pressed = 0;

/* =========================================================
   Helper Functions
========================================================= */
void UART_SendString(const char* str)
{
    while(*str != '\0')
    {
        UART_Write((u8)(*str));
        str++;
    }
}

/* =========================================================
   Interrupt Callbacks
========================================================= */

/* Called by Timer0 ISR every overflow */
void App_Timer0_Callback(void)
{
    g_Timer0_TickCount++;
    
    /* Test GPIO: Toggle an LED on PORTD, Pin 0 every ~500ms (assuming 50 ticks) */
    if(g_Timer0_TickCount >= 50)
    {
        /* Manual Toggle since GPIO_interface.h doesn't have a toggle function */
        if(GPIO_GetPinValue(GPIO_PORTD, GPIO_PIN0) == GPIO_HIGH)
        {
            GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN0, GPIO_LOW);
        }
        else
        {
            GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN0, GPIO_HIGH);
        }
        g_Timer0_TickCount = 0;
    }
}

/* Called by External Interrupt (RB0) ISR */
void App_EXT_Callback(void)
{
    g_Button_Pressed = 1;
}

/* =========================================================
   System Initialization
========================================================= */
void System_Init(void)
{
    /* 1. GPIO Setup */
    GPIO_Init(); 
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN0, GPIO_OUTPUT); /* Timer LED */
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN1, GPIO_OUTPUT); /* Button LED */
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);  /* EXT Button */
    
    /* 2. ADC Setup (Potentiometer on AN0) */
    ADC_Init();

    /* 3. PWM Setup (LED/Motor on CCP1 - RC2) */
    PWM_Init();
    PWM_Start(PWM_CHANNEL_1);

    /* 4. Communications Setup */
    UART_TX_Init();
    UART_RX_Init();
    SPI_Master_Init();
    I2C_Master_Init();

    /* 5. Timer0 Setup */
    TIMER0_Init();
    TIMER0_SetCallback(App_Timer0_Callback);
    TIMER0_Enable();

    /* 6. External Interrupt Setup */
    EXT_INT_Init();
    EXT_INT_SetEdge(falling_edge); /* Trigger on button press (assuming pull-up) */
    EXT_INT_SetCallback(App_EXT_Callback);
    EXT_INT_Enable();

    /* 7. Enable Global & Peripheral Interrupts 
       (Depends on your Interrupt Manager. TIMER0_Enable() sets GIE, 
        but ensure PEIE is set for ADC/UART/SPI if using interrupts there) */
    /* INTERRUPT_MANAGER_EnableGlobal(); */
    /* INTERRUPT_MANAGER_EnablePeripheral(); */
}

/* =========================================================
   Main Application Loop
========================================================= */
int main(void)
{
    u16 adc_value = 0;
    u8 pwm_duty = 0;
    u8 dummy_spi_data = 0;
    u8 i2c_ack_status = 0;

    /* Initialize all MCAL drivers */
    System_Init();

    /* Send boot message via USART */
    UART_SendString("System Initialized. Starting Tests...\r\n");

    while(1)
    {
        /* ---------------------------------------------------
           TEST 1: ADC to PWM Link
           Read analog value, convert to 0-100%, and update PWM
        --------------------------------------------------- */
        adc_value = ADC_ReadChannel(ADC_CHANNEL_0);
        
        /* Convert 10-bit ADC (0-1023) to percentage (0-100) */
        pwm_duty = (u8)(((u32)adc_value * 100) / 1023);
        PWM_SetDutyCycle(PWM_CHANNEL_1, pwm_duty);

        /* ---------------------------------------------------
           TEST 2: External Interrupt Notification
           If RB0 was pressed, toggle an LED and send UART msg
        --------------------------------------------------- */
        if(g_Button_Pressed == 1)
        {
            if(GPIO_GetPinValue(GPIO_PORTD, GPIO_PIN1) == GPIO_HIGH)
            {
                GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN1, GPIO_LOW);
            }
            else
            {
                GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN1, GPIO_HIGH);
            }

            UART_SendString("Button Pressed! EXT INT Working.\r\n");
            g_Button_Pressed = 0; /* Reset flag */
        }

        /* ---------------------------------------------------
           TEST 3: SPI & I2C Dummy Transfers
           Send a dummy byte over SPI and I2C periodically
        --------------------------------------------------- */
        if(g_Timer0_TickCount == 25) 
        {
            /* Send dummy byte over SPI (Full duplex: sends 0xAA, receives response) */
            dummy_spi_data = SPI_Transfer(0xAA);
            
            /* Send dummy data over I2C to a fake address (e.g., 0xA0) */
            I2C_Start();
            i2c_ack_status = I2C_Write(0xA0);  /* Device address + Write bit */
            if(i2c_ack_status == 0)            /* If slave ACK'd */
            {
                I2C_Write(pwm_duty);           /* Send current PWM duty as data */
            }
            I2C_Stop();
        }
    }

    return 0;
}