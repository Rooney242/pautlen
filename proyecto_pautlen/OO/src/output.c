#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "macros.h"
#include "tsa.h"
#include "tsc.h"
#include "hash_table.h"
#include "output.h"


int	print_caso(FILE* pf, int caso, char* ambito_desde, tsa* ambito_encontrado, tsa_elem* elem){
	if(!pf) return ERROR;

	switch(caso){
		case ERROR:
			fprintf(pf, "CASO 20 -- OK\n"
				"-->Elemento %s en buscarIdNoCualificado desde (%s) ENCONTRADO en main.\n", elem->id, ambito_desde);
			break;
		case CASO_21:
			fprintf(pf, "CASO 21 -- ERR\n"
				"-->FALLO en la busqueda del id %s en buscarIdNoCualificado desde %s \n", elem->id, ambito_desde);
			break;
		case CASO_22:
			fprintf(pf, "CASO 22 -- OK\n"
				"-->Elemento %s en buscarIdNoCualificado desde %s ENCONTRADO en main\n", elem->id, ambito_desde);
			break;
		case CASO_23:
			fprintf(pf, "CASO 23 -- ERR\n"
				"-->FALLO en la busqueda del id %s en buscarIdNoCualificado desde %s\n", elem->id, ambito_desde);
			break;
		case CASO_24:
			fprintf(pf, "CASO 24 -- OK\n"
				"-->Elemento %s en buscarIdNoCualificado desde %s ENCONTRADO en %s\n", elem->id, ambito_desde, ambito_encontrado->ambito);
			break;
		case CASO_25:
			fprintf(pf, "CASO 25 -- OK\n"
				"-->Elemento %s en buscarIdNoCualificado desde %s ENCONTRADO en main\n", elem->id, ambito_desde);
			break; 
		case CASO_26:
			fprintf(pf, "CASO 26 -- ERR\n"
				"-->FALLO en la busqueda del id %s en buscarIdNoCualificado desde %s\n",elem->id, ambito_desde);
			break;

		case CASO_49:
			fprintf(pf, "CASO 49\n"
				"BUSCAR PARA DECLARAR MIEMBRO CLASE: CASO %s NO ESTA",elem->id);
			break; 
		case CASO_50:
			fprintf(pf, "CASO 50\n"
				"BUSCAR PARA DECLARAR MIEMBRO CLASE: OK %s YA ESTA",elem->id);
			break;



		case CASO_51:
			fprintf(pf, "CASO 51\n"
				"BUSCAR PARA DECLARAR MIEMBRO INSTANCIA: OK %s NO SE PUEDE DECLARAR",elem->id);
			break; 
		case CASO_52:
			fprintf(pf, "CASO 52\n"
				"BUSCAR PARA DECLARAR MIEMBRO INSTANCIA: NO SE HACERLO HULIO");
	//DECLARADO EN AA ES ATRIBUTO DE INSTANCIA ACCESIBLE CON ACCESO secret NO
	//EXISTE AA_ha1 (EN AA) PERO NO ES ACCESIBLE PORQUE ES HIDDEN SE PUEDE DECLARAR	
	//EXISTE EN LA JERARQUIA (AA) ES ACCESIBLE (SECRET) Y ES SOBREESCRIBIBLE: SE ESTÁ SOBREESCRIBIENDO Y EL OFFSET ACUMULADO PAR LA TABLA DE MÉTODOS ES EL MISMO QUE EL DE AA_mA1@1
	//CASO (AA_mA2) mA2 EXISTE EN AA PERO NO ES ACCESIBLE (HIDDEN) SE PEUDE DECLARAR COMO UN MÉTODO SOBRERESCRBIBLE NUVO CON SU PROPIO OFFSET ACUMULADO PARA LA TABLA DE METODOS
			break; 
		case CASO_53:
			fprintf(pf, "CASO 53\n"
				"BUSCAR PARA DECLARAR MIEMBRO INSTANCIA: CASO %s SE PUEDE DECLARAR",elem->id);
			break;
		default:
			fprintf(pf, "ME HA LLEGADO ALGO QUE NO SE LO QUE ES HULIO.\n");
			break;
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

int print_command(FILE* pf, char* command){
	if(!pf || !command) return ERROR;
	fprintf(pf, "%s\n", command);
}
