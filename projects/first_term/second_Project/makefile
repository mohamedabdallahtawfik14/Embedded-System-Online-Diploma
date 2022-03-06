#@copyright : Mohamed Abdallah

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
PROJECTNAME=DataBaseProject

all: $(PROJECTNAME).exe
	@echo =====================Bulid succeeded======================
	
%.o: %.c
	gcc.exe -c $< -o $@

$(PROJECTNAME).exe: $(OBJ)
	gcc.exe  $(OBJ) -o $@

clean:
	rm *.exe *.o