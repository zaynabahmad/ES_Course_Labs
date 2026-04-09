
_app_spi_test:

;spi_test.c,5 :: 		void app_spi_test(void)
;spi_test.c,7 :: 		u8 txValue = 0;
	CLRF       app_spi_test_txValue_L0+0
	CLRF       app_spi_test_ledState_L0+0
	CLRF       app_spi_test_delayValue_L0+0
;spi_test.c,12 :: 		LED_Init(GPIO_PORTD, GPIO_PIN0);
	MOVLW      3
	MOVWF      FARG_LED_Init_port+0
	CLRF       FARG_LED_Init_pin+0
	CALL       _LED_Init+0
;spi_test.c,14 :: 		SPI_Init();
	CALL       _SPI_Init+0
;spi_test.c,16 :: 		while(1)
L_app_spi_test0:
;spi_test.c,18 :: 		rxValue = SPI_Transfer(txValue);
	MOVF       app_spi_test_txValue_L0+0, 0
	MOVWF      FARG_SPI_Transfer_txValue+0
	CALL       _SPI_Transfer+0
;spi_test.c,21 :: 		ledState ^= 1;
	MOVLW      1
	XORWF      app_spi_test_ledState_L0+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      app_spi_test_ledState_L0+0
;spi_test.c,22 :: 		GPIO_setPinValue(GPIO_PORTD, GPIO_PIN0, ledState);
	MOVLW      3
	MOVWF      FARG_GPIO_setPinValue_port+0
	CLRF       FARG_GPIO_setPinValue_pin+0
	MOVF       R0+0, 0
	MOVWF      FARG_GPIO_setPinValue_value+0
	CALL       _GPIO_setPinValue+0
;spi_test.c,24 :: 		txValue++;
	INCF       app_spi_test_txValue_L0+0, 1
;spi_test.c,26 :: 		for(delayValue = 0; delayValue < 10000; delayValue++)
	CLRF       app_spi_test_delayValue_L0+0
L_app_spi_test2:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORLW      39
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__app_spi_test6
	MOVLW      16
	SUBWF      app_spi_test_delayValue_L0+0, 0
L__app_spi_test6:
	BTFSC      STATUS+0, 0
	GOTO       L_app_spi_test3
	INCF       app_spi_test_delayValue_L0+0, 1
;spi_test.c,29 :: 		}
	GOTO       L_app_spi_test2
L_app_spi_test3:
;spi_test.c,30 :: 		}
	GOTO       L_app_spi_test0
;spi_test.c,31 :: 		}
L_end_app_spi_test:
	RETURN
; end of _app_spi_test
