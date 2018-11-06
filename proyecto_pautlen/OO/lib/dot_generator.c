#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include "tsc.h"
#include "dot_generator.h"
#include "graph.h"


int generar_dot(tsc* tabla, char* file_name){
	if(!tabla) return ERROR;
	FILE * pf;
	int i, k, num_parents, num_clases;
	char* name;
	char ** parents_names;
	if (!file_name){
		pf = fopen(strcat(file_name, ".dot"),"w");
	}else{
		pf = fopen(strcat(OUTPUT_FILE, ".dot"), "w");
	}

	fprintf(pf, "digraph grafo_clases  { rankdir=BT; edge [arrowhead = empty]\n");

	num_clases = tabla->grafo->vertex_count;
	for(i=0; i<num_clases; i++){
		name = tabla->grafo->nodes[i]->name;
		fprintf(pf, "\t%s [label=\"{%s|%s\\l", name, name, name);
		for(k=0; k<1; k++){//bucle por los simbolos del ambito TODO
			fprintf(pf, "TODO\\l");
		}
		fprintf(pf, "}\"][shape=record];\n");

		num_parents = get_parents_names(tabla->grafo, parents_names, name);
		for(k=0; k<num_parents; k++){
			fprintf(pf, "\t%s -> %s\n", name, parents_names[k]);
		}
		free(parents_names);
	}

	fprintf(pf, "\tedge [arrowhead = normal]\n");

	for(i=0; i<num_clases; i++){
		name = tabla->grafo->nodes[i]->name;
		fprintf(pf, "\t%sN%d [label=\"%s\"][shape=oval];\n", name, i, name);
		if (i>1){
			fprintf(pf, "\t%sN%d -> %sN%d\n", tabla->grafo->nodes[i-1]->name, i-1, name, i);
		}
	}

	fprintf(pf, "}");
	fclose(pf);
}