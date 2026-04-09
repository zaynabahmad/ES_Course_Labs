#include "SPI_Test.h"
#include "../../MCAL/SPI/SPI_Interface.h"
#include "../../HAL/LED/LED_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

/* Commands for SPI */
#define CMD_LED_ON      0x11
#define CMD_LED_OFF     0x22
#define CMD_LED_TOGGLE  0x33

#define SLAVE_LED_PORT  GPIO_PORTC
#define SLAVE_LED_PIN   GPIO_PIN0

/* Delay function for Master transmission interval */
static void SPI_Test_Delay(u32 count)
{
    while(count--)
    {
        /* delay loop */
    }
}

void SPI_Test_Init(void)
{
#if (SPI_TEST_ROLE == SPI_TEST_ROLE_MASTER)
    /* --- Master Initialization --- */
    
    /* Config SPI Pins for Master: SCK (RC3)=Output, SDI (RC4)=Input, SDO (RC5)=Output */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_OUTPUT);
    
    /* Ensure the SPI Config file is set to Master appropriately */
    SPI_Init();
    
#elif (SPI_TEST_ROLE == SPI_TEST_ROLE_SLAVE)
    /* --- Slave Initialization --- */
    
    /* Config SPI Pins for Slave: SCK (RC3)=Input, SDI (RC4)=Input, SDO (RC5)=Output, SS (RA5)=Input */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN5, GPIO_INPUT);
    
    /* Ensure the SPI Config file is set to Slave appropriately */
    SPI_Init();
    
    /* Init Status LED to verify data reception */
    LED_Init(SLAVE_LED_PORT, SLAVE_LED_PIN);
#endif
}

void SPI_Test_App(void)
{
#if (SPI_TEST_ROLE == SPI_TEST_ROLE_MASTER)
    /* --- Master Execution --- */
    
    /* Sequence: Send ON -> delay -> OFF -> delay -> TOGGLE -> delay */
    SPI_Transfer(CMD_LED_ON);
    SPI_Test_Delay(100000);
    
    SPI_Transfer(CMD_LED_OFF);
    SPI_Test_Delay(100000);
    
    SPI_Transfer(CMD_LED_TOGGLE);
    SPI_Test_Delay(100000);
    
#elif (SPI_TEST_ROLE == SPI_TEST_ROLE_SLAVE)
    /* --- Slave Execution --- */
    
    u8 received_cmd = 0;
    
    /* Wait for Master to send data (SPI_Transfer blocks until BF is set) */
    received_cmd = SPI_Transfer(0xFF);
    
    /* Process the received command */
    if (received_cmd == CMD_LED_ON)
    {
        LED_On(SLAVE_LED_PORT, SLAVE_LED_PIN);
    }
    else if (received_cmd == CMD_LED_OFF)
    {
        LED_Off(SLAVE_LED_PORT, SLAVE_LED_PIN);
    }
    else if (received_cmd == CMD_LED_TOGGLE)
    {
        LED_Toggle(SLAVE_LED_PORT, SLAVE_LED_PIN);
    }
#endif
}
