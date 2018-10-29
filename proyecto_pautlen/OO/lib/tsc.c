#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include "graph.h"
#include "tsa.h"
#include "tsc.h"


int iniciarTablaSimbolosClases(tablaSimbolosClases* t, char * nombre){
	if(!nombre) return ERROR;
	t = (tablaSimbolosClases*) malloc(sizeof(tablaSimbolosClases));
	if (!t) return ERROR;

	t->nombre = (char*) malloc(sizeof(char)*(strlen(nombre)+1));
	if(!t->nombre){
		liberaTablaSimbolosClases(t);
		return ERROR;
	}

	t->main = init_tsa(TSA_MAIN);
	if(!t->main){
		liberaTablaSimbolosClases(t);
		return ERROR;
	}

	t->grafo = init_graph(t->grafo);
	if(!t->grafo){
		liberaTablaSimbolosClases(t);
		return ERROR;
	}

	reuturn OK;
}

int liberaTablaSimbolosClases(tablaSimbolosClases* t){
	if(!t) return ERROR;
	if(t->nombre) free(t->nombre);
	if(t->main) free_tsa(t->main);
	if(t->grafo) free_graph(t->grafo);
	return OK;
}

int abrirClase(tablaSimbolosClases* t, char* id_clase){
	if(!t || !id_clase) return ERROR;
	return insert_class(t->grafo, id_clase, NULL, 0);
}

/*Aqui viene el movidote de que decidir con las herencias, se toca en insert_class del grafo*/
int abrirClaseHereda(tablaSimbolosClases* t, char* id_clase, ...){
	if(!t || !id_clase) return ERROR;

	va_list names;
	char ** parents;
	char* name;
	int i, num, ret;

	va_start(valist, id_clase);
	num = 0;
	va_arg(valist, char*);
	while(id_clase != NULL){
		va_arg(valist, char*);
		num++;
	}
	va_end(valist);

	parents = (char**) malloc(num*sizeof(char*));
	if(!parents) return ERROR
	name = va_arg(id_clase, char*);
	for (i = 0; i < num; i++){
		parents[i] = va_arg(id_clase, char*);
	}
	va_end(valist);

	ret = insert_class(t->grafo, name, parents, num);
	free(parents);
	return ret;
}

int cerrarClase(tablaSimbolosClases* t, char* id_clase, int num_atributos_clase, int num_atributos_instancia,
				int num_metodos_sobreescribibles, int num_metodos_no_sobreescribibles);

void graph_enrouteParentsLastNode(tablaSimbolosClases * g);	
