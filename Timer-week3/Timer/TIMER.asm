
_TIMER0_Init:

;TIMER.c,11 :: 		void TIMER0_Init(void)
;TIMER.c,13 :: 		SET_BIT(INTCON, 5);      // Enable Timer0 Interrupt
	BSF        INTCON+0, 5
;TIMER.c,14 :: 		CLR_BIT(INTCON, 2);      // Clear Timer0 Interrupt Flag
	BCF        INTCON+0, 2
;TIMER.c,15 :: 		CLR_BIT(OPTION_REG, 5);  // Select Internal Clock
	BCF        OPTION_REG+0, 5
;TIMER.c,16 :: 		SET_BIT(INTCON, 7);      // Enable Global Interrupts
	BSF        INTCON+0, 7
;TIMER.c,17 :: 		CLR_BIT(OPTION_REG, 3);  // Assign Prescaler to Timer0
	BCF        OPTION_REG+0, 3
;TIMER.c,20 :: 		SET_BIT(OPTION_REG, 0);
	BSF        OPTION_REG+0, 0
;TIMER.c,21 :: 		SET_BIT(OPTION_REG, 1);
	BSF        OPTION_REG+0, 1
;TIMER.c,22 :: 		SET_BIT(OPTION_REG, 2);
	BSF        OPTION_REG+0, 2
;TIMER.c,24 :: 		TMR0 = 0;
	CLRF       TMR0+0
;TIMER.c,25 :: 		count = 0;
	CLRF       _count+0
;TIMER.c,26 :: 		sec = 0;
	CLRF       _sec+0
;TIMER.c,27 :: 		}
L_end_TIMER0_Init:
	RETURN
; end of _TIMER0_Init

_TIMER0_SetCallback_1Sec:

;TIMER.c,29 :: 		void TIMER0_SetCallback_1Sec(void (*ptr)(void)) { TIMER_1Sec_Callback = ptr; }
	MOVF       FARG_TIMER0_SetCallback_1Sec_ptr+0, 0
	MOVWF      TIMER_TIMER_1Sec_Callback+0
	MOVF       FARG_TIMER0_SetCallback_1Sec_ptr+1, 0
	MOVWF      TIMER_TIMER_1Sec_Callback+1
	MOVF       FARG_TIMER0_SetCallback_1Sec_ptr+2, 0
	MOVWF      TIMER_TIMER_1Sec_Callback+2
	MOVF       FARG_TIMER0_SetCallback_1Sec_ptr+3, 0
L_end_TIMER0_SetCallback_1Sec:
	RETURN
; end of _TIMER0_SetCallback_1Sec

_TIMER0_SetCallback_2Sec:

;TIMER.c,30 :: 		void TIMER0_SetCallback_2Sec(void (*ptr)(void)) { TIMER_2Sec_Callback = ptr; }
	MOVF       FARG_TIMER0_SetCallback_2Sec_ptr+0, 0
	MOVWF      TIMER_TIMER_2Sec_Callback+0
	MOVF       FARG_TIMER0_SetCallback_2Sec_ptr+1, 0
	MOVWF      TIMER_TIMER_2Sec_Callback+1
	MOVF       FARG_TIMER0_SetCallback_2Sec_ptr+2, 0
	MOVWF      TIMER_TIMER_2Sec_Callback+2
	MOVF       FARG_TIMER0_SetCallback_2Sec_ptr+3, 0
L_end_TIMER0_SetCallback_2Sec:
	RETURN
; end of _TIMER0_SetCallback_2Sec

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;TIMER.c,32 :: 		void interrupt()
;TIMER.c,34 :: 		if(GET_BIT(INTCON, 2))
	MOVF       INTCON+0, 0
	MOVWF      R1+0
	RRF        R1+0, 1
	BCF        R1+0, 7
	RRF        R1+0, 1
	BCF        R1+0, 7
	BTFSS      R1+0, 0
	GOTO       L_interrupt0
;TIMER.c,36 :: 		CLR_BIT(INTCON, 2);
	BCF        INTCON+0, 2
;TIMER.c,38 :: 		if(count < 30) {
	MOVLW      30
	SUBWF      _count+0, 0
	BTFSC      STATUS+0, 0
	GOTO       L_interrupt1
;TIMER.c,39 :: 		TMR0 = 0;
	CLRF       TMR0+0
;TIMER.c,40 :: 		count++;
	INCF       _count+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      _count+0
;TIMER.c,41 :: 		}
	GOTO       L_interrupt2
L_interrupt1:
;TIMER.c,42 :: 		else if(count == 30) {
	MOVF       _count+0, 0
	XORLW      30
	BTFSS      STATUS+0, 2
	GOTO       L_interrupt3
;TIMER.c,43 :: 		TMR0 = 125;
	MOVLW      125
	MOVWF      TMR0+0
;TIMER.c,44 :: 		count++;
	INCF       _count+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      _count+0
;TIMER.c,45 :: 		}
	GOTO       L_interrupt4
L_interrupt3:
;TIMER.c,47 :: 		count = 0;
	CLRF       _count+0
;TIMER.c,50 :: 		if(TIMER_1Sec_Callback != 0) {
	MOVF       TIMER_TIMER_1Sec_Callback+0, 0
	MOVWF      R1+0
	MOVF       TIMER_TIMER_1Sec_Callback+1, 0
	MOVWF      R1+1
	MOVF       TIMER_TIMER_1Sec_Callback+2, 0
	MOVWF      R1+2
	MOVF       TIMER_TIMER_1Sec_Callback+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt13
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt13
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt13
	MOVF       R1+0, 0
	XORLW      0
L__interrupt13:
	BTFSC      STATUS+0, 2
	GOTO       L_interrupt5
;TIMER.c,51 :: 		TIMER_1Sec_Callback();
	MOVF       TIMER_TIMER_1Sec_Callback+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       TIMER_TIMER_1Sec_Callback+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;TIMER.c,52 :: 		}
L_interrupt5:
;TIMER.c,54 :: 		sec++;
	INCF       _sec+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      _sec+0
;TIMER.c,56 :: 		if(sec >= 2) {
	MOVLW      2
	SUBWF      _sec+0, 0
	BTFSS      STATUS+0, 0
	GOTO       L_interrupt6
;TIMER.c,57 :: 		if(TIMER_2Sec_Callback != 0) {
	MOVF       TIMER_TIMER_2Sec_Callback+0, 0
	MOVWF      R1+0
	MOVF       TIMER_TIMER_2Sec_Callback+1, 0
	MOVWF      R1+1
	MOVF       TIMER_TIMER_2Sec_Callback+2, 0
	MOVWF      R1+2
	MOVF       TIMER_TIMER_2Sec_Callback+3, 0
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
	GOTO       L_interrupt7
;TIMER.c,58 :: 		TIMER_2Sec_Callback();
	MOVF       TIMER_TIMER_2Sec_Callback+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       TIMER_TIMER_2Sec_Callback+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;TIMER.c,59 :: 		}
L_interrupt7:
;TIMER.c,60 :: 		sec = 0;
	CLRF       _sec+0
;TIMER.c,61 :: 		}
L_interrupt6:
;TIMER.c,62 :: 		}
L_interrupt4:
L_interrupt2:
;TIMER.c,63 :: 		}
L_interrupt0:
;TIMER.c,64 :: 		}
L_end_interrupt:
L__interrupt12:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt

TIMER____?ag:

L_end_TIMER___?ag:
	RETURN
; end of TIMER____?ag
