
_App_ToggleLED_ISR:

;main.c,11 :: 		void App_ToggleLED_ISR(void) {
;main.c,13 :: 		Delay_ms(30);
	MOVLW      78
	MOVWF      R12+0
	MOVLW      235
	MOVWF      R13+0
L_App_ToggleLED_ISR0:
	DECFSZ     R13+0, 1
	GOTO       L_App_ToggleLED_ISR0
	DECFSZ     R12+0, 1
	GOTO       L_App_ToggleLED_ISR0
;main.c,16 :: 		LED_Toggle(APP_LED_PORT, APP_LED_PIN);
	MOVLW      3
	MOVWF      FARG_LED_Toggle_Port+0
	CLRF       FARG_LED_Toggle_Pin+0
	CALL       _LED_Toggle+0
;main.c,17 :: 		}
L_end_App_ToggleLED_ISR:
	RETURN
; end of _App_ToggleLED_ISR

_main:

;main.c,19 :: 		void main() {
;main.c,21 :: 		LED_Init(APP_LED_PORT, APP_LED_PIN);
	MOVLW      3
	MOVWF      FARG_LED_Init_Port+0
	CLRF       FARG_LED_Init_Pin+0
	CALL       _LED_Init+0
;main.c,24 :: 		SWITCH_Init(GPIO_PIN0);
	CLRF       FARG_SWITCH_Init_pin+0
	CALL       _SWITCH_Init+0
;main.c,26 :: 		EXT_INT0_Init();
	CALL       _EXT_INT0_Init+0
;main.c,29 :: 		EXT_INT0_SetCallback(App_ToggleLED_ISR);
	MOVLW      _App_ToggleLED_ISR+0
	MOVWF      FARG_EXT_INT0_SetCallback_ptr+0
	MOVLW      hi_addr(_App_ToggleLED_ISR+0)
	MOVWF      FARG_EXT_INT0_SetCallback_ptr+1
	MOVLW      0
	MOVWF      FARG_EXT_INT0_SetCallback_ptr+2
	MOVLW      0
	CALL       _EXT_INT0_SetCallback+0
;main.c,32 :: 		EXT_INT0_Enable();
	CALL       _EXT_INT0_Enable+0
;main.c,35 :: 		while (1) {
L_main1:
;main.c,37 :: 		}
	GOTO       L_main1
;main.c,38 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
