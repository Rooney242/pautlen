CC = gcc
LIBRARIES = lib/
MACROS = $(LIBRARIES)/macros.h

OBJ_FOLDER = $(LIBRARIES)obj/

HASH = hash_table
HASH_DEPS = $(MACROS)

GRAPH = graph
GRAPH_DEPS = $(OBJ_FOLDER)hash_table.o $(OBJ_FOLDER)tsa.o $(MACROS)

TSA = tsa
TSA_DEPS = $(OBJ_FOLDER)hash_table.o $(MACROS)

CASOS = casos
CASOS_DEPS = $(OBJ_FOLDER)tsa.o $(OBJ_FOLDER)hash_table.o $(MACROS)

TSC = tsc
TSC_DEPS = $(OBJ_FOLDER)tsa.o $(OBJ_FOLDER)hash_table.o $(OBJ_FOLDER)graph.o $(OBJ_FOLDER)casos.o $(MACROS)


DOT_GENERATOR = dot_generator
DOT_GENERATOR_DEPS = $(OBJ_FOLDER)tsc.o $(OBJ_FOLDER)graph.o $(MACROS)

all: hash graph tsa tsc dot

all-test: hash-test graph-test

pre:
	@mkdir $(OBJ_FOLDER)

hash:
	@echo Compilando modulo de tabla hash...
	@$(CC) -c $(LIBRARIES)$(HASH).c -o $(OBJ_FOLDER)$(HASH).o 

hash-test: hash
	@echo Compilando tester del modulo de la tabla hash...
	@$(CC) -o $(LIBRARIES)test_$(HASH) $(OBJ_FOLDER)$(HASH).o $(LIBRARIES)test_$(HASH).c $(HASH_DEPS)

graph: tsa
	@echo Compilando modulo de grafos...
	@$(CC) -c $(LIBRARIES)$(GRAPH).c -o $(OBJ_FOLDER)$(GRAPH).o 

graph-test: graph
	@echo Compilando tester del modulo de grafos...
	@$(CC) -o $(LIBRARIES)test_$(GRAPH) $(OBJ_FOLDER)$(GRAPH).o $(LIBRARIES)test_$(GRAPH).c $(GRAPH_DEPS)

casos: tsa hash
	@echo Compilando modulo de casos...
	@$(CC) -c $(LIBRARIES)$(CASOS).c -o $(OBJ_FOLDER)$(CASOS).o 

tsa: hash
	@echo Compilando modulo de tsa...
	@$(CC) -c $(LIBRARIES)$(TSA).c -o $(OBJ_FOLDER)$(TSA).o
	
tsc: tsa graph casos
	@echo Compilando modulo de tsc...
	@$(CC) -c $(LIBRARIES)$(TSC).c -o $(OBJ_FOLDER)$(TSC).o

tsc-test: tsc
	@echo Compilando tester del modulo de tsc...
	@$(CC) -o $(LIBRARIES)test_$(TSC) $(OBJ_FOLDER)$(TSC).o $(LIBRARIES)test_$(TSC).c $(TSC_DEPS)

dot: tsc graph 
	@echo Compilando modulo de generador de ficheros .dot...
	@$(CC) -c $(LIBRARIES)$(DOT_GENERATOR).c -o $(OBJ_FOLDER)$(DOT_GENERATOR).o 

.PHONY : clean all
clean :
	@rm -f $(LIBRARIES)test_$(HASH)
	@rm -f $(LIBRARIES)test_$(GRAPH)
	@rm -f $(LIBRARIES)test_$(TSC)
	@rm -f $(OBJ_FOLDER)*.o