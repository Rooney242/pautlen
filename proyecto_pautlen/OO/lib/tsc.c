#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "macros.h"
#include "graph.h"
#include "tsa.h"
#include "tsc.h"
#include "hash_table.h"


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
	free(t);
	return OK;
}

int close_tsc(tsc* t){
	return OK;
}	

tsa* get_class(tsc* t, char* id_clase){
	return get_node_tsa(t->grafo, id_clase);
}

/*Inserta una clase en el grafo*/
int abrirClase(tsc* t, char* id_clase){
	if(!t || !id_clase) return ERROR;
	return insert_class(t->grafo, id_clase, NULL, 0);
}

/*Inserta una clase que tiene relaciones de herencia en el grafo*/
/*Aqui viene el movidote de que decidir con las herencias, se toca en insert_class del grafo*/
int abrirClaseHereda(tsc* t, char* id_clase, ...){
	if(!t || !id_clase) return ERROR;

	va_list names;
	char ** parents;
	char* name;
	int i, num, ret;

	va_start(names, id_clase);
	num = 0;
	name = id_clase;
	id_clase = va_arg(names, char*);
	while(id_clase){
		if(num==0){
			parents = (char**) malloc(sizeof(char*));
			if(!parents) return ERROR;
		}else{
			parents = (char**) realloc(parents, (num+1)*sizeof(char*));
			if(!parents) return ERROR;
		}
		parents[num] = id_clase;
		num++;
		id_clase = va_arg(names, char*);
	}
	va_end(names);

	ret = insert_class(t->grafo, name, parents, num);
	if(parents) free(parents);
	return ret;
}

/*Realiza las tareas de meter en la tabla hash del main los datos de la clase*/
int abrirAmbitoClase(tsc* t, char* id_clase, int tamanio){
	return open_scope_class(t->main, id_clase, tamanio);
}

/*Cierra una lase actualizando sus datos*/
int cerrarClase(tsc* t, char* id_clase, int num_atributos_clase, int num_atributos_instancia,
				int num_metodos_sobreescribibles, int num_metodos_no_sobreescribibles){
	if(!t || !id_clase) return ERROR;

	tsa_elem* elem;
	elem = ppal_get(t->main, id_clase);
	if(!elem) return ERROR;
	elem->numero_atributos_clase = num_atributos_clase;
	elem->numero_atributos_instancia = num_atributos_instancia;
	elem->numero_metodos_sobreescribibles = num_metodos_sobreescribibles;
	elem->numero_metodos_no_sobreescribibles = num_metodos_no_sobreescribibles;
	if(elem->simbolo_cerrado == TRUE) return ERROR;
	elem->simbolo_cerrado = TRUE;
	return OK;
}

void graph_enrouteParentsLastNode(tsc * g){
	//No deberiamos de tener que hacer nada por como esta hecho nuestro grafo
	return;
}

int abrirAmbitoEnClase(tsc * t, char * id_clase, char* id_ambito, int categoria, int acceso_metodo, int tipo_metodo, int posicion_metodo_sobreescribible, 	int tamanio){
	tsa* clase;
	clase = get_class(t, id_clase);
	if(!t || !clase) return ERROR;

	return open_scope_met(clase, id_ambito, categoria, acceso_metodo, tipo_metodo, posicion_metodo_sobreescribible, tamanio);
}

int cerrarAmbitoEnClase(tsc* t, char* id_clase, char* id_ambito){
	tsa* clase;
	clase = get_class(t, id_clase);
	if(!t || !clase) return ERROR;

	return close_scope_met(clase, id_ambito);

}

int insertarSimboloEnClase(tsc* t, char* id_clase, char* simbolo, int categoria, int tipo,						int estructura,
	int direcciones,					int numero_parametros,
	int numero_variables_locales,		int posicion_variable_local,
	int posicion_parametro,			int dimension,
	int tamanio,					int filas,
	int columnas,					int capacidad,
	int numero_atributos_clase,			int numero_atributos_instancia,
	int numero_metodos_sobreescribibles,	int numero_metodos_no_sobreescribibles,
	int tipo_acceso,  				int tipo_miembro, 
	int posicion_atributo_instancia,		int posicion_metodo_sobreescribible,
	int num_acumulado_atributos_instancia,	int num_acumulado_metodos_sobreescritura,
	int posicion_acumulada_atributos_instancia,
	int posicion_acumulada_metodos_sobreescritura,
	int * tipo_args){

	tsa_elem* elem;
	tsa* clase;
	clase = get_class(t, id_clase);	
	if(!t || !clase) return ERROR;
	elem = init_tsa_elem();

	if(!elem) return ERROR;
	set_tsa_elem(elem, categoria, tipo,	estructura,
	direcciones,					 numero_parametros,
	numero_variables_locales,		posicion_variable_local,
	posicion_parametro,			dimension,
	tamanio,					filas,
	columnas,					capacidad,
	numero_atributos_clase,		numero_atributos_instancia,
	numero_metodos_sobreescribibles,	numero_metodos_no_sobreescribibles,
	tipo_acceso,  				tipo_miembro, 
	posicion_atributo_instancia,		posicion_metodo_sobreescribible,
	num_acumulado_atributos_instancia,	num_acumulado_metodos_sobreescritura,
	posicion_acumulada_atributos_instancia,
	posicion_acumulada_metodos_sobreescritura,
	tipo_args, TRUE);
	if(!ppal_put(clase, simbolo, elem)) return ERROR;
	return OK;

}

int insertarSimboloEnMain(tsc* t, char* simbolo, int categoria, int tipo,						int estructura,
	int direcciones,					int numero_parametros,
	int numero_variables_locales,		int posicion_variable_local,
	int posicion_parametro,			int dimension,
	int tamanio,					int filas,
	int columnas,					int capacidad,
	int numero_atributos_clase,			int numero_atributos_instancia,
	int numero_metodos_sobreescribibles,	int numero_metodos_no_sobreescribibles,
	int tipo_acceso,  				int tipo_miembro, 
	int posicion_atributo_instancia,		int posicion_metodo_sobreescribible,
	int num_acumulado_atributos_instancia,	int num_acumulado_metodos_sobreescritura,
	int posicion_acumulada_atributos_instancia,
	int posicion_acumulada_metodos_sobreescritura,
	int * tipo_args){

	tsa_elem* elem;
	tsa* clase;

	elem = init_tsa_elem();
	if(!elem) return ERROR;
	set_tsa_elem(elem, categoria, tipo,	estructura,
	direcciones,					 numero_parametros,
	numero_variables_locales,		posicion_variable_local,
	posicion_parametro,			dimension,
	tamanio,					filas,
	columnas,					capacidad,
	numero_atributos_clase,		numero_atributos_instancia,
	numero_metodos_sobreescribibles,	numero_metodos_no_sobreescribibles,
	tipo_acceso,  				tipo_miembro, 
	posicion_atributo_instancia,		posicion_metodo_sobreescribible,
	num_acumulado_atributos_instancia,	num_acumulado_metodos_sobreescritura,
	posicion_acumulada_atributos_instancia,
	posicion_acumulada_metodos_sobreescritura,
	tipo_args, TRUE);
	if(!ppal_put(t->main, simbolo, elem)) return ERROR;
	return OK;

}