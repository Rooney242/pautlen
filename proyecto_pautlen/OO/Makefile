CC = gcc
LIB = -I$(INCLUDES)

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
OUTPUT_DEPS = $(OBJ_FOLDER)tsa.o $(OBJ_FOLDER)hash_table.o

TSC = tsc
TSC_DEPS = $(OBJ_FOLDER)tsa.o $(OBJ_FOLDER)hash_table.o $(OBJ_FOLDER)graph.o $(OBJ_FOLDER)output.o

DOT_GENERATOR = dot_generator


all: hash graph tsa tsc output

all-test: graph-test tsc-test

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

.PHONY : clean all
clean :
	@rm -f test_$(HASH)
	@rm -f test_$(GRAPH)
	@rm -f test_$(TSC)
	@rm -f test_$(DOT_GENERATOR)
	@rm -f grafo.dot
	@rm -f $(OBJ_FOLDER)*.o