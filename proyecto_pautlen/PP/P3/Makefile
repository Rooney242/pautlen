CC = gcc

EJ = pruebaSintactico

LEX = lex.yy.c

TAB = y.tab

all: flex bison
	@echo Compilado del ejercicio
	@$(CC) -Wall -o $(EJ) $(EJ).c $(LEX) $(TAB).c

flex:
	@flex omicron.l

bison:
	@bison -d -y -v omicron.y

.PHONY : clean all
clean :
	@rm -f $(EJ)
	@rm -f *.o
	@rm -f residuo.txt
	@rm -f $(LEX)
	@rm -f $(TAB).c
	@rm -f $(TAB).h
	@rm -f y.output
