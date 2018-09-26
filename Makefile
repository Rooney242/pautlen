CC = gcc

LIBRARIES = lib/

OBJ_FOLDER = $(LIBRARIES)obj/

HASH_FOLDER = $(LIBRARIES)hash_table/
HASH = hash_table

GRAPH_FOLDER = $(LIBRARIES)graph/
GRAPH = graph

all: hash graph

all-test: hash-test graph-test

pre:
	@mkdir $(OBJ_FOLDER)

hash:
	@echo Compilando modulo de tabla hash...
	@$(CC) -c $(HASH_FOLDER)$(HASH).c -o $(OBJ_FOLDER)$(HASH).o

hash-test: hash
	@echo Compilando tester del modulo de la tabla hash...
	@$(CC) -o $(HASH_FOLDER)test_$(HASH) $(HASH_FOLDER)$(HASH).o $(HASH_FOLDER)test_$(HASH).c

graph:
	@echo Compilando modulo de grafos...
	@$(CC) -c $(GRAPH_FOLDER)$(GRAPH).c -o $(OBJ_FOLDER)$(GRAPH).o

graph-test: graph
	@echo Compilando tester del modulo de grafos...
	@$(CC) -o $(GRAPH_FOLDER)test_$(GRAPH) $(OBJ_FOLDER)$(GRAPH).o $(GRAPH_FOLDER)test_$(GRAPH).c

.PHONY : clean all
clean :
	@rm -f $(HASH_FOLDER)test_$(HASH)
	@rm -f $(GRAPH_FOLDER)test_$(GRAPH)
	@rm -f $(OBJ_FOLDER)*.o