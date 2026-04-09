
_ADC_Init:

;adc_program.c,6 :: 		void ADC_Init(void)
;adc_program.c,9 :: 		SET_BIT(ADCON1_REG, ADFM_BIT);
	BSF        159, 7
;adc_program.c,12 :: 		CLR_BIT(ADCON1_REG, ADCS2_BIT);
	BCF        159, 6
;adc_program.c,13 :: 		SET_BIT(ADCON0_REG, ADCS1_BIT);
	BSF        31, 7
;adc_program.c,14 :: 		CLR_BIT(ADCON0_REG, ADCS0_BIT);
	BCF        31, 6
;adc_program.c,17 :: 		SET_BIT(ADCON0_REG, ADON_BIT);
	BSF        31, 0
;adc_program.c,18 :: 		}
L_end_ADC_Init:
	RETURN
; end of _ADC_Init

_ADC_Read:

;adc_program.c,20 :: 		u16 ADC_Read(u8 channel)
;adc_program.c,22 :: 		u8 local_u8Counter = 0;
	CLRF       ADC_Read_local_u8Counter_L0+0
;adc_program.c,26 :: 		CLR_BIT(ADCON0_REG, CHS0_BIT);
	BCF        31, 3
;adc_program.c,27 :: 		CLR_BIT(ADCON0_REG, CHS1_BIT);
	BCF        31, 4
;adc_program.c,28 :: 		CLR_BIT(ADCON0_REG, CHS2_BIT);
	BCF        31, 5
;adc_program.c,31 :: 		if(channel & 0x01) SET_BIT(ADCON0_REG, CHS0_BIT);
	BTFSS      FARG_ADC_Read_channel+0, 0
	GOTO       L_ADC_Read0
	BSF        31, 3
L_ADC_Read0:
;adc_program.c,32 :: 		if(channel & 0x02) SET_BIT(ADCON0_REG, CHS1_BIT);
	BTFSS      FARG_ADC_Read_channel+0, 1
	GOTO       L_ADC_Read1
	BSF        31, 4
L_ADC_Read1:
;adc_program.c,33 :: 		if(channel & 0x04) SET_BIT(ADCON0_REG, CHS2_BIT);
	BTFSS      FARG_ADC_Read_channel+0, 2
	GOTO       L_ADC_Read2
	BSF        31, 5
L_ADC_Read2:
;adc_program.c,36 :: 		for(local_u8Counter = 0; local_u8Counter < 20; local_u8Counter++)
	CLRF       ADC_Read_local_u8Counter_L0+0
L_ADC_Read3:
	MOVLW      20
	SUBWF      ADC_Read_local_u8Counter_L0+0, 0
	BTFSC      STATUS+0, 0
	GOTO       L_ADC_Read4
	INCF       ADC_Read_local_u8Counter_L0+0, 1
;adc_program.c,39 :: 		}
	GOTO       L_ADC_Read3
L_ADC_Read4:
;adc_program.c,42 :: 		SET_BIT(ADCON0_REG, GO_DONE_BIT);
	BSF        31, 2
;adc_program.c,45 :: 		while(GET_BIT(ADCON0_REG, GO_DONE_BIT) == 1)
L_ADC_Read6:
	MOVF       31, 0
	MOVWF      R0+0
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	MOVLW      1
	ANDWF      R0+0, 0
	MOVWF      R1+0
	MOVF       R1+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_ADC_Read7
;adc_program.c,48 :: 		}
	GOTO       L_ADC_Read6
L_ADC_Read7:
;adc_program.c,51 :: 		result = ((u16)ADRESH_REG << 8) | ADRESL_REG;
	MOVF       158, 0
	MOVWF      R0+0
;adc_program.c,53 :: 		return result;
;adc_program.c,54 :: 		}
L_end_ADC_Read:
	RETURN
; end of _ADC_Read
