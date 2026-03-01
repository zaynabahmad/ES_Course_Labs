
exti_service_ToggleLED:

;exti_service.c,9 :: 		static void ToggleLED(void) {
;exti_service.c,10 :: 		led_toggle_flag = 1;   // Set flag only
	MOVLW      1
	MOVWF      _led_toggle_flag+0
;exti_service.c,11 :: 		}
L_end_ToggleLED:
	RETURN
; end of exti_service_ToggleLED

_EXTI0_Service_Init:

;exti_service.c,14 :: 		void EXTI0_Service_Init(void) {
;exti_service.c,15 :: 		LED_Init(0, 0);           // Initialize LED (Port A, Pin 0)
	CLRF       FARG_LED_Init_port+0
	CLRF       FARG_LED_Init_pin+0
	CALL       _LED_Init+0
;exti_service.c,16 :: 		EXTI0_Init();             // Initialize INT0
	CALL       _EXTI0_Init+0
;exti_service.c,17 :: 		EXTI0_SetCallback(ToggleLED); // Register callback
	MOVLW      exti_service_ToggleLED+0
	MOVWF      FARG_EXTI0_SetCallback_callback+0
	MOVLW      hi_addr(exti_service_ToggleLED+0)
	MOVWF      FARG_EXTI0_SetCallback_callback+1
	MOVLW      0
	MOVWF      FARG_EXTI0_SetCallback_callback+2
	MOVLW      0
	CALL       _EXTI0_SetCallback+0
;exti_service.c,18 :: 		}
L_end_EXTI0_Service_Init:
	RETURN
; end of _EXTI0_Service_Init

_EXTI0_Service_Loop:

;exti_service.c,21 :: 		void EXTI0_Service_Loop(void) {
;exti_service.c,22 :: 		if (led_toggle_flag) {    // Check if interrupt occurred
	MOVF       _led_toggle_flag+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_EXTI0_Service_Loop0
;exti_service.c,23 :: 		led_toggle_flag = 0;  // Clear flag
	CLRF       _led_toggle_flag+0
;exti_service.c,24 :: 		LED_Toggle(0, 0);     // Toggle LED safely in main context
	CLRF       FARG_LED_Toggle_port+0
	CLRF       FARG_LED_Toggle_pin+0
	CALL       _LED_Toggle+0
;exti_service.c,25 :: 		}
L_EXTI0_Service_Loop0:
;exti_service.c,26 :: 		}
L_end_EXTI0_Service_Loop:
	RETURN
; end of _EXTI0_Service_Loop
