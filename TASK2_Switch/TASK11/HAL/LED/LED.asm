
_LED_Init:

;LED.c,6 :: 		void LED_Init(void)
;LED.c,8 :: 		GPIO_SetPinDirection(LED1_PORT, LED1_PIN, GPIO_OUTPUT);
	CLRF       FARG_GPIO_SetPinDirection_Port+0
	CLRF       FARG_GPIO_SetPinDirection_Pin+0
	CLRF       FARG_GPIO_SetPinDirection_Direction+0
	CALL       _GPIO_SetPinDirection+0
;LED.c,9 :: 		GPIO_SetPinDirection(LED2_PORT, LED2_PIN, GPIO_OUTPUT);
	CLRF       FARG_GPIO_SetPinDirection_Port+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Pin+0
	CLRF       FARG_GPIO_SetPinDirection_Direction+0
	CALL       _GPIO_SetPinDirection+0
;LED.c,11 :: 		GPIO_SetPinValue(LED1_PORT, LED1_PIN, GPIO_LOW);
	CLRF       FARG_GPIO_SetPinValue_Port+0
	CLRF       FARG_GPIO_SetPinValue_Pin+0
	CLRF       FARG_GPIO_SetPinValue_Value+0
	CALL       _GPIO_SetPinValue+0
;LED.c,12 :: 		GPIO_SetPinValue(LED2_PORT, LED2_PIN, GPIO_LOW);
	CLRF       FARG_GPIO_SetPinValue_Port+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinValue_Pin+0
	CLRF       FARG_GPIO_SetPinValue_Value+0
	CALL       _GPIO_SetPinValue+0
;LED.c,13 :: 		}
L_end_LED_Init:
	RETURN
; end of _LED_Init

_LED_On:

;LED.c,15 :: 		void LED_On(u8 led)
;LED.c,17 :: 		if(led == LED1) GPIO_SetPinValue(LED1_PORT, LED1_PIN, GPIO_HIGH);
	MOVF       FARG_LED_On_led+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_LED_On0
	CLRF       FARG_GPIO_SetPinValue_Port+0
	CLRF       FARG_GPIO_SetPinValue_Pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinValue_Value+0
	CALL       _GPIO_SetPinValue+0
L_LED_On0:
;LED.c,18 :: 		if(led == LED2) GPIO_SetPinValue(LED2_PORT, LED2_PIN, GPIO_HIGH);
	MOVF       FARG_LED_On_led+0, 0
	XORLW      2
	BTFSS      STATUS+0, 2
	GOTO       L_LED_On1
	CLRF       FARG_GPIO_SetPinValue_Port+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinValue_Pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinValue_Value+0
	CALL       _GPIO_SetPinValue+0
L_LED_On1:
;LED.c,19 :: 		}
L_end_LED_On:
	RETURN
; end of _LED_On

_LED_Off:

;LED.c,21 :: 		void LED_Off(u8 led)
;LED.c,23 :: 		if(led == LED1) GPIO_SetPinValue(LED1_PORT, LED1_PIN, GPIO_LOW);
	MOVF       FARG_LED_Off_led+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_LED_Off2
	CLRF       FARG_GPIO_SetPinValue_Port+0
	CLRF       FARG_GPIO_SetPinValue_Pin+0
	CLRF       FARG_GPIO_SetPinValue_Value+0
	CALL       _GPIO_SetPinValue+0
L_LED_Off2:
;LED.c,24 :: 		if(led == LED2) GPIO_SetPinValue(LED2_PORT, LED2_PIN, GPIO_LOW);
	MOVF       FARG_LED_Off_led+0, 0
	XORLW      2
	BTFSS      STATUS+0, 2
	GOTO       L_LED_Off3
	CLRF       FARG_GPIO_SetPinValue_Port+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinValue_Pin+0
	CLRF       FARG_GPIO_SetPinValue_Value+0
	CALL       _GPIO_SetPinValue+0
L_LED_Off3:
;LED.c,25 :: 		}
L_end_LED_Off:
	RETURN
; end of _LED_Off

_LED_Toggle:

;LED.c,27 :: 		void LED_Toggle(u8 led)
;LED.c,29 :: 		if(led == LED1) GPIO_SetPinValue(LED1_PORT, LED1_PIN, !GPIO_GetPinValue(LED1_PORT, LED1_PIN));
	MOVF       FARG_LED_Toggle_led+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_LED_Toggle4
	CLRF       FARG_GPIO_GetPinValue_Port+0
	CLRF       FARG_GPIO_GetPinValue_Pin+0
	CALL       _GPIO_GetPinValue+0
	MOVF       R0+0, 0
	MOVLW      1
	BTFSS      STATUS+0, 2
	MOVLW      0
	MOVWF      FARG_GPIO_SetPinValue_Value+0
	CLRF       FARG_GPIO_SetPinValue_Port+0
	CLRF       FARG_GPIO_SetPinValue_Pin+0
	CALL       _GPIO_SetPinValue+0
L_LED_Toggle4:
;LED.c,30 :: 		if(led == LED2) GPIO_SetPinValue(LED2_PORT, LED2_PIN, !GPIO_GetPinValue(LED2_PORT, LED2_PIN));
	MOVF       FARG_LED_Toggle_led+0, 0
	XORLW      2
	BTFSS      STATUS+0, 2
	GOTO       L_LED_Toggle5
	CLRF       FARG_GPIO_GetPinValue_Port+0
	MOVLW      1
	MOVWF      FARG_GPIO_GetPinValue_Pin+0
	CALL       _GPIO_GetPinValue+0
	MOVF       R0+0, 0
	MOVLW      1
	BTFSS      STATUS+0, 2
	MOVLW      0
	MOVWF      FARG_GPIO_SetPinValue_Value+0
	CLRF       FARG_GPIO_SetPinValue_Port+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinValue_Pin+0
	CALL       _GPIO_SetPinValue+0
L_LED_Toggle5:
;LED.c,31 :: 		}
L_end_LED_Toggle:
	RETURN
; end of _LED_Toggle
