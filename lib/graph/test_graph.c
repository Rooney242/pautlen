/*
 * =====================================================================================
 *
 *       Filename:  graph.c
 *
 *    Description:  Main program to run Adjacency_Matrix application
 *
 *        Version:  1.0
 *        Created:  17/04/2013 10:34:33
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
#include "graph.h"

#define INSERT_VERTEX 1
#define REMOVE_VERTEX 2
#define INSERT_ARC 3
#define REMOVE_ARC 4
#define VERTEX_ADJACENCY 5
#define TRANSPOSE_GRAPH 6
#define PRINT_GRAPH 7
#define EXIT 0

void menu() {
  system("clear");
  printf("Graph Theory\n");
  printf("[1] Insert Vertex\n");
  printf("[2] Remove Vertex\n");
  printf("[3] Insert Arc\n");
  printf("[4] Remove Arc\n");
  printf("[5] Get Vertex Adjacency\n");
  printf("[6] Transpose Graph (not functional)\n");
  printf("[7] Print Graph\n");
  printf("[0] Exit\n");
}

void pause() {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
  printf("Press enter to continue...");
  getchar();
}

int main(int argc, char* argv[]) {
  Adjacency_Matrix* g = (Adjacency_Matrix*) malloc(sizeof(Adjacency_Matrix));
  Adjacency_Matrix* tp;
  int* adjacency;
  init_graph(g);

  int option, v, a1, a2;
  char *name;

  do {
    menu();
    scanf("%d", &option);
    switch (option) {
      case INSERT_VERTEX:
        printf("Name of the vertex: ");
        scanf("%s", name);
        insert_vertex(g, name);
        break;
      case REMOVE_VERTEX:
        printf("Which vertex would you like to remove? ");
        scanf("%d", &v);
        remove_vertex(g, v);
        break;
      case INSERT_ARC:
        printf("First vertex: ");
        scanf("%d", &a1);
        printf("Second vertex: ");
        scanf("%d", &a2);
        insert_arc(g, a1, a2);
        break;
      case REMOVE_ARC:
        printf("First vertex: ");
        scanf("%d", &a1);
        printf("Second vertex: ");
        scanf("%d", &a2);
        remove_arc(g, a1, a2);
        break;
      case VERTEX_ADJACENCY:
        printf("Which vertex would you like to verify adjacency?");
        scanf("%d", &v);
        adjacency = get_adjacency(g, v);
        print_adjacency(adjacency);
        free(adjacency);
        pause();
        break;
      case TRANSPOSE_GRAPH:
        tp = transpose_graph(g);
        print_graph(tp);
        free(tp);
        pause();
        break;
      case PRINT_GRAPH: 
        print_graph(g);
        pause();
        break;
    }
  } while (option != EXIT);

  return 0;
}