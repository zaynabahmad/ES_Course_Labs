#line 1 "D:/mikroC PRO for PIC/Examples/MCAL/SPI/SPI_program.c"







void SPI_voidInitMaster(void)
{

 SET_BIT(SPCR, SPE);


 SET_BIT(SPCR, MSTR);


 CLR_BIT(SPCR, 0);
 SET_BIT(SPCR, 1);
}

void SPI_voidInitSlave(void)
{

 SET_BIT(SPCR, SPE);


 CLR_BIT(SPCR, MSTR);
}

u8 SPI_u8SendReceive(u8 data)
{

 SPDR = data;


 while(GET_BIT(SPSR, SPIF) == 0);


 return SPDR;
}
