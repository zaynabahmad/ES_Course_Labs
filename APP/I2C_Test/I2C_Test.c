#include "I2C_Test.h"
#include "../../MCAL/I2C/I2C_Interface.h"
#include "../../HAL/LED/LED_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

/* Commands */
#define CMD_LED_ON      0x11
#define CMD_LED_OFF     0x22
#define CMD_LED_TOGGLE  0x33

#define SLAVE_LED_PORT  GPIO_PORTC
#define SLAVE_LED_PIN   GPIO_PIN0

#if (I2C_TEST_ROLE == I2C_TEST_ROLE_SLAVE)
/* Choose which slave this compiles for */
#define MY_SLAVE_ADDRESS  SLAVE_1_ADDRESS
#endif

/* Standard delay sequence for master tests */
static void I2C_Test_Delay(u32 count)
{
    while(count--)
    {
        /* delay loop */
    }
}

void I2C_Test_Init(void)
{
    /* I2C pins (RC3=SCL, RC4=SDA) must be configured as INPUT for the MSB I2C engine to control them */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);

#if (I2C_TEST_ROLE == I2C_TEST_ROLE_MASTER)
    /* --- Master Initialization --- */
    I2C_Master_Init();

#elif (I2C_TEST_ROLE == I2C_TEST_ROLE_SLAVE)
    /* --- Slave Initialization --- */
    I2C_Slave_Init(MY_SLAVE_ADDRESS);
    
    /* Config Status LED */
    LED_Init(SLAVE_LED_PORT, SLAVE_LED_PIN);
#endif
}

void I2C_Test_App(void)
{
#if (I2C_TEST_ROLE == I2C_TEST_ROLE_MASTER)
    /* --- Master Execution --- */
    
    /* Control Sequence for Slave 1 */
    /* 1. Turn ON LED */
    I2C_Start();
    I2C_Write(SLAVE_1_ADDRESS); /* Send SLA+W */
    I2C_Write(CMD_LED_ON);      /* Send Command */
    I2C_Stop();
    I2C_Test_Delay(100000);
    
    /* 2. Turn OFF LED */
    I2C_Start();
    I2C_Write(SLAVE_1_ADDRESS);
    I2C_Write(CMD_LED_OFF);
    I2C_Stop();
    I2C_Test_Delay(100000);
    
    /* 3. Toggle LED */
    I2C_Start();
    I2C_Write(SLAVE_1_ADDRESS);
    I2C_Write(CMD_LED_TOGGLE);
    I2C_Stop();
    I2C_Test_Delay(100000);

#elif (I2C_TEST_ROLE == I2C_TEST_ROLE_SLAVE)
    /* --- Slave Execution --- */
    
    u8 received_data;
    
    /* Wait and block until communication occurs (Address Match or Data) */
    received_data = I2C_Slave_Read();
    
    /* In PIC16 I2C polling mode, the first byte received in SSPBUF after START is the Address match byte.
       The match is verified by hardware. Reading the buffer acknowledges it and releases clock stretching. */
    if (received_data == MY_SLAVE_ADDRESS)
    {
        /* Now wait and block for the actual data byte (Command) */
        received_data = I2C_Slave_Read();
        
        switch (received_data)
        {
            case CMD_LED_ON:
                LED_On(SLAVE_LED_PORT, SLAVE_LED_PIN);
                break;
            case CMD_LED_OFF:
                LED_Off(SLAVE_LED_PORT, SLAVE_LED_PIN);
                break;
            case CMD_LED_TOGGLE:
                LED_Toggle(SLAVE_LED_PORT, SLAVE_LED_PIN);
                break;
            default:
                break;
        }
    }
#endif
}
