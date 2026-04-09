
_EXTI_init:

;exti_program.c,9 :: 		void EXTI_init(u8 edge) {
;exti_program.c,11 :: 		SET_BIT(INTCON_REG, GIE);
	BSF        11, 7
;exti_program.c,14 :: 		SET_BIT(INTCON_REG, INTE);
	BSF        11, 4
;exti_program.c,17 :: 		if(edge == EXTI_RISING_EDGE) {
	MOVF       FARG_EXTI_init_edge+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_EXTI_init0
;exti_program.c,18 :: 		SET_BIT(OPTION_REG, INTEDG);
	BSF        129, 6
;exti_program.c,19 :: 		} else {
	GOTO       L_EXTI_init1
L_EXTI_init0:
;exti_program.c,20 :: 		CLR_BIT(OPTION_REG, INTEDG);
	BCF        129, 6
;exti_program.c,21 :: 		}
L_EXTI_init1:
;exti_program.c,22 :: 		}
L_end_EXTI_init:
	RETURN
; end of _EXTI_init

_EXTI_setCallback:

;exti_program.c,24 :: 		void EXTI_setCallback(void (*ptr)(void)) {
;exti_program.c,25 :: 		if(ptr != NULL) {
	MOVF       FARG_EXTI_setCallback_ptr+0, 0
	MOVWF      R1+0
	MOVF       FARG_EXTI_setCallback_ptr+1, 0
	MOVWF      R1+1
	MOVF       FARG_EXTI_setCallback_ptr+2, 0
	MOVWF      R1+2
	MOVF       FARG_EXTI_setCallback_ptr+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__EXTI_setCallback7
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__EXTI_setCallback7
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__EXTI_setCallback7
	MOVF       R1+0, 0
	XORLW      0
L__EXTI_setCallback7:
	BTFSC      STATUS+0, 2
	GOTO       L_EXTI_setCallback2
;exti_program.c,26 :: 		EXTI_CallBackPtr = ptr;
	MOVF       FARG_EXTI_setCallback_ptr+0, 0
	MOVWF      exti_program_EXTI_CallBackPtr+0
	MOVF       FARG_EXTI_setCallback_ptr+1, 0
	MOVWF      exti_program_EXTI_CallBackPtr+1
	MOVF       FARG_EXTI_setCallback_ptr+2, 0
	MOVWF      exti_program_EXTI_CallBackPtr+2
	MOVF       FARG_EXTI_setCallback_ptr+3, 0
;exti_program.c,27 :: 		}
L_EXTI_setCallback2:
;exti_program.c,28 :: 		}
L_end_EXTI_setCallback:
	RETURN
; end of _EXTI_setCallback

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;exti_program.c,37 :: 		void interrupt() {
;exti_program.c,40 :: 		if (GET_BIT(INTCON_REG, INTF) == 1) {
	MOVF       11, 0
	MOVWF      R0+0
	RRF        R0+0, 1
	BCF        R0+0, 7
	MOVLW      1
	ANDWF      R0+0, 0
	MOVWF      R1+0
	MOVF       R1+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_interrupt3
;exti_program.c,41 :: 		exti_flag = 1;
	MOVLW      1
	MOVWF      _exti_flag+0
;exti_program.c,42 :: 		CLR_BIT(INTCON_REG, INTF);
	BCF        11, 1
;exti_program.c,43 :: 		}
L_interrupt3:
;exti_program.c,46 :: 		if (GET_BIT(INTCON_REG, TMR0IF) == 1) {
	MOVF       11, 0
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
	GOTO       L_interrupt4
;exti_program.c,47 :: 		timer0_flag = 1;
	MOVLW      1
	MOVWF      _timer0_flag+0
;exti_program.c,48 :: 		CLR_BIT(INTCON_REG, TMR0IF);
	BCF        11, 2
;exti_program.c,49 :: 		}
L_interrupt4:
;exti_program.c,50 :: 		}
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

exti_program____?ag:

L_end_exti_program___?ag:
	RETURN
; end of exti_program____?ag
