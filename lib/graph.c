/*
 * =====================================================================================
 *
 *       Filename:  adjacency_matrix.c
 *
 *    Description:  Adjacency Matrix implementation using an Adjacency Matrix
 *
 *        Version:  1.0
 *        Created:  15/04/2013 14:27:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitor Freitas (vfs), vitorfs@gmail.com
 *        Company:  Universidade Federal de Juiz de Fora (UFJF)
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

void init_graph(Adjacency_Matrix* g) {
  g->vertex_count = 0;
  g->arcs = NULL;
  g->nodes = NULL;
}

void free_graph(Adjacency_Matrix* g) {
  int i;
  for (i = 0; i < g->vertex_count; i++){
    free(g->arcs[i]);
    free_node(g->nodes[i]);
  }

  free(g->arcs);
  free(g->nodes);
  free(g);
}


Adjacency_Matrix* transpose_graph(Adjacency_Matrix* g) {
  /*Adjacency_Matrix* transpose = (Adjacency_Matrix*) malloc(sizeof(Adjacency_Matrix));
  init_graph(transpose);

  int i, j;

  for (i = 0 ; i < g->vertex_count ; i++)
    for (j = 0 ; j < g->vertex_count ; j++)
      if (g->arcs[i][j] == 0)
        transpose->arcs[i][j] = 1;

  return transpose;*/
}
int get_node_index(Adjacency_Matrix* g, char* name){
  int i;
  for(i = 0; i < g->vertex_count; i++){
    if (!strcmp(name, g->nodes[i]->name)){
      break;
    }
  }
  if(i < g->vertex_count){
    return i;
  }else{
    return -1;
  }
}

int insert_arc(Adjacency_Matrix* g, char* name1, char* name2) {
  int a1, a2;
  a1 = get_node_index(g, name1);
  a2 = get_node_index(g, name2);
  if (a1 >= 0 && a1 < g->vertex_count && a2 >= 0 && a2 < g->vertex_count && g->arcs[a1][a2] == 0) {
    g->arcs[a1][a2] = 1;
    g->arcs[a2][a1] = 1;
    return 0;
  }
  return -1;
}

int remove_arc(Adjacency_Matrix* g, char* name1, char* name2) {
  int a1, a2;
  a1 = get_node_index(g, name1);
  a2 = get_node_index(g, name2);
  int weight = -1;
  if (a1 >= 0 && a1 < g->vertex_count && a2 >= 0 && a2 < g->vertex_count && g->arcs[a1][a2] > 0) {
    weight = g->arcs[a1][a2];
    g->arcs[a1][a2] = 0;
    g->arcs[a2][a1] = 0;
  }
  return weight;
}

int exists_arc(Adjacency_Matrix* g, char* name1, char* name2) {
  int a1, a2;
  a1 = get_node_index(g, name1);
  a2 = get_node_index(g, name2);
  if (a1>=0 && a2>=0){
    return g->arcs[a1][a2] > 0;
  }else{ 
    return -1;
  }
}

int* get_adjacency(Adjacency_Matrix* g, char* name) {
  int v;
  v = get_node_index(g, name);
  if (v>=0){
    int* adjacency = (int*) malloc(sizeof(int));
    adjacency[0] = 0; // Using the first position of the pointer to determine the size of the array
    
    int i;
    for (i = 0 ; i < g->vertex_count ; i++) {
      if (g->arcs[i][v] > 0) {
        adjacency[0]++;
        adjacency = (int*) realloc(adjacency, adjacency[0] * sizeof(int));
        adjacency[adjacency[0]] = i;
      }
    }

    return adjacency;
  }
}

void insert_vertex(Adjacency_Matrix* g, char* name) {
  if (g->arcs == NULL) {
    g->arcs = (int**) malloc(sizeof(int*));
    g->arcs[0] = (int*) malloc(sizeof(int));
    g->arcs[0][0] = 0;

    g->nodes = (Node**) malloc(sizeof(Node*));
    g->nodes[0] = init_node(name);
    g->vertex_count = 1;
  }else {
    int i;
    g->vertex_count += 1;
    g->arcs = (int**) realloc(g->arcs, g->vertex_count * sizeof(int*));
    
    for (i = 0 ; i < g->vertex_count - 1 ; i++)
      g->arcs[i] = (int*) realloc(g->arcs[i], g->vertex_count * sizeof(int)); // realloc the part of the matrix which were used before

    for ( ; i < g->vertex_count ; i++) 
      g->arcs[i] = (int*) malloc(g->vertex_count * sizeof(int)); // alloc the new part of the matrix

    for (i = 0 ; i < g->vertex_count ; i++) {
      g->arcs[i][g->vertex_count - 1] = 0;
      g->arcs[g->vertex_count - 1][i] = 0;
    }
    
    g->nodes = (Node**) realloc(g->nodes, g->vertex_count * sizeof(Node*));
    g->nodes[g->vertex_count-1] = init_node(name);
  }
}

//Loss of memory
void remove_vertex(Adjacency_Matrix* g, char* name) {
  int v;
  v = get_node_index(g, name);
  if (v >=0){
    int i, j;

    for (i = 0 ; i < g->vertex_count - 1 ; i++)
      for (j = v ; j < g->vertex_count ; j++) {
        g->arcs[i][j] = g->arcs[i][j + 1];
      }

    for (i = v ; i < g->vertex_count - 1; i++){
      for (j = 0 ; j < g->vertex_count ; j++){
        g->arcs[i][j] = g->arcs[i + 1][j];
      }
    }
    
    for (i = v; i < g->vertex_count - 1; i++){
      g->nodes[i] = g->nodes[i+1];
    }

    free_node(g->nodes[g->vertex_count - 1]);


    g->vertex_count--;

    g->arcs = (int**) realloc(g->arcs, g->vertex_count * sizeof(int*));

    for (i = 0 ; i < g->vertex_count ; i++){
      g->arcs[i] = (int*) realloc(g->arcs[i], g->vertex_count * sizeof(int));
    }

    g->nodes = (Node**) realloc(g->nodes, g->vertex_count * sizeof(Node*));
  }
}

void print_graph(Adjacency_Matrix* g) {
  int i, j;

  for (i = 0 ; i < g->vertex_count ; i++) {
    for (j = 0 ; j < g->vertex_count ; j++) {
      printf("[%d]", g->arcs[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (i = 0 ; i < g->vertex_count ; i++){
    printf("[%d, %s] ", i, g->nodes[i]->name);
  }
}

void print_adjacency(int* a) {
  int i;

  for (i = 1 ; i <= a[0] ; i++)
    printf("[%d]", a[i]);

  printf("\n");
}

Node* init_node(char* name){
  Node* node;
  node = (Node*) malloc(sizeof(Node));

  node->tsa = init_tsa(name);
  node->name = (char*) malloc(strlen(name) * sizeof(char));
  strcpy(node->name, name);
  return node;
}

void free_node(Node* node){
  free_tsa(node->tsa);
  free(node->name);
  free(node);
}

char* get_node_name(Node* node){
  return node->name;
}