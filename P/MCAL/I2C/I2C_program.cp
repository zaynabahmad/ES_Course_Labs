#line 1 "E:/Drivers/P/MCAL/I2C/I2C_program.c"
#line 1 "e:/drivers/p/mcal/i2c/i2c_interface.h"



void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(char d);
char I2C_Read(char ack);
#line 9 "E:/Drivers/P/MCAL/I2C/I2C_program.c"
void I2C_Init(void)
{
 TRISC3_bit = 1;
 TRISC4_bit = 1;

 SSPCON = 0x28;
 SSPSTAT = 0x00;
}


void I2C_Start(void)
{
 SEN_bit = 1;
 while (SEN_bit);
}


void I2C_Stop(void)
{
 PEN_bit = 1;
 while (PEN_bit);
}


void I2C_Write(char d)
{
 SSPBUF = d;
 while (!SSPIF_bit);
 SSPIF_bit = 0;
}
#line 43 "E:/Drivers/P/MCAL/I2C/I2C_program.c"
char I2C_Read(char ack)
{
 RCEN_bit = 1;
 while (!SSPIF_bit);
 SSPIF_bit = 0;

 ACKDT_bit = (ack ? 0 : 1);
 ACKEN_bit = 1;
 while (ACKEN_bit);

 return SSPBUF;
}
