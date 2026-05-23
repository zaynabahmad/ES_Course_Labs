
_PWM_voidInit:

;PWM_program.c,7 :: 		void PWM_voidInit(void)
;PWM_program.c,9 :: 		CLR_BIT(TRISC, PWM_OUTPUT_PIN);
	BCF        135, 2
;PWM_program.c,11 :: 		PR2 = PWM_PR2_VALUE;
	MOVLW      124
	MOVWF      146
;PWM_program.c,13 :: 		CCP1CON = PWM_MODE_VALUE;
	MOVLW      12
	MOVWF      23
;PWM_program.c,15 :: 		CCPR1L = 0x00u;
	CLRF       21
;PWM_program.c,17 :: 		TMR2   = 0x00u;                         /* clear timer count   */
	CLRF       17
;PWM_program.c,18 :: 		T2CON  = T2_PRESCALE_4;                 /* set prescaler = 1:4 */
	MOVLW      1
	MOVWF      18
;PWM_program.c,19 :: 		SET_BIT(T2CON, T2CON_TMR2ON);           /* start Timer2        */
	BSF        18, 2
;PWM_program.c,20 :: 		}
L_end_PWM_voidInit:
	RETURN
; end of _PWM_voidInit

_PWM_voidSetDuty:

;PWM_program.c,23 :: 		unsigned char PWM_voidSetDuty(unsigned char duty_percent)
;PWM_program.c,28 :: 		if (duty_percent > 100u)
	MOVF       FARG_PWM_voidSetDuty_duty_percent+0, 0
	SUBLW      100
	BTFSC      STATUS+0, 0
	GOTO       L_PWM_voidSetDuty0
;PWM_program.c,30 :: 		return PWM_ERR_INVALID;
	MOVLW      255
	MOVWF      R0+0
	GOTO       L_end_PWM_voidSetDuty
;PWM_program.c,31 :: 		}
L_PWM_voidSetDuty0:
;PWM_program.c,33 :: 		raw = ((unsigned int)duty_percent * PWM_MAX_DUTY) / 100u;
	MOVF       FARG_PWM_voidSetDuty_duty_percent+0, 0
	MOVWF      R0+0
	CLRF       R0+1
	MOVLW      255
	MOVWF      R4+0
	CLRF       R4+1
	CALL       _Mul_16X16_U+0
	MOVLW      100
	MOVWF      R4+0
	CLRF       R4+1
	CALL       _Div_16X16_U+0
;PWM_program.c,36 :: 		CCPR1L = (unsigned char)raw;
	MOVF       R0+0, 0
	MOVWF      21
;PWM_program.c,38 :: 		CLR_BIT(CCP1CON, CCP1CON_DC1B0);
	BCF        23, 4
;PWM_program.c,39 :: 		CLR_BIT(CCP1CON, CCP1CON_DC1B1);
	BCF        23, 5
;PWM_program.c,41 :: 		return PWM_OK;
	CLRF       R0+0
;PWM_program.c,42 :: 		}
L_end_PWM_voidSetDuty:
	RETURN
; end of _PWM_voidSetDuty

_PWM_voidSetDutyRaw:

;PWM_program.c,45 :: 		void PWM_voidSetDutyRaw(unsigned char raw)
;PWM_program.c,48 :: 		CCPR1L = raw;
	MOVF       FARG_PWM_voidSetDutyRaw_raw+0, 0
	MOVWF      21
;PWM_program.c,49 :: 		CLR_BIT(CCP1CON, CCP1CON_DC1B0);
	BCF        23, 4
;PWM_program.c,50 :: 		CLR_BIT(CCP1CON, CCP1CON_DC1B1);
	BCF        23, 5
;PWM_program.c,51 :: 		}
L_end_PWM_voidSetDutyRaw:
	RETURN
; end of _PWM_voidSetDutyRaw

_PWM_voidStop:

;PWM_program.c,54 :: 		void PWM_voidStop(void)
;PWM_program.c,57 :: 		CLR_BIT(T2CON, T2CON_TMR2ON);
	BCF        18, 2
;PWM_program.c,60 :: 		CCP1CON = 0x00u;
	CLRF       23
;PWM_program.c,63 :: 		CCPR1L = 0x00u;
	CLRF       21
;PWM_program.c,64 :: 		}
L_end_PWM_voidStop:
	RETURN
; end of _PWM_voidStop
