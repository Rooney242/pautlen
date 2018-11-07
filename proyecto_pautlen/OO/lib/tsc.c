#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "macros.h"
#include "graph.h"
#include "tsa.h"
#include "tsc.h"
#include "hash_table.h"

char* _concat_prefix(char* prefix, char* symbol){
	char*  full_symbol;
	full_symbol = (char*)malloc(sizeof(char)*(strlen(prefix)+strlen(symbol)+2));
	if(!full_symbol) return NULL;
	strcpy(full_symbol, prefix);
	full_symbol = strcat(full_symbol, "_");
	full_symbol = strcat(full_symbol, symbol);

	return full_symbol;

}

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
	int ret;
	char* pref_simbolo;
	clase = get_class(t, id_clase);
	if(!t || !clase) return ERROR;

	pref_simbolo = _concat_prefix(id_clase, id_ambito);

	ret = open_scope_met(clase, pref_simbolo, categoria, acceso_metodo, tipo_metodo, posicion_metodo_sobreescribible, tamanio);
	free(pref_simbolo);
	return ret;
}

int cerrarAmbitoEnClase(tsc* t, char* id_clase, char* id_ambito){
	tsa* clase;
	int ret;
	char* pref_simbolo;
	clase = get_class(t, id_clase);
	if(!t || !clase) return ERROR;

	pref_simbolo = _concat_prefix(id_clase, id_ambito);

	ret = close_scope_met(clase, pref_simbolo);
	free(pref_simbolo);
	return ret;

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
	char* pref_simbolo;
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

	pref_simbolo = _concat_prefix(id_clase, simbolo);

	if(!ppal_put(clase, pref_simbolo, elem)) return ERROR;
	free(pref_simbolo);
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
	char* pref_simbolo;

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

	pref_simbolo = _concat_prefix(TSA_MAIN, simbolo);

	if(!ppal_put(t->main, pref_simbolo, elem)) return ERROR;
	free(pref_simbolo);
	return OK;

}

int insertarSimboloEnAmbitoEnClase(tsc* t, char* id_clase, char* id_ambito, char* simbolo, int categoria,
	int tipo,	int estructura,
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
	char* pref_simbolo;
	clase = get_class(t, id_clase);	
	if(!t || !clase) return ERROR;
	
	elem = ppal_get(clase, id_ambito);
	if(!elem) return ERROR;
	if(elem->simbolo_cerrado == TRUE) return ERROR;

	elem = init_tsa_elem();
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

	pref_simbolo = _concat_prefix(id_ambito, simbolo);

	if(!met_put(clase, pref_simbolo, elem)) return ERROR;
	free(pref_simbolo);
	return OK;

}

/****FUNCIONES DE BUSQUEDA***********/
/*Encuentra la tsa de la clase en funcion de un ambito, ya sea el de la clase o el de una funcion de la clase*/
tsa* _get_tsa_from_scope(tsc* t, char* scope){
	tsa* table;
	tsa_elem* elem;
	int i;
	char* function;
	if(!t || !scope) return NULL;
	table = get_node_tsa(t->grafo, scope);
	if(!table){/*Caso de estar en el ambito de una funcion o error, vemos todos los ambitos*/
		for(i=0; i<t->grafo->vertex_count || !elem; i++){
			function = _concat_prefix(t->grafo->nodes[i]->name, scope);
			table = t->grafo->nodes[i]->tsa;
			elem = ppal_get(table, function); 
			free(function);
		}
		if(!elem){/*Puede estar en el main*/
			table = t->main;
			elem = ppal_get(t->main, function);
		}
		if(!elem){/*error*/
			table = NULL;
		}
	}
	return table;
}

int buscarTablaSimbolosAmbitosConPrefijos(tsc* t, char* id, char* id_ambito){
	tsa* table;
	tsa_elem* elem = NULL;
	if(!t || !id || !id_ambito) return ERROR;
	/*En el caso de que estemos dentro del ambito de una funcion buscamos en el
		(en realidad por comodidad no miramos si estamos en una funcion, si no estamos la tabla hash auxiliar estara
		vacia y no hay posibilidad de encontrar nada)*/

	table = _get_tsa_from_scope(t, id_ambito);
	if(!table) return ERROR;

	/*Miro si esta en el ambito de la posible funcion o de la clase*/
	elem = met_get(table, id);
	if(elem) return OK;
	elem = ppal_get(table, id);
	if(elem) return OK;

	/*Nos queda mirar en la jerarquia*/


}
