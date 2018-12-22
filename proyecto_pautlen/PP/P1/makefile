all:
	gcc -Wall -o ej4 ej4.c generacion.c
	./ej4 ej.asm
	nasm -felf32 -g ej.asm
	nasm -felf32 -g ts.asm
	gcc -o ej -m32 ej.o ts.o olib.o 
	./ej
	#valgrind --leak-check=full ./ej

clean :
	@rm generacion.o
	@rm ej4
	@rm ej.o
	@rm ts.o
	@rm ej