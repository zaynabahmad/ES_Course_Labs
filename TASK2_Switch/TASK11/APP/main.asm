
_ShortSequence:

;main.c,11 :: 		void ShortSequence(void)
;main.c,13 :: 		LED_On(LED1);
	MOVLW      1
	MOVWF      FARG_LED_On_led+0
	CALL       _LED_On+0
;main.c,14 :: 		LED_On(LED2);
	MOVLW      2
	MOVWF      FARG_LED_On_led+0
	CALL       _LED_On+0
;main.c,15 :: 		Delay_ms(200);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      8
	MOVWF      R12+0
	MOVLW      119
	MOVWF      R13+0
L_ShortSequence0:
	DECFSZ     R13+0, 1
	GOTO       L_ShortSequence0
	DECFSZ     R12+0, 1
	GOTO       L_ShortSequence0
	DECFSZ     R11+0, 1
	GOTO       L_ShortSequence0
;main.c,16 :: 		LED_Off(LED1);
	MOVLW      1
	MOVWF      FARG_LED_Off_led+0
	CALL       _LED_Off+0
;main.c,17 :: 		LED_Off(LED2);
	MOVLW      2
	MOVWF      FARG_LED_Off_led+0
	CALL       _LED_Off+0
;main.c,18 :: 		Delay_ms(200);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      8
	MOVWF      R12+0
	MOVLW      119
	MOVWF      R13+0
L_ShortSequence1:
	DECFSZ     R13+0, 1
	GOTO       L_ShortSequence1
	DECFSZ     R12+0, 1
	GOTO       L_ShortSequence1
	DECFSZ     R11+0, 1
	GOTO       L_ShortSequence1
;main.c,19 :: 		}
L_end_ShortSequence:
	RETURN
; end of _ShortSequence

_LongSequence:

;main.c,21 :: 		void LongSequence(void)
;main.c,23 :: 		LED_On(LED1);
	MOVLW      1
	MOVWF      FARG_LED_On_led+0
	CALL       _LED_On+0
;main.c,24 :: 		LED_On(LED2);
	MOVLW      2
	MOVWF      FARG_LED_On_led+0
	CALL       _LED_On+0
;main.c,25 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_LongSequence2:
	DECFSZ     R13+0, 1
	GOTO       L_LongSequence2
	DECFSZ     R12+0, 1
	GOTO       L_LongSequence2
	DECFSZ     R11+0, 1
	GOTO       L_LongSequence2
	NOP
	NOP
;main.c,26 :: 		LED_Off(LED1);
	MOVLW      1
	MOVWF      FARG_LED_Off_led+0
	CALL       _LED_Off+0
;main.c,27 :: 		LED_Off(LED2);
	MOVLW      2
	MOVWF      FARG_LED_Off_led+0
	CALL       _LED_Off+0
;main.c,28 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_LongSequence3:
	DECFSZ     R13+0, 1
	GOTO       L_LongSequence3
	DECFSZ     R12+0, 1
	GOTO       L_LongSequence3
	DECFSZ     R11+0, 1
	GOTO       L_LongSequence3
	NOP
	NOP
;main.c,29 :: 		}
L_end_LongSequence:
	RETURN
; end of _LongSequence

_main:

;main.c,31 :: 		void main(void)
;main.c,33 :: 		GPIO_Init();
	CALL       _GPIO_Init+0
;main.c,34 :: 		LED_Init();
	CALL       _LED_Init+0
;main.c,36 :: 		GPIO_SetPinDirection(SW1_PORT, SW1_PIN, GPIO_INPUT);
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Port+0
	CLRF       FARG_GPIO_SetPinDirection_Pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Direction+0
	CALL       _GPIO_SetPinDirection+0
;main.c,37 :: 		GPIO_SetPinDirection(SW2_PORT, SW2_PIN, GPIO_INPUT);
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Port+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Direction+0
	CALL       _GPIO_SetPinDirection+0
;main.c,39 :: 		while(1)
L_main4:
;main.c,41 :: 		if(GPIO_GetPinValue(SW1_PORT, SW1_PIN) == 0)
	MOVLW      1
	MOVWF      FARG_GPIO_GetPinValue_Port+0
	CLRF       FARG_GPIO_GetPinValue_Pin+0
	CALL       _GPIO_GetPinValue+0
	MOVF       R0+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_main6
;main.c,42 :: 		ShortSequence();
	CALL       _ShortSequence+0
	GOTO       L_main7
L_main6:
;main.c,43 :: 		else if(GPIO_GetPinValue(SW2_PORT, SW2_PIN) == 0)
	MOVLW      1
	MOVWF      FARG_GPIO_GetPinValue_Port+0
	MOVLW      1
	MOVWF      FARG_GPIO_GetPinValue_Pin+0
	CALL       _GPIO_GetPinValue+0
	MOVF       R0+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_main8
;main.c,44 :: 		LongSequence();
	CALL       _LongSequence+0
	GOTO       L_main9
L_main8:
;main.c,47 :: 		LED_Off(LED1);
	MOVLW      1
	MOVWF      FARG_LED_Off_led+0
	CALL       _LED_Off+0
;main.c,48 :: 		LED_Off(LED2);
	MOVLW      2
	MOVWF      FARG_LED_Off_led+0
	CALL       _LED_Off+0
;main.c,49 :: 		}
L_main9:
L_main7:
;main.c,50 :: 		}
	GOTO       L_main4
;main.c,51 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
