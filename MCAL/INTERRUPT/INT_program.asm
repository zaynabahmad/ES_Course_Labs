
_EXT_INT_Init:

;INT_program.c,8 :: 		void EXT_INT_Init(u8 Edge)
;INT_program.c,10 :: 		if(Edge == RISING_EDGE)
	MOVF       FARG_EXT_INT_Init_Edge+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_EXT_INT_Init0
;INT_program.c,11 :: 		SET_BIT(OPTION_REG , 6);   // INTEDG
	BSF        OPTION_REG+0, 6
	GOTO       L_EXT_INT_Init1
L_EXT_INT_Init0:
;INT_program.c,13 :: 		CLR_BIT(OPTION_REG , 6);
	MOVLW      191
	ANDWF      OPTION_REG+0, 1
L_EXT_INT_Init1:
;INT_program.c,14 :: 		}
L_end_EXT_INT_Init:
	RETURN
; end of _EXT_INT_Init

_EXT_INT_Enable:

;INT_program.c,16 :: 		void EXT_INT_Enable(void)
;INT_program.c,18 :: 		SET_BIT(INTCON , 4);   // INTE
	BSF        INTCON+0, 4
;INT_program.c,19 :: 		}
L_end_EXT_INT_Enable:
	RETURN
; end of _EXT_INT_Enable

_EXT_INT_Disable:

;INT_program.c,21 :: 		void EXT_INT_Disable(void)
;INT_program.c,23 :: 		CLR_BIT(INTCON , 4);
	MOVLW      239
	ANDWF      INTCON+0, 1
;INT_program.c,24 :: 		}
L_end_EXT_INT_Disable:
	RETURN
; end of _EXT_INT_Disable

_EXT_INT_SetCallback:

;INT_program.c,26 :: 		void EXT_INT_SetCallback(void (*Callback)(void))
;INT_program.c,28 :: 		EXT0_Callback = Callback;
	MOVF       FARG_EXT_INT_SetCallback_Callback+0, 0
	MOVWF      INT_program_EXT0_Callback+0
	MOVF       FARG_EXT_INT_SetCallback_Callback+1, 0
	MOVWF      INT_program_EXT0_Callback+1
	MOVF       FARG_EXT_INT_SetCallback_Callback+2, 0
	MOVWF      INT_program_EXT0_Callback+2
	MOVF       FARG_EXT_INT_SetCallback_Callback+3, 0
;INT_program.c,29 :: 		}
L_end_EXT_INT_SetCallback:
	RETURN
; end of _EXT_INT_SetCallback

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;INT_program.c,31 :: 		void interrupt()
;INT_program.c,35 :: 		if(INTF_bit && EXT0_Callback != NULL_PTR)
	BTFSS      INTCON+0, 1
	GOTO       L_interrupt4
	MOVF       INT_program_EXT0_Callback+0, 0
	MOVWF      R1+0
	MOVF       INT_program_EXT0_Callback+1, 0
	MOVWF      R1+1
	MOVF       INT_program_EXT0_Callback+2, 0
	MOVWF      R1+2
	MOVF       INT_program_EXT0_Callback+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt14
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt14
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt14
	MOVF       R1+0, 0
	XORLW      0
L__interrupt14:
	BTFSC      STATUS+0, 2
	GOTO       L_interrupt4
L__interrupt7:
;INT_program.c,37 :: 		INTF_bit = 0;
	BCF        INTCON+0, 1
;INT_program.c,38 :: 		EXT0_Callback();
	MOVF       INT_program_EXT0_Callback+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       INT_program_EXT0_Callback+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;INT_program.c,39 :: 		}
L_interrupt4:
;INT_program.c,43 :: 		if(T0IF_bit)
	BTFSS      T0IF_bit+0, BitPos(T0IF_bit+0)
	GOTO       L_interrupt5
;INT_program.c,45 :: 		T0IF_bit = 0;
	BCF        T0IF_bit+0, BitPos(T0IF_bit+0)
;INT_program.c,47 :: 		if(TIMER0_Callback != NULL_PTR)
	MOVF       _TIMER0_Callback+0, 0
	MOVWF      R1+0
	MOVF       _TIMER0_Callback+1, 0
	MOVWF      R1+1
	MOVF       _TIMER0_Callback+2, 0
	MOVWF      R1+2
	MOVF       _TIMER0_Callback+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt15
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt15
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt15
	MOVF       R1+0, 0
	XORLW      0
L__interrupt15:
	BTFSC      STATUS+0, 2
	GOTO       L_interrupt6
;INT_program.c,49 :: 		TIMER0_Callback();
	MOVF       _TIMER0_Callback+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       _TIMER0_Callback+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;INT_program.c,50 :: 		}
L_interrupt6:
;INT_program.c,51 :: 		}
L_interrupt5:
;INT_program.c,52 :: 		}
L_end_interrupt:
L__interrupt13:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt

INT_program____?ag:

L_end_INT_program___?ag:
	RETURN
; end of INT_program____?ag
