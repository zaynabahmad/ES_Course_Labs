
_ADC_voidInit:

;ADC_program.c,7 :: 		void ADC_voidInit(void)
;ADC_program.c,9 :: 		ADCON1 = ADC_ADCON1_CONFIG;
	MOVLW      142
	MOVWF      159
;ADC_program.c,11 :: 		ADCON0 = 0x00;
	CLRF       31
;ADC_program.c,13 :: 		ADCON0 |= (unsigned char)(ADC_CLK_FOSC_8 << ADC_ADCS_SHIFT);
	BSF        31, 6
;ADC_program.c,15 :: 		SET_BIT(ADCON0, ADC_ADON_BIT);
	BSF        31, 0
;ADC_program.c,16 :: 		}
L_end_ADC_voidInit:
	RETURN
; end of _ADC_voidInit

_ADC_u16Read:

;ADC_program.c,19 :: 		unsigned int ADC_u16Read(unsigned char channel)
;ADC_program.c,25 :: 		if (channel > ADC_MAX_CHANNEL)
	MOVF       FARG_ADC_u16Read_channel+0, 0
	SUBLW      7
	BTFSC      STATUS+0, 0
	GOTO       L_ADC_u16Read0
;ADC_program.c,27 :: 		return ADC_INVALID_CHANNEL;
	MOVLW      255
	MOVWF      R0+0
	MOVLW      255
	MOVWF      R0+1
	GOTO       L_end_ADC_u16Read
;ADC_program.c,28 :: 		}
L_ADC_u16Read0:
;ADC_program.c,30 :: 		ADCON0 &= ADC_CHANNEL_MASK;
	MOVLW      199
	ANDWF      31, 1
;ADC_program.c,31 :: 		ADCON0 |= (unsigned char)(channel << ADC_CHS_SHIFT);
	MOVF       FARG_ADC_u16Read_channel+0, 0
	MOVWF      R0+0
	RLF        R0+0, 1
	BCF        R0+0, 0
	RLF        R0+0, 1
	BCF        R0+0, 0
	RLF        R0+0, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	IORWF      31, 1
;ADC_program.c,33 :: 		for (delay_cnt = 0; delay_cnt < ADC_ACQ_DELAY_COUNT; delay_cnt++)
	CLRF       R6+0
L_ADC_u16Read1:
	MOVLW      40
	SUBWF      R6+0, 0
	BTFSC      STATUS+0, 0
	GOTO       L_ADC_u16Read2
	INCF       R6+0, 1
;ADC_program.c,36 :: 		}
	GOTO       L_ADC_u16Read1
L_ADC_u16Read2:
;ADC_program.c,39 :: 		SET_BIT(ADCON0, ADC_GO_DONE_BIT);
	BSF        31, 2
;ADC_program.c,42 :: 		while (GET_BIT(ADCON0, ADC_GO_DONE_BIT))
L_ADC_u16Read4:
	MOVF       31, 0
	MOVWF      R1+0
	RRF        R1+0, 1
	BCF        R1+0, 7
	RRF        R1+0, 1
	BCF        R1+0, 7
	BTFSS      R1+0, 0
	GOTO       L_ADC_u16Read5
;ADC_program.c,45 :: 		}
	GOTO       L_ADC_u16Read4
L_ADC_u16Read5:
;ADC_program.c,48 :: 		result = (unsigned int)(((unsigned int)(ADRESH & 0x03u) << 8u)
	MOVLW      3
	ANDWF      30, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      R4+0
	CLRF       R4+1
	MOVF       R4+0, 0
	MOVWF      R2+1
	CLRF       R2+0
;ADC_program.c,49 :: 		| (unsigned int)ADRESL);
	MOVF       158, 0
	MOVWF      R0+0
	CLRF       R0+1
	MOVF       R2+0, 0
	IORWF      R0+0, 1
	MOVF       R2+1, 0
	IORWF      R0+1, 1
;ADC_program.c,51 :: 		return result;
;ADC_program.c,52 :: 		}
L_end_ADC_u16Read:
	RETURN
; end of _ADC_u16Read

_ADC_f32ToVoltage:

;ADC_program.c,55 :: 		float ADC_f32ToVoltage(unsigned int raw_value)
;ADC_program.c,58 :: 		return (float)raw_value * 4.8828f;
	MOVF       FARG_ADC_f32ToVoltage_raw_value+0, 0
	MOVWF      R0+0
	MOVF       FARG_ADC_f32ToVoltage_raw_value+1, 0
	MOVWF      R0+1
	CALL       _word2double+0
	MOVLW      230
	MOVWF      R4+0
	MOVLW      63
	MOVWF      R4+1
	MOVLW      28
	MOVWF      R4+2
	MOVLW      129
	MOVWF      R4+3
	CALL       _Mul_32x32_FP+0
;ADC_program.c,59 :: 		}
L_end_ADC_f32ToVoltage:
	RETURN
; end of _ADC_f32ToVoltage
