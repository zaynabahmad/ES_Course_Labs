
_LED_Init:

;LED.c,4 :: 		void LED_Init(u8 Port, u8 Pin)
;LED.c,6 :: 		GPIO_SetPinDirection(Port, Pin, GPIO_OUTPUT);
	MOVF       FARG_LED_Init_Port+0, 0
	MOVWF      FARG_GPIO_SetPinDirection_Port+0
	MOVF       FARG_LED_Init_Pin+0, 0
	MOVWF      FARG_GPIO_SetPinDirection_Pin+0
	CLRF       FARG_GPIO_SetPinDirection_Direction+0
	CALL       _GPIO_SetPinDirection+0
;LED.c,7 :: 		GPIO_SetPinValue(Port, Pin, GPIO_LOW); // Initialize to OFF
	MOVF       FARG_LED_Init_Port+0, 0
	MOVWF      FARG_GPIO_SetPinValue_Port+0
	MOVF       FARG_LED_Init_Pin+0, 0
	MOVWF      FARG_GPIO_SetPinValue_Pin+0
	CLRF       FARG_GPIO_SetPinValue_Value+0
	CALL       _GPIO_SetPinValue+0
;LED.c,8 :: 		}
L_end_LED_Init:
	RETURN
; end of _LED_Init

_LED_On:

;LED.c,10 :: 		void LED_On(u8 Port, u8 Pin)
;LED.c,12 :: 		GPIO_SetPinValue(Port, Pin, GPIO_HIGH);
	MOVF       FARG_LED_On_Port+0, 0
	MOVWF      FARG_GPIO_SetPinValue_Port+0
	MOVF       FARG_LED_On_Pin+0, 0
	MOVWF      FARG_GPIO_SetPinValue_Pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinValue_Value+0
	CALL       _GPIO_SetPinValue+0
;LED.c,13 :: 		}
L_end_LED_On:
	RETURN
; end of _LED_On

_LED_Off:

;LED.c,15 :: 		void LED_Off(u8 Port, u8 Pin)
;LED.c,17 :: 		GPIO_SetPinValue(Port, Pin, GPIO_LOW);
	MOVF       FARG_LED_Off_Port+0, 0
	MOVWF      FARG_GPIO_SetPinValue_Port+0
	MOVF       FARG_LED_Off_Pin+0, 0
	MOVWF      FARG_GPIO_SetPinValue_Pin+0
	CLRF       FARG_GPIO_SetPinValue_Value+0
	CALL       _GPIO_SetPinValue+0
;LED.c,18 :: 		}
L_end_LED_Off:
	RETURN
; end of _LED_Off

_LED_Toggle:

;LED.c,20 :: 		void LED_Toggle(u8 Port, u8 Pin)
;LED.c,22 :: 		GPIO_TogglePinValue(Port, Pin);
	MOVF       FARG_LED_Toggle_Port+0, 0
	MOVWF      FARG_GPIO_TogglePinValue_Port+0
	MOVF       FARG_LED_Toggle_Pin+0, 0
	MOVWF      FARG_GPIO_TogglePinValue_Pin+0
	CALL       _GPIO_TogglePinValue+0
;LED.c,23 :: 		}
L_end_LED_Toggle:
	RETURN
; end of _LED_Toggle
