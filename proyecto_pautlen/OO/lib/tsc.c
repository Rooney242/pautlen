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

/*Realiza las tareas de meter en la tabla hash del main los datos de la clase. Importante primero abrir la clase*/
int abrirAmbitoClase(tsc* t, char* id_clase, int tamanio){
	int tipo;
	tipo = -get_node_index(t->grafo, id_clase);
	return open_scope_class(t->main, id_clase, tamanio, tipo);
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
	
	elem = init_tsa_elem();
	if(!elem) return ERROR;

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
	if(!strcmp(scope, TSA_MAIN)) return t->main;
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

/*Dado un id y el ambito desde el que se quiere acceder a el se aplica si se tiene acceso a dicho elemento.
	El elemento encontrado se devuelve en elem*/
int aplicarAccesos(tsc* t, char* id, char* ambito_id, char* ambito_actual, tsa_elem** elem){
	tsa* table;
	char* real_id;
	char** parents_names;
	int acceso, num_parents, i;
	*elem = NULL;

	if(!t || !id ||!ambito_id || !ambito_actual) return ERROR;
	table = _get_tsa_from_scope(t, ambito_id);
	if(!table) return ERROR;

	
	/*Primero sacamos los permisos del simbolo antes de ver en que caso nos encontramos*/
	/*Hay que distinguir del caso de estar buscando una clase en el main, ya que estas NO llevan prefijo*/
	if(!strcmp(table->ambito, TSA_MAIN)){/*Primero buscamos sin prefijo por si es una clase*/
		*elem = ppal_get(table, id);
		if(!(*elem)){/*Si no pues buscamos a ver si no es una clase*/
			real_id = _concat_prefix(table->ambito, id);
			*elem = ppal_get(table, real_id);
			if(!(*elem)) return ERROR;
			acceso = (*elem)->tipo_acceso;
		}
	}else{
		real_id = _concat_prefix(table->ambito, id);
		*elem = ppal_get(table, real_id);
		if(!(*elem)) return ERROR;
		acceso = (*elem)->tipo_acceso;
	}

	/*Caso en el que estemos buscando desde el main, solo no se puede si es hidden*/
	if(!strcmp(ambito_actual, TSA_MAIN)){
		if(acceso == HIDDEN) return FALSE;
		return TRUE;
	}else{/*Caso de no estar en el main*/
		/*Si estoy en la misma clase donde se declaro puedo acceder seguro*/
		if(!strcmp(ambito_actual, ambito_id)) return TRUE;
		if(acceso == HIDDEN){/*Si es hidden solo se puede acceder desde la clase que se declaro*/
			return FALSE;
		}else if(acceso == SECRET){/*Si es secreto se puede si soy hijo de esa clase*/
			num_parents = get_parents_names(t->grafo, parents_names, ambito_actual);
			for (i=0; i<num_parents; i++){
				if(!strcmp(parents_names[i], ambito_actual)) return TRUE;
			}
			return FALSE;
		}
		/*Si es exposed o ninguno se puede acceder siempre*/
		return TRUE;
	}

}

/*Dado un id y un ambito devuelve si se puede llegar a conocer la identidad de ese id desde el ambito pasado.
	Devuelve el ambito donde se ha encontrado dicho simbolo o NULL en caso de que no se halla encontrado.
	La tsa donde se encuentra el simbolo se devuelve en table y el elemento de la tsa en elem.*/
int buscarIdEnJerarquiaDesdeAmbito(tsc* t, char* id, char* id_ambito, tsa** table, tsa_elem** elem){
	int num_parents, i;
	Node ** parents = NULL;
	char* real_id;
	*table = NULL;
	*elem = NULL;
	if(!t || !id || !id_ambito) return ERROR;
	/*En el caso de que estemos dentro del ambito de una funcion buscamos en el
		(en realidad por comodidad no miramos si estamos en una funcion, si no estamos la tabla hash auxiliar estara
		vacia y no hay posibilidad de encontrar nada)*/

	*table = _get_tsa_from_scope(t, id_ambito);
	if(!table) return ERROR;

	/*Miro si esta en el ambito de la posible funcion o de la clase*/
	real_id = _concat_prefix(id_ambito, id);	
	*elem = met_get(*table, real_id);
	free(real_id);
	if(*elem) return TRUE;

	real_id = _concat_prefix((*table)->ambito, id);	
	*elem = ppal_get(*table, real_id);
	free(real_id);
	if(*elem) return TRUE;

	/*Llegados aqui el simbolo no esta en el ambito en el que esta siendo llamado, nos queda mirar en la jerarquia*/
	num_parents = get_parents(t->grafo, parents, (*table)->ambito);
	/*Buscamos en todos sus padres en orden inverso para asi llegar antes a los padres mas directos*/
	for (i=num_parents-1; i>=0; i--){
		real_id = _concat_prefix(parents[i]->tsa->ambito, id);
		*elem = ppal_get(parents[i]->tsa, real_id);
		free(real_id);
		if(*elem){
			*table = parents[i]->tsa;
			return TRUE;
		}
	}

	/*Si no esta en su ambito o en la jerarquia de herencia de ese ambito solo puede estar en el main*/
	real_id = _concat_prefix(t->main->ambito, id);
	*elem = ppal_get(t->main, real_id);
	free(real_id);
	if(*elem){
		*table = t->main;
		return TRUE;
	}


	/*Llegados a este punto hemos mirado en todos los posibles sitios donde podria estar el id y no esta, no se puede llegar*/
	if(parents) free(parents);
	*table = NULL;
	return FALSE;

}

/*Dado un id sin cualificar y el ambito desde el que se quiere acceder devuelve true si se puede llegar a ese id
	y se tiene permiso para ello. Se devuelve la tsa encontreda y el elemento encontrado*/
int buscarIdNoCualificado(tsc* t, char* nombre_id, char* nombre_ambito_desde, tsa** tsa_encontrada, tsa_elem** elem){
	int ret, i;
	char * real_id;
	*tsa_encontrada = NULL;
	*elem = NULL;
	if(!t || !nombre_id || !nombre_ambito_desde) return ERROR;

	/*Miramos si podemos llegar a la clase del simbolo desde donde estamos*/
	if(strcmp(nombre_ambito_desde, TSA_MAIN)){
		ret = buscarIdEnJerarquiaDesdeAmbito(t, nombre_id, nombre_ambito_desde, tsa_encontrada, elem);
		if(ret == TRUE){/*Si se puede llegar miramos los accesos*/
			return aplicarAccesos(t, nombre_id, (*tsa_encontrada)->ambito, nombre_ambito_desde, elem);
		}else{
			return ret;
		}
	}else{/*Si estamos en el main buscamos en todas las tsa*/
		/*Buscamos en el main*/
		real_id = _concat_prefix(t->main->ambito, nombre_id);
		*elem = ppal_get(t->main, real_id);
		free(real_id);
		if(*elem){
			*tsa_encontrada = t->main;
			return aplicarAccesos(t, nombre_id, (*tsa_encontrada)->ambito, nombre_ambito_desde, elem);
		}
		/*Si no esta buscamos en el resto de tsa*/
		for(i=0; i<t->grafo->vertex_count; i++){
			real_id = _concat_prefix(t->grafo->nodes[i]->tsa->ambito, nombre_id);
			*elem = ppal_get(t->grafo->nodes[i]->tsa, real_id);
			free(real_id);
			if(*elem){
				*tsa_encontrada = t->grafo->nodes[i]->tsa;
				return aplicarAccesos(t, nombre_id, (*tsa_encontrada)->ambito, nombre_ambito_desde, elem);
			}
		}
		return FALSE;
	}
}

/*Esta funcion busca si el id cualificado por una clase es accesible desde dicha clase y se tiene permiso*/
int buscarIdCualificadoClase(	tsc *t, char * nombre_clase_cualifica,
						char * nombre_id, char * nombre_ambito_desde,
						tsa ** ambito_encontrado,
						tsa_elem ** elem){
	int i, ret;
	*ambito_encontrado = NULL;
	*elem = NULL;
	if(!t || !nombre_clase_cualifica || !nombre_id || !nombre_ambito_desde) return ERROR;

	/*Primero buscamos si la clase que cualifica existe*/
	*ambito_encontrado = _get_tsa_from_scope(t, nombre_clase_cualifica);
	if(!(*ambito_encontrado)) return ERROR;/*La clase que cualifica no existe*/

	/*Si existe la clase que cualifica miramos si se puede llegar a ese simbolo desde ella en su jerarquia*/
	ret = buscarIdEnJerarquiaDesdeAmbito(t, nombre_id, nombre_clase_cualifica, ambito_encontrado, elem);
	if(ret == TRUE){/*Aplicamos accesos desde la clase en la que nos encontramos*/
		return aplicarAccesos(t, nombre_id, (*ambito_encontrado)->ambito, nombre_ambito_desde, elem);
	}else{
		return ret;
	}

}

/*Esta funcion busca si la instancia de la clase que cualifica el simbolo es accesible y se tienen permisos*/
int buscarIdCualificadoInstancia(tsc *t, char * nombre_instancia_cualifica,
						char * nombre_id, char * nombre_ambito_desde,
						tsa ** ambito_encontrado, tsa_elem ** elem){
	int ret;
	*ambito_encontrado = NULL;
	*elem = NULL;
	if(!t || !nombre_instancia_cualifica || !nombre_id || !nombre_ambito_desde) return ERROR;

	/*Buscamos la instancia como un id no cualificado desde el ambito en el que estamos*/
	ret = buscarIdNoCualificado(t, nombre_instancia_cualifica, nombre_ambito_desde, ambito_encontrado, elem);
	if(ret == TRUE){
		if((*elem)->categoria != CLASE) return FALSE;/*Comprobamos que se declaro como clase*/
		/*Miramos si esa instancia tiene acceso al simbolo que queremos cualificar. 
			Para hallar el nombre de la clase de la instancia buscamos en los nodos del grafo*/
		printf("%d\n", -(*elem)->tipo);
		ret = buscarIdEnJerarquiaDesdeAmbito(t, nombre_id, t->grafo->nodes[-(*elem)->tipo]->tsa->ambito, ambito_encontrado, elem);
		if (ret == TRUE){
			return  aplicarAccesos(t, nombre_id, (*ambito_encontrado)->ambito, t->grafo->nodes[-(*elem)->tipo]->tsa->ambito, elem);
		}
	}
	return ret;
}

int buscarParaDeclararMiembroClase(	tsc *t, char * nombre_ambito_desde, char * nombre_miembro,
							tsa * ambito_encontrado, tsa_elem ** e){
	return ERROR;
}




