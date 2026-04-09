
_SPI_Test:

;spi_test.c,5 :: 		void SPI_Test(void)
;spi_test.c,9 :: 		SPI_Init();
	CALL       _SPI_Init+0
;spi_test.c,12 :: 		received = SPI_Transmit(0x55); // Send 0x55
	MOVLW      85
	MOVWF      FARG_SPI_Transmit_d+0
	CALL       _SPI_Transmit+0
;spi_test.c,13 :: 		received = SPI_Transmit(0xAA); // Send 0xAA
	MOVLW      170
	MOVWF      FARG_SPI_Transmit_d+0
	CALL       _SPI_Transmit+0
;spi_test.c,16 :: 		while(1);
L_SPI_Test0:
	GOTO       L_SPI_Test0
;spi_test.c,17 :: 		}
L_end_SPI_Test:
	RETURN
; end of _SPI_Test
