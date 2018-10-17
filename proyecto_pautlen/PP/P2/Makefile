CC = gcc

EJ = omicron

LEX = lex.yy.c

all: ej 

ej:
	@echo Compilado del ejercicio
	@flex $(EJ).l
	@$(CC) -Wall -o $(EJ) $(EJ).c $(LEX)


.PHONY : clean all
clean :
	@rm -f $(EJ)
	@rm -f *.o
	@rm -f salida.txt
	@rm -f $(LEX)

