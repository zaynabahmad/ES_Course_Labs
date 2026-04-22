# MCU
MCU = 16F877A

# Compiler
CC = xc8-cc

# DFP
DFP = /opt/microchip/PIC16Fxxx_DFP/1.7.162/xc8

# Target
TARGET = app

# Source files
SRCS = \
APP/main.c \
HAL/LED/LED.c \
MCAL/GPIO/GPIO.c

# Include directories
INCLUDES = \
-IAPP \
-IHAL/LED \
-IMCAL/GPIO \
-ISERVICES

# Flags
CFLAGS = -mcpu=$(MCU) -mdfp=$(DFP) $(INCLUDES)

# Default target
all: $(TARGET).hex

# Build target
$(TARGET).hex: $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET).hex $(SRCS)

# # Flash (PICkit2 example)
# flash: $(TARGET).hex
# 	pk2cmd -P$(MCU) -F$(TARGET).hex -M

# Clean
clean:
	rm -f *.hex *.elf *.o *.d *.map *.lst

# .PHONY: all flash clean
.PHONY: all clean
