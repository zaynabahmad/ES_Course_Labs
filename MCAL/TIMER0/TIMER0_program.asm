
_TIMER0_voidInit:

;TIMER0_program.c,7 :: 		void TIMER0_voidInit(void)
;TIMER0_program.c,10 :: 		CLR_BIT(OPTION_REG, OPTION_T0CS);
	BCF        129, 5
;TIMER0_program.c,12 :: 		CLR_BIT(OPTION_REG, OPTION_PSA);
	BCF        129, 3
;TIMER0_program.c,14 :: 		OPTION_REG &= ~(0x07u);                        /* clear PS2:PS0 */
	MOVLW      248
	ANDWF      129, 1
;TIMER0_program.c,15 :: 		OPTION_REG |= TIMER0_PRESCALE_1MS;             /* set 1:8       */
	BSF        129, 1
;TIMER0_program.c,18 :: 		TMR0 = TIMER0_PRELOAD_1MS;
	MOVLW      6
	MOVWF      1
;TIMER0_program.c,21 :: 		CLR_BIT(INTCON, INTCON_T0IF);
	BCF        11, 2
;TIMER0_program.c,22 :: 		}
L_end_TIMER0_voidInit:
	RETURN
; end of _TIMER0_voidInit

_TIMER0_voidDelayMs:

;TIMER0_program.c,25 :: 		void TIMER0_voidDelayMs(unsigned char ms)
;TIMER0_program.c,30 :: 		for (i = 0u; i < ms; i++)
	CLRF       R2+0
L_TIMER0_voidDelayMs0:
	MOVF       FARG_TIMER0_voidDelayMs_ms+0, 0
	SUBWF      R2+0, 0
	BTFSC      STATUS+0, 0
	GOTO       L_TIMER0_voidDelayMs1
;TIMER0_program.c,33 :: 		TMR0 = TIMER0_PRELOAD_1MS;
	MOVLW      6
	MOVWF      1
;TIMER0_program.c,36 :: 		CLR_BIT(INTCON, INTCON_T0IF);
	BCF        11, 2
;TIMER0_program.c,39 :: 		while (GET_BIT(INTCON, INTCON_T0IF) == 0u)
L_TIMER0_voidDelayMs3:
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
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_TIMER0_voidDelayMs4
;TIMER0_program.c,42 :: 		}
	GOTO       L_TIMER0_voidDelayMs3
L_TIMER0_voidDelayMs4:
;TIMER0_program.c,30 :: 		for (i = 0u; i < ms; i++)
	INCF       R2+0, 1
;TIMER0_program.c,43 :: 		}
	GOTO       L_TIMER0_voidDelayMs0
L_TIMER0_voidDelayMs1:
;TIMER0_program.c,46 :: 		CLR_BIT(INTCON, INTCON_T0IF);
	BCF        11, 2
;TIMER0_program.c,47 :: 		}
L_end_TIMER0_voidDelayMs:
	RETURN
; end of _TIMER0_voidDelayMs

_TIMER0_voidSetPreload:

;TIMER0_program.c,50 :: 		void TIMER0_voidSetPreload(unsigned char preload)
;TIMER0_program.c,53 :: 		TMR0 = preload;
	MOVF       FARG_TIMER0_voidSetPreload_preload+0, 0
	MOVWF      1
;TIMER0_program.c,54 :: 		}
L_end_TIMER0_voidSetPreload:
	RETURN
; end of _TIMER0_voidSetPreload

_TIMER0_voidEnableInterrupt:

;TIMER0_program.c,57 :: 		void TIMER0_voidEnableInterrupt(void)
;TIMER0_program.c,60 :: 		CLR_BIT(INTCON, INTCON_T0IF);
	BCF        11, 2
;TIMER0_program.c,63 :: 		SET_BIT(INTCON, INTCON_T0IE);
	BSF        11, 5
;TIMER0_program.c,66 :: 		SET_BIT(INTCON, INTCON_GIE);
	BSF        11, 7
;TIMER0_program.c,67 :: 		}
L_end_TIMER0_voidEnableInterrupt:
	RETURN
; end of _TIMER0_voidEnableInterrupt

_TIMER0_voidDisableInterrupt:

;TIMER0_program.c,70 :: 		void TIMER0_voidDisableInterrupt(void)
;TIMER0_program.c,73 :: 		CLR_BIT(INTCON, INTCON_T0IE);
	BCF        11, 5
;TIMER0_program.c,74 :: 		}
L_end_TIMER0_voidDisableInterrupt:
	RETURN
; end of _TIMER0_voidDisableInterrupt

_TIMER0_voidClearFlag:

;TIMER0_program.c,77 :: 		void TIMER0_voidClearFlag(void)
;TIMER0_program.c,80 :: 		CLR_BIT(INTCON, INTCON_T0IF);
	BCF        11, 2
;TIMER0_program.c,81 :: 		}
L_end_TIMER0_voidClearFlag:
	RETURN
; end of _TIMER0_voidClearFlag

_TIMER0_u8GetFlag:

;TIMER0_program.c,84 :: 		unsigned char TIMER0_u8GetFlag(void)
;TIMER0_program.c,86 :: 		return GET_BIT(INTCON, INTCON_T0IF);
	MOVF       11, 0
	MOVWF      R0+0
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	MOVLW      1
	ANDWF      R0+0, 1
;TIMER0_program.c,87 :: 		}
L_end_TIMER0_u8GetFlag:
	RETURN
; end of _TIMER0_u8GetFlag
