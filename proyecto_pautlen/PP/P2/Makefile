CC = gcc

EJ = omicron

LEX = lex.yy.c

all: 
	@echo Compilado del ejercicio
	@flex $(EJ).l
	@$(CC) -Wall -o pruebaMorfo $(EJ).c $(LEX)


.PHONY : clean all
clean :
	@rm -f $(EJ)
	@rm -f *.o
	@rm -f residuo.txt
	@rm -f $(LEX)

