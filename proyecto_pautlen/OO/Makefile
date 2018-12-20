CC = gcc
LIB = -I$(INCLUDES) -g

INCLUDES = includes/
SOURCES = src/
TESTS = tests/

MACROS = $(SOURCES)/macros.h

OBJ_FOLDER = obj/

HASH = hash_table
HASH_DEPS = 

GRAPH = graph
GRAPH_DEPS = $(OBJ_FOLDER)hash_table.o $(OBJ_FOLDER)tsa.o 

TSA = tsa
TSA_DEPS = $(OBJ_FOLDER)hash_table.o 

OUTPUT = output
OUTPUT_DEPS = $(OBJ_FOLDER)tsa.o $(OBJ_FOLDER)hash_table.o $(OBJ_FOLDER)tsc.o

TSC = tsc
TSC_DEPS = $(OBJ_FOLDER)tsa.o $(OBJ_FOLDER)hash_table.o $(OBJ_FOLDER)graph.o $(OBJ_FOLDER)output.o

GENERADOR_TSC = generador_tsc
GENERADOR_TSC_DEPS = $(OBJ_FOLDER)tsc.o $(OBJ_FOLDER)tsa.o $(OBJ_FOLDER)hash_table.o $(OBJ_FOLDER)graph.o $(OBJ_FOLDER)output.o

DOT_GENERATOR = dot_generator

PRACTICA4 = prueba_TS



all: hash graph tsa tsc output generador_tsc

all-test: graph-test tsc-test dot-test generador_tsc-test 

pre:
	@mkdir $(OBJ_FOLDER)

hash:
	@echo Compilando modulo de tabla hash...
	@$(CC) $(LIB) -c $(SOURCES)$(HASH).c -o $(OBJ_FOLDER)$(HASH).o

graph: tsa
	@echo Compilando modulo de grafos...
	@$(CC) $(LIB) -c $(SOURCES)$(GRAPH).c -o $(OBJ_FOLDER)$(GRAPH).o 

graph-test: graph
	@echo Compilando tester del modulo de grafos...
	@$(CC) $(LIB) -o test_$(GRAPH) $(OBJ_FOLDER)$(GRAPH).o $(TESTS)test_$(GRAPH).c $(GRAPH_DEPS)

output: tsa hash
	@echo Compilando modulo de output...
	@$(CC) $(LIB) -c $(SOURCES)$(OUTPUT).c -o $(OBJ_FOLDER)$(OUTPUT).o 

tsa: hash
	@echo Compilando modulo de tsa...
	@$(CC) $(LIB) -c $(SOURCES)$(TSA).c -o $(OBJ_FOLDER)$(TSA).o
	
tsc: tsa graph output
	@echo Compilando modulo de tsc...
	@$(CC) $(LIB) -c $(SOURCES)$(TSC).c -o $(OBJ_FOLDER)$(TSC).o

tsc-test: tsc
	@echo Compilando tester del modulo de tsc...
	@$(CC) $(LIB) -o test_$(TSC) $(OBJ_FOLDER)$(TSC).o $(TESTS)test_$(TSC).c $(TSC_DEPS)

dot-test: tsc
	@echo Compilando tester de la generacion de dot...
	@$(CC) $(LIB) -o test_$(DOT_GENERATOR) $(OBJ_FOLDER)$(TSC).o $(TESTS)test_$(DOT_GENERATOR).c $(TSC_DEPS)

generador_tsc: tsc
	@echo Compilando modulo del generacion de tsc...
	@$(CC) $(LIB) -c $(SOURCES)$(GENERADOR_TSC).c -o $(OBJ_FOLDER)$(GENERADOR_TSC).o

generador_tsc-test: generador_tsc
	@echo Compilando tester del modulo de generacion de tsc...
	@$(CC) $(LIB) -o test_$(GENERADOR_TSC) $(OBJ_FOLDER)$(GENERADOR_TSC).o $(TESTS)test_$(GENERADOR_TSC).c $(GENERADOR_TSC_DEPS)

practica4: generador_tsc
	@echo Compilando el archivo de prueba para la entrega de la practica 4...
	@$(CC) $(LIB) -o $(PRACTICA4) $(OBJ_FOLDER)$(GENERADOR_TSC).o $(TESTS)$(PRACTICA4).c $(GENERADOR_TSC_DEPS)

.PHONY : clean all
clean :
	@rm -f test_$(HASH)
	@rm -f test_$(GRAPH)
	@rm -f test_$(TSC)
	@rm -f test_$(DOT_GENERATOR)
	@rm -f test_$(GENERADOR_TSC)
	@rm -f test_$(GENERADOR_NASM)
	@rm -f $(PRACTICA4)
	@rm -f grafo.dot
	@rm -f $(OBJ_FOLDER)*.o