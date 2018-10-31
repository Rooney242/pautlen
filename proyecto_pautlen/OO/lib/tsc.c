#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "macros.h"
#include "graph.h"
#include "tsa.h"
#include "tsc.h"


tsc* init_tsc(char * nombre){
	tsc* t;
	if(!nombre) return NULL;
	t = (tsc*) malloc(sizeof(tsc));
	if (!t) return NULL;

	t->nombre = (char*) malloc(sizeof(char)*(strlen(nombre)+1));
	if(!t->nombre){
		free_tsc(t);
		return NULL;
	}

	t->main = init_tsa(TSA_MAIN);
	if(!t->main){
		free_tsc(t);
		return NULL;
	}

	t->grafo = init_graph(t->grafo);
	if(!t->grafo){
		free_tsc(t);
		return NULL;
	}

	return t;
}

int free_tsc(tsc* t){
	if(!t) return ERROR;
	if(t->nombre) free(t->nombre);
	if(t->main) free_tsa(t->main);
	if(t->grafo) free_graph(t->grafo);
	return OK;
}

int abrirClase(tsc* t, char* id_clase){
	if(!t || !id_clase) return ERROR;
	return insert_class(t->grafo, id_clase, NULL, 0);
}

/*Aqui viene el movidote de que decidir con las herencias, se toca en insert_class del grafo*/
int abrirClaseHereda(tsc* t, char* id_clase, ...){
	if(!t || !id_clase) return ERROR;

	va_list names;
	char ** parents;
	char* name;
	int i, num, ret;

	va_start(names, id_clase);
	num = 0;
	va_arg(names, char*);
	while(id_clase != NULL){
		va_arg(names, char*);
		num++;
	}
	va_end(names);

	parents = (char**) malloc(num*sizeof(char*));
	if(!parents) return ERROR;
	name = va_arg(names, char*);
	for (i = 0; i < num; i++){
		parents[i] = va_arg(names, char*);
	}
	va_end(names);

	ret = insert_class(t->grafo, name, parents, num);
	free(parents);
	return ret;
}

int cerrarClase(tsc* t, char* id_clase, int num_atributos_clase, int num_atributos_instancia,
				int num_metodos_sobreescribibles, int num_metodos_no_sobreescribibles){
	if(!t || !id_clase) return ERROR;
	int index;
	index = get_node_index(t->grafo, id_clase);
	if(index == ERROR) return ERROR;
	t->grafo->nodes[index]->num_atributos_clase = num_atributos_clase;
	t->grafo->nodes[index]->num_atributos_instancia = num_atributos_instancia;
	t->grafo->nodes[index]->num_metodos_sobreescribibles = num_metodos_sobreescribibles;
	t->grafo->nodes[index]->num_metodos_no_sobreescribibles = num_metodos_no_sobreescribibles;
	return OK;
}

void graph_enrouteParentsLastNode(tsc * g){
	//No deberiamos de tener que hacer nada por como esta hecho nuestro grafo
	return;
}

int close_tsc(tsc* t){
	return OK;
}	
