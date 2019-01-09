CC = gcc

OO_FOLDER = ../../OO/

LIB = -I $(OO_FOLDER)includes/ 

OBJ_FOLDER = $(OO_FOLDER)obj/

OBJ_FOLDER_DEPS = $(OBJ_FOLDER)tsc.o $(OBJ_FOLDER)tsa.o $(OBJ_FOLDER)hash_table.o $(OBJ_FOLDER)graph.o $(OBJ_FOLDER)output.o

EJ = pruebaCompilador



LEX = lex.yy.c

TAB = y.tab

all: generacion flex bison
	@echo Compilado del ejercicio
	@$(CC) $(LIB) -Wall -o omicron $(EJ).c $(LEX) $(TAB).c $(OBJ_FOLDER_DEPS) generacion.o
	@echo Make success

generacion:
	gcc -Wall -c generacion.c -o generacion.o

flex:
	@flex omicron.l

bison:
	@bison -d -y -v omicron.y 

asm:
	nasm -felf32 omicron.asm
	@$(CC) -m32 -o omicron omicron.o olib.o
	./omicron

debug:
	@$(CC) -ggdb $(LIB) -Wall -o omicron $(EJ).c $(LEX) $(TAB).c $(OBJ_FOLDER_DEPS) generacion.o
	@echo Make success

.PHONY : clean all
clean :
	@rm -f $(EJ)
	@rm -f salida.txt
	@rm -f residuo.txt
	@rm -f $(LEX)
	@rm -f $(TAB).c
	@rm -f $(TAB).h
	@rm -f y.output
	@rm -f omicron.asm
	@rm -f omicron.o
	@rm -f omicron
