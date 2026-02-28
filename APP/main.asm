
_delay:

;main.c,9 :: 		void delay(void)
;main.c,12 :: 		for(i = 0; i < 50000; i++);
	CLRF       R1+0
	CLRF       R1+1
L_delay0:
	MOVLW      195
	SUBWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__delay6
	MOVLW      80
	SUBWF      R1+0, 0
L__delay6:
	BTFSC      STATUS+0, 0
	GOTO       L_delay1
	INCF       R1+0, 1
	BTFSC      STATUS+0, 2
	INCF       R1+1, 1
	GOTO       L_delay0
L_delay1:
;main.c,13 :: 		}
L_end_delay:
	RETURN
; end of _delay

_main:

;main.c,15 :: 		void main()
;main.c,17 :: 		LED_Init(GPIO_PORTB, GPIO_PIN0);
	MOVLW      1
	MOVWF      FARG_LED_Init_Port+0
	CLRF       FARG_LED_Init_Pin+0
	CALL       _LED_Init+0
;main.c,19 :: 		while(1)
L_main3:
;main.c,21 :: 		LED_On(GPIO_PORTB, GPIO_PIN0);
	MOVLW      1
	MOVWF      FARG_LED_On_Port+0
	CLRF       FARG_LED_On_Pin+0
	CALL       _LED_On+0
;main.c,22 :: 		delay();
	CALL       _delay+0
;main.c,24 :: 		LED_Off(GPIO_PORTB, GPIO_PIN0);
	MOVLW      1
	MOVWF      FARG_LED_Off_Port+0
	CLRF       FARG_LED_Off_Pin+0
	CALL       _LED_Off+0
;main.c,25 :: 		delay();
	CALL       _delay+0
;main.c,26 :: 		}
	GOTO       L_main3
;main.c,27 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
