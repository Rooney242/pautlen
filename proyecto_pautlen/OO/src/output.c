#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "macros.h"
#include "tsa.h"
#include "tsc.h"
#include "hash_table.h"
#include "output.h"


int	print_caso(FILE* pf, int caso, int es_declarar, char* ambito_desde, tsa* ambito_encontrado, tsa_elem* elem){
	if(!pf) return ERROR;

	if(caso){
		fprintf(pf, "--> Simbolo %s encontrado en %s. ", elem->id, ambito_encontrado->ambito);
		if(es_declarar){
			fprintf(pf, "No se puede declarar.\n");
		}else{
			fprintf(pf, "Se puede acceder al simbolo.\n");
		}
	}else{
		fprintf(pf, "--> Simbolo no encontrado. ");
		if(es_declarar){
			fprintf(pf, "Se puede declarar.\n");
		}else{
			fprintf(pf, "No se puede acceder al simbolo.\n");
		}
	}
}

int print_hash_table_from_class(FILE* pf, tsc* p_tsc, char* id_clase){
	int i;
	char ** simbolos;
	tsa* t;
	if(!pf || !id_clase) return ERROR;

	t = _get_tsa_from_scope(p_tsc, id_clase);

	simbolos = (char**) malloc(sizeof(char*)*t->ppal->e_num);
	ht_list_keys(t->ppal, simbolos, t->ppal->e_num);


	fprintf(pf, "=================== %s =================\n", t->ambito);
	for(i=0; i<t->ppal->e_num; i++){
		if(print_tsa_elem(t->ppal, simbolos[i], pf) == ERROR){
			free(simbolos);
			return ERROR;
		}
	}
	free(simbolos);
	return OK;
}

int print_hash_table_from_met(FILE* pf, tsc* p_tsc, char* id_clase, char* metodo){
	int i;
	char ** simbolos;
	tsa* t;
	if(!pf || !id_clase || !metodo) return ERROR;

	t = _get_tsa_from_scope(p_tsc, metodo);

	simbolos = (char**) malloc(sizeof(char*)*t->met->e_num);
	ht_list_keys(t->met, simbolos, t->met->e_num);

	fprintf(pf, "=================== %s =================\n", metodo);
	for(i=0; i<t->met->e_num; i++){
		if(print_tsa_elem(t->met, simbolos[i], pf) == ERROR){
			free(simbolos);
			return ERROR;
		}
	}
	free(simbolos);
	return print_hash_table_from_class(pf, p_tsc, id_clase);
}

int print_command(FILE* pf, char* command, int salto_de_linea){
	if(!pf || !command) return ERROR;
	if(salto_de_linea == TRUE){
		fprintf(pf, "%s\n", command);
	}else{
		fprintf(pf, "%s ", command);
	}
}
