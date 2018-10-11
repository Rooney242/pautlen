CC = gcc

LIBRARIES = lib/

OBJ_FOLDER = $(LIBRARIES)obj/

HASH = hash_table
HASH_DEPS =

GRAPH = graph
GRAPH_DEPS = $(OBJ_FOLDER)hash_table.o $(OBJ_FOLDER)tsa.o

TSA = tsa
TSA_DEPS = $(OBJ_FOLDER)hash_table.o 

all: hash graph

all-test: hash-test graph-test

pre:
	@mkdir $(OBJ_FOLDER)

hash:
	@echo Compilando modulo de tabla hash...
	@$(CC) -c $(LIBRARIES)$(HASH).c -o $(OBJ_FOLDER)$(HASH).o

hash-test: hash
	@echo Compilando tester del modulo de la tabla hash...
	@$(CC) -o $(LIBRARIES)test_$(HASH) $(LIBRARIES)$(HASH).o $(LIBRARIES)test_$(HASH).c

graph: tsa
	@echo Compilando modulo de grafos...
	@$(CC) -c $(LIBRARIES)$(GRAPH).c -o $(OBJ_FOLDER)$(GRAPH).o

graph-test: graph
	@echo Compilando tester del modulo de grafos...
	@$(CC) -o $(LIBRARIES)test_$(GRAPH) $(OBJ_FOLDER)$(GRAPH).o $(LIBRARIES)test_$(GRAPH).c $(GRAPH_DEPS)

tsa: hash
	@echo Compilando modulo de tsa...
	@$(CC) -c $(LIBRARIES)$(TSA).c -o $(OBJ_FOLDER)$(TSA).o

.PHONY : clean all
clean :
	@rm -f $(LIBRARIES)test_$(HASH)
	@rm -f $(LIBRARIES)test_$(GRAPH)
	@rm -f $(OBJ_FOLDER)*.o