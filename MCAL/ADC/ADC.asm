
_ADC_Init:

;ADC.c,5 :: 		void ADC_Init(void) {
;ADC.c,7 :: 		ADCON1 = 0x80;
	MOVLW      128
	MOVWF      159
;ADC.c,10 :: 		SET_BIT(ADCON0, ADON);
	BSF        31, 0
;ADC.c,11 :: 		}
L_end_ADC_Init:
	RETURN
; end of _ADC_Init

_ADC_ReadChannel:

;ADC.c,13 :: 		u16 ADC_ReadChannel(u8 Channel) {
;ADC.c,14 :: 		u16 result = 0;
;ADC.c,17 :: 		ADCON0 &= 0xC7;
	MOVLW      199
	ANDWF      31, 1
;ADC.c,18 :: 		ADCON0 |= (Channel << 3);
	MOVF       FARG_ADC_ReadChannel_Channel+0, 0
	MOVWF      R0+0
	RLF        R0+0, 1
	BCF        R0+0, 0
	RLF        R0+0, 1
	BCF        R0+0, 0
	RLF        R0+0, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	IORWF      31, 1
;ADC.c,23 :: 		SET_BIT(ADCON0, GO_DONE);
	BSF        31, 2
;ADC.c,26 :: 		while (GET_BIT(ADCON0, GO_DONE) == 1);
L_ADC_ReadChannel0:
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
	GOTO       L_ADC_ReadChannel1
	GOTO       L_ADC_ReadChannel0
L_ADC_ReadChannel1:
;ADC.c,29 :: 		result = ((u16)ADRESH << 8) | ADRESL;
	MOVF       158, 0
	MOVWF      R0+0
;ADC.c,31 :: 		return result;
;ADC.c,32 :: 		}
L_end_ADC_ReadChannel:
	RETURN
; end of _ADC_ReadChannel
