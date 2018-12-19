Para compilar se puede hacer:
	-make o make all: se compilaran todos los modulos sin tests
	-make all-test se compilaran todos los tests que usabamos nosotros para probar las cosas
	-make practica4: se compilara el test llamado prueba_TS tal como indica la practica, 
		se le puede llamar con ./prueba_TS fichero_entrada fichero_salida (el fichero de entrada
		que proponeis en la practica se encuentra en programs/programs1)
	-make pre: por si no compila prepara los ficheros para que se pueda hacer make
	-make clean: borra todo 

Nota conceptual sobre las funciones de insercion y busqueda:
	Estas funciones devuelven casos concretos dentro del contexto del programa,
	para usarlas correctamente se debe tener en cuenta la libreria output.h en donde están
	definidos. El criterio que se ha seguido es que las funciones devuelven un numero positivo
	en caso de OK y un numero negativo en caso de ERR.