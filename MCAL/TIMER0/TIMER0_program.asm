
_TIMER0_voidInit:

;TIMER0_program.c,7 :: 		void TIMER0_voidInit(void) {
;TIMER0_program.c,9 :: 		OPTION_REG &= 0b11000000;
	MOVLW      192
	ANDWF      129, 1
;TIMER0_program.c,10 :: 		OPTION_REG |= 0b00000010;
	BSF        129, 1
;TIMER0_program.c,11 :: 		}
L_end_TIMER0_voidInit:
	RETURN
; end of _TIMER0_voidInit

_TIMER0_voidSetPreload:

;TIMER0_program.c,13 :: 		void TIMER0_voidSetPreload(unsigned char Copy_u8Preload) {
;TIMER0_program.c,14 :: 		TMR0 = Copy_u8Preload;
	MOVF       FARG_TIMER0_voidSetPreload_Copy_u8Preload+0, 0
	MOVWF      1
;TIMER0_program.c,15 :: 		}
L_end_TIMER0_voidSetPreload:
	RETURN
; end of _TIMER0_voidSetPreload

_TIMER0_voidEnableInterrupt:

;TIMER0_program.c,17 :: 		void TIMER0_voidEnableInterrupt(void) {
;TIMER0_program.c,19 :: 		INTCON |= (1 << 5);
	BSF        11, 5
;TIMER0_program.c,20 :: 		}
L_end_TIMER0_voidEnableInterrupt:
	RETURN
; end of _TIMER0_voidEnableInterrupt

_TIMER0_voidSetCallBack:

;TIMER0_program.c,22 :: 		void TIMER0_voidSetCallBack(void (*Copy_ptrToFunc)(void)) {
;TIMER0_program.c,23 :: 		if (Copy_ptrToFunc != 0) {
	MOVF       FARG_TIMER0_voidSetCallBack_Copy_ptrToFunc+0, 0
	MOVWF      R1+0
	MOVF       FARG_TIMER0_voidSetCallBack_Copy_ptrToFunc+1, 0
	MOVWF      R1+1
	MOVF       FARG_TIMER0_voidSetCallBack_Copy_ptrToFunc+2, 0
	MOVWF      R1+2
	MOVF       FARG_TIMER0_voidSetCallBack_Copy_ptrToFunc+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__TIMER0_voidSetCallBack7
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__TIMER0_voidSetCallBack7
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__TIMER0_voidSetCallBack7
	MOVF       R1+0, 0
	XORLW      0
L__TIMER0_voidSetCallBack7:
	BTFSC      STATUS+0, 2
	GOTO       L_TIMER0_voidSetCallBack0
;TIMER0_program.c,24 :: 		TIMER0_CallBack = Copy_ptrToFunc;
	MOVF       FARG_TIMER0_voidSetCallBack_Copy_ptrToFunc+0, 0
	MOVWF      TIMER0_program_TIMER0_CallBack+0
	MOVF       FARG_TIMER0_voidSetCallBack_Copy_ptrToFunc+1, 0
	MOVWF      TIMER0_program_TIMER0_CallBack+1
	MOVF       FARG_TIMER0_voidSetCallBack_Copy_ptrToFunc+2, 0
	MOVWF      TIMER0_program_TIMER0_CallBack+2
	MOVF       FARG_TIMER0_voidSetCallBack_Copy_ptrToFunc+3, 0
;TIMER0_program.c,25 :: 		}
L_TIMER0_voidSetCallBack0:
;TIMER0_program.c,26 :: 		}
L_end_TIMER0_voidSetCallBack:
	RETURN
; end of _TIMER0_voidSetCallBack

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;TIMER0_program.c,29 :: 		void interrupt() {
;TIMER0_program.c,31 :: 		if (INTCON & (1 << 2)) {
	BTFSS      11, 2
	GOTO       L_interrupt1
;TIMER0_program.c,32 :: 		INTCON &= ~(1 << 2);
	BCF        11, 2
;TIMER0_program.c,33 :: 		TMR0 = 6;
	MOVLW      6
	MOVWF      1
;TIMER0_program.c,34 :: 		if (TIMER0_CallBack != 0) {
	MOVF       TIMER0_program_TIMER0_CallBack+0, 0
	MOVWF      R1+0
	MOVF       TIMER0_program_TIMER0_CallBack+1, 0
	MOVWF      R1+1
	MOVF       TIMER0_program_TIMER0_CallBack+2, 0
	MOVWF      R1+2
	MOVF       TIMER0_program_TIMER0_CallBack+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt10
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt10
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt10
	MOVF       R1+0, 0
	XORLW      0
L__interrupt10:
	BTFSC      STATUS+0, 2
	GOTO       L_interrupt2
;TIMER0_program.c,35 :: 		TIMER0_CallBack();
	MOVF       TIMER0_program_TIMER0_CallBack+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       TIMER0_program_TIMER0_CallBack+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;TIMER0_program.c,36 :: 		}
L_interrupt2:
;TIMER0_program.c,37 :: 		}
L_interrupt1:
;TIMER0_program.c,38 :: 		}
L_end_interrupt:
L__interrupt9:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt

TIMER0_program____?ag:

L_end_TIMER0_program___?ag:
	RETURN
; end of TIMER0_program____?ag
