#line 1 "D:/mikroC PRO for PIC/Examples/MCAL/ADC/ADC_program.c"










void ADC_voidInit(void)
{

 SET_BIT(ADMUX, 6);


 SET_BIT(ADCSRA, ADEN);


 SET_BIT(ADCSRA, 0);
 SET_BIT(ADCSRA, 1);
 SET_BIT(ADCSRA, 2);
}

u16 ADC_u16ReadChannel(u8 channel)
{

 ADMUX &= 0b11100000;
 ADMUX |= channel;


 SET_BIT(ADCSRA, ADSC);


 while(GET_BIT(ADCSRA, ADIF) == 0);


 SET_BIT(ADCSRA, ADIF);


 u16 result = ADCL;
 result |= (ADCH << 8);

 return result;
}
