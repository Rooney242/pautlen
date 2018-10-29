#ifndef GRAPH_H
#define GRAPH_H

#include "tsa.h"

#define ES_HIJO -1
#define ES_PADRE_DIRECTO 1
#define ES_PADRE_INDIRECTO 2

typedef struct {
	char* name;
	tsa* tsa;
} Node;

typedef struct {
	int vertex_count;
  	int** arcs; // 0 represents the lack of adjacency
  	Node** nodes;
} Adjacency_Matrix;

Adjacency_Matrix* init_graph(Adjacency_Matrix* g);
void free_graph(Adjacency_Matrix* g);
Adjacency_Matrix* transpose_graph(Adjacency_Matrix* g);
int insert_arc(Adjacency_Matrix* g, char* name1, char* name2);
int remove_arc(Adjacency_Matrix* g, char* name1, char* name2);
int exists_arc(Adjacency_Matrix* g, char* name1, char* name2);
int* get_adjacency(Adjacency_Matrix* g, char* name);
int insert_vertex(Adjacency_Matrix* g, char* name);
int insert_class(Adjacency_Matrix* g, char* name, char** parents, int size);
int remove_vertex(Adjacency_Matrix* g, char* name);
Node ** get_parents(Adjacency_Matrix* g, char* name);
void print_graph(Adjacency_Matrix* g);
void print_adjacency(int* a);

Node* init_node(char* name);
void free_node(Node* node);
char* get_node_name(Node* node);
#endif
