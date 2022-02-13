#@copyright : Mohamed Abdallah
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -mthumb -g -gdwarf-2
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
PROJECTNAME=uint3_lab3_cortexM4
all: $(PROJECTNAME).bin
	@echo =====================Bulid succeeded======================

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(PROJECTNAME).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=map_file.map
	cp $(PROJECTNAME).elf $(PROJECTNAME).axf

$(PROJECTNAME).bin: $(PROJECTNAME).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.elf *.bin *.o 

clean:
	rm *.elf *.bin