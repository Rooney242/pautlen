/*
 * =====================================================================================
 *
 *       Filename:  adjacency_matrix.h
 *
 *    Description:  Adjacency Matrix Header with the required methods
 *
 *        Version:  1.0
 *        Created:  17/04/2013 10:37:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitor Freitas (vfs), vitorfs@gmail.com
 *        Company:  Universidade Federal de Juiz de Fora (UFJF)
 *
 * =====================================================================================
 */

#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
	char* name;
} Node;

typedef struct {
	int vertex_count;
  	int** arcs; // 0 represents the lack of adjacency
  	Node** nodes;
} Adjacency_Matrix;

void init_graph(Adjacency_Matrix* g);
void free_graph(Adjacency_Matrix* g);
Adjacency_Matrix* transpose_graph(Adjacency_Matrix* g);
int insert_arc(Adjacency_Matrix* g, char* name1, char* name2);
int remove_arc(Adjacency_Matrix* g, char* name1, char* name2);
int exists_arc(Adjacency_Matrix* g, char* name1, char* name2);
int* get_adjacency(Adjacency_Matrix* g, char* name);
void insert_vertex(Adjacency_Matrix* g, char* name);
void remove_vertex(Adjacency_Matrix* g, char* name);
void print_graph(Adjacency_Matrix* g);
void print_adjacency(int* a);

Node* init_node(char* name);
void free_node(Node* node);
char* get_node_name(Node* node);
#endif
