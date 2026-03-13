
_TIMER0_Init:

;TIMER0_program.c,8 :: 		void TIMER0_Init(u8 Mode, u8 PrescalerEnable, u8 PrescalerValue)
;TIMER0_program.c,10 :: 		CLR_BIT(OPTION_REG, T0CS); // internal clock
	MOVLW      223
	ANDWF      129, 1
;TIMER0_program.c,12 :: 		if(PrescalerEnable) CLR_BIT(OPTION_REG, PSA);
	MOVF       FARG_TIMER0_Init_PrescalerEnable+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_TIMER0_Init0
	MOVLW      247
	ANDWF      129, 1
	GOTO       L_TIMER0_Init1
L_TIMER0_Init0:
;TIMER0_program.c,13 :: 		else SET_BIT(OPTION_REG, PSA);
	BSF        129, 3
L_TIMER0_Init1:
;TIMER0_program.c,15 :: 		OPTION_REG &= 0xF8;
	MOVLW      248
	ANDWF      129, 1
;TIMER0_program.c,16 :: 		OPTION_REG |= (PrescalerValue & 0x07);
	MOVLW      7
	ANDWF      FARG_TIMER0_Init_PrescalerValue+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	IORWF      129, 1
;TIMER0_program.c,18 :: 		TMR0 = 0;
	CLRF       1
;TIMER0_program.c,19 :: 		T0IE_bit = 0; // disable interrupt
	BCF        T0IE_bit+0, BitPos(T0IE_bit+0)
;TIMER0_program.c,20 :: 		}
L_end_TIMER0_Init:
	RETURN
; end of _TIMER0_Init

_TIMER0_Start:

;TIMER0_program.c,22 :: 		void TIMER0_Start(void)
;TIMER0_program.c,24 :: 		T0IE_bit = 1; // enable interrupt
	BSF        T0IE_bit+0, BitPos(T0IE_bit+0)
;TIMER0_program.c,25 :: 		}
L_end_TIMER0_Start:
	RETURN
; end of _TIMER0_Start

_TIMER0_Stop:

;TIMER0_program.c,27 :: 		void TIMER0_Stop(void)
;TIMER0_program.c,29 :: 		T0IE_bit = 0; // disable interrupt
	BCF        T0IE_bit+0, BitPos(T0IE_bit+0)
;TIMER0_program.c,30 :: 		}
L_end_TIMER0_Stop:
	RETURN
; end of _TIMER0_Stop

_TIMER0_SetValue:

;TIMER0_program.c,32 :: 		void TIMER0_SetValue(u8 Value)
;TIMER0_program.c,34 :: 		TMR0 = Value;
	MOVF       FARG_TIMER0_SetValue_Value+0, 0
	MOVWF      1
;TIMER0_program.c,35 :: 		}
L_end_TIMER0_SetValue:
	RETURN
; end of _TIMER0_SetValue

_TIMER0_GetValue:

;TIMER0_program.c,37 :: 		u8 TIMER0_GetValue(void)
;TIMER0_program.c,39 :: 		return TMR0;
	MOVF       1, 0
	MOVWF      R0+0
;TIMER0_program.c,40 :: 		}
L_end_TIMER0_GetValue:
	RETURN
; end of _TIMER0_GetValue

_TIMER0_SetCallback:

;TIMER0_program.c,42 :: 		void TIMER0_SetCallback(void (*Callback)(void))
;TIMER0_program.c,44 :: 		TIMER0_Callback = Callback;
	MOVF       FARG_TIMER0_SetCallback_Callback+0, 0
	MOVWF      _TIMER0_Callback+0
	MOVF       FARG_TIMER0_SetCallback_Callback+1, 0
	MOVWF      _TIMER0_Callback+1
	MOVF       FARG_TIMER0_SetCallback_Callback+2, 0
	MOVWF      _TIMER0_Callback+2
	MOVF       FARG_TIMER0_SetCallback_Callback+3, 0
;TIMER0_program.c,45 :: 		}
L_end_TIMER0_SetCallback:
	RETURN
; end of _TIMER0_SetCallback
