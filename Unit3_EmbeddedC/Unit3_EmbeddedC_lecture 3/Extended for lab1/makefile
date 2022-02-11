#@copyright : Mohamed Abdallah
CC=arm-none-eabi-
CFLAGS= -g -mcpu=arm926ej-s
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
PROJECTNAME=learn-in-depth
all: $(PROJECTNAME).bin
	@echo =====================Bulid succeeded======================

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(PROJECTNAME).elf: startup.o uart.o app.o
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@

$(PROJECTNAME).bin: $(PROJECTNAME).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.elf *.bin *.o 

clean:
	rm *.elf *.bin