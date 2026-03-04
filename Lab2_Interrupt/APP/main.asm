
_Button_PressedCallback:

;main.c,34 :: 		void Button_PressedCallback(void)
;main.c,36 :: 		g_button_pressed_flag = 1;   /* Signal main loop */
	MOVLW      1
	MOVWF      _g_button_pressed_flag+0
;main.c,37 :: 		}
L_end_Button_PressedCallback:
	RETURN
; end of _Button_PressedCallback

_main:

;main.c,40 :: 		void main(void)
;main.c,43 :: 		LED_Init(LED_PORT, LED_PIN);
	MOVLW      2
	MOVWF      FARG_LED_Init_port+0
	CLRF       FARG_LED_Init_pin+0
	CALL       _LED_Init+0
;main.c,46 :: 		BUTTON_Init();
	CALL       _BUTTON_Init+0
;main.c,49 :: 		BUTTON_SetCallback(Button_PressedCallback);
	MOVLW      _Button_PressedCallback+0
	MOVWF      FARG_BUTTON_SetCallback_ptr+0
	MOVLW      hi_addr(_Button_PressedCallback+0)
	MOVWF      FARG_BUTTON_SetCallback_ptr+1
	MOVLW      0
	MOVWF      FARG_BUTTON_SetCallback_ptr+2
	MOVLW      0
	CALL       _BUTTON_SetCallback+0
;main.c,52 :: 		while(1)
L_main0:
;main.c,55 :: 		if(g_button_pressed_flag == 1)
	MOVF       _g_button_pressed_flag+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_main2
;main.c,57 :: 		g_button_pressed_flag = 0;   /* Clear flag first */
	CLRF       _g_button_pressed_flag+0
;main.c,58 :: 		LED_Toggle(LED_PORT, LED_PIN); /* Now safe to call GPIO here */
	MOVLW      2
	MOVWF      FARG_LED_Toggle_port+0
	CLRF       FARG_LED_Toggle_pin+0
	CALL       _LED_Toggle+0
;main.c,59 :: 		}
L_main2:
;main.c,60 :: 		}
	GOTO       L_main0
;main.c,61 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
