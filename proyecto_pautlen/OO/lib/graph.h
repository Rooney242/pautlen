#ifndef GRAPH_H
#define GRAPH_H

#include "tsa.h"

#define ES_HIJO -1
#define ES_PADRE_DIRECTO 1
#define ES_PADRE_INDIRECTO 2

typedef struct {
	char* name;
	tsa* tsa;
	int num_atributos_clase;
    int num_atributos_instancia; 
    int num_metodos_sobreescribibles; 
    int num_metodos_no_sobreescribibles;

} Node;

typedef struct {
	int vertex_count;
  	int** arcs; // 0 represents the lack of adjacency
  	Node** nodes;
} Adjacency_Matrix;

Adjacency_Matrix* init_graph();
void free_graph(Adjacency_Matrix* g);
Adjacency_Matrix* transpose_graph(Adjacency_Matrix* g);
int insert_arc(Adjacency_Matrix* g, char* name1, char* name2);
int remove_arc(Adjacency_Matrix* g, char* name1, char* name2);
int exists_arc(Adjacency_Matrix* g, char* name1, char* name2);
int* get_adjacency(Adjacency_Matrix* g, char* name);
int insert_vertex(Adjacency_Matrix* g, char* name);
int insert_class(Adjacency_Matrix* g, char* name, char** parents, int size);
int remove_vertex(Adjacency_Matrix* g, char* name);
int get_parents(Adjacency_Matrix* g, Node** parents, char* name);
int get_parents_names(Adjacency_Matrix* g, char** parents_names, char* name);
void print_graph(Adjacency_Matrix* g);
void print_adjacency(int* a);

Node* init_node(char* name);
void free_node(Node* node);
char* get_node_name(Node* node);
int get_node_index(Adjacency_Matrix* g, char* name);
#endif
