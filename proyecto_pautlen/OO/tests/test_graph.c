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
#define INSERT_CLASS 4
#define REMOVE_ARC 5
#define VERTEX_ADJACENCY 6
#define TRANSPOSE_GRAPH 7
#define PRINT_GRAPH 8
#define EXIT 0

void menu() {
  system("clear");
  printf("Graph Theory\n");
  printf("[1] Insert Vertex\n");
  printf("[2] Remove Vertex\n");
  printf("[3] Insert Arc\n");
  printf("[4] Insert Class\n");
  printf("[5] Remove Arc\n");
  printf("[6] Get Vertex Adjacency\n");
  printf("[7] Transpose Graph (not functional)\n");
  printf("[8] Print Graph\n");
  printf("[0] Exit\n");
}

void pause() {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
  printf("Press enter to continue...");
  getchar();
}

int main(int argc, char* argv[]) {
  Adjacency_Matrix* g;
  Adjacency_Matrix* tp;
  int* adjacency;
  g = init_graph();

  int option, v, a1, a2;
  char name1[50], name2[50];
  char **parents;
  parents = NULL;
  int num, i;

  do {
    menu();
    scanf("%d", &option);
    switch (option) {
      case INSERT_VERTEX:
        printf("Name of the vertex: ");
        scanf("%s", name1);
        insert_vertex(g, name1);
        break;
      case REMOVE_VERTEX:
        printf("Which vertex would you like to remove? ");
        scanf("%s", name1);
        remove_vertex(g, name1);
        break;
      case INSERT_ARC:
        printf("First vertex: ");
        scanf("%s", name1);
        printf("Second vertex: ");
        scanf("%s", name2);
        insert_arc(g, name1, name2);
        break;
      case INSERT_CLASS:
        num=0;
        printf("Class name: ");
        scanf("%s", name1);
        printf("Number of parents: ");
        scanf("%d", &num);
        if(num>0){
          parents = (char**) malloc(num+sizeof(char*));
          name2[0]='\0';
          for (i=0; i<num; i++){
            printf("Parent name(%d): ", i);
            scanf("%s", name2);
            parents[i] = (char*) malloc((strlen(name2)+1)*sizeof(char));
            strcpy(parents[i], name2);
            name2[0]='\0';
          }
        }
        insert_class(g, name1, parents, num);
        if(num>0){
          for (i=0; i<num; i++){
            free(parents[i]);
          }
          free(parents);
        }
        parents = NULL;
        break;
      case REMOVE_ARC:
        printf("First vertex: ");
        scanf("%s", name1);
        printf("Second vertex: ");
        scanf("%s", name2);
        remove_arc(g, name1, name2);
        break;
      case VERTEX_ADJACENCY:
        printf("Which vertex would you like to verify adjacency?");
        scanf("%s", name1);
        adjacency = get_adjacency(g, name1);
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

  free_graph(g);

  return 0;
}